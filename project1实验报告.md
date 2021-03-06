# 编译技术 Project1

小组ID：30

组员: 张家硕、曹浩威、游凌云

## 构建

该项目在 Ubuntu 18.04 (x64) gcc 7.5.0 环境下通过编译

```
mkdir build
cd build
cmake ..
make -j 12
```

## 实现思路

首先读取JSON文件，获取kernel字符串，由词法、文法解析工具生成抽象文法树，遍历树上节点生成IRNode树，之后遍历IRNode树，收集必要信息，添加索引范围检查，最后使用Printer生成C++代码

## 实现方法

整个翻译流程分为以下几步

### I. JSON to Kernel

该部分遍历case1-case10以及example，读取各个存在的case的JSON文件，调用jsoncpp提供的功能提取出相关信息，并将kernel字符串写入一个临时文件中供后续步骤使用

### II. Kernel To IR

这一部分的主要工作为将输入的kernel字符串初步转换为IR的抽象语法树。具体来说，是通过对kernel字符串进行词法与语法分析，获得kernel的抽象语法树，在遍历该抽象语法树的过程中生成调用各类IR Node的make函数，构建IR的抽象语法树。本部分只构建了IR中Stmt及之下的节点。LoopNest节点和Kernel节点的构建，以及Dom节点的范围推断，在后续部分的IRVisitor与IRMutator中完成。

本部分中使用antlr自动生成kernel的抽象语法树。antlr是一个较为成熟的parser生成工具，其采用自上而下(LL(K))的递归下降分析方法。通过编写kernel.g4，可以指导antlr生成kernel parser。在编写kernel.g4时，按照相应的规则，可以定义语法、词法规则，指定语法与词法规则的优先级和结合顺序等，进而正确地完成parser的构建。

本部分核心代码为Kernel2IRVisitor.h, 需要配合antlr的runtime库、kernel parser以及IR.h一起使用。本部分采用visitor开发模式，通过遍历kernel的各个节点来完成IR语法树的构建，将kernel输入时的string转换为IR中的vector\<Stmt\>。其SDD大致为:

```
P ::= P S {P.stmtList.add(S.stmt))
			| S {P.stmtList.add(S.stmt)}
S ::= LHS = RHS {S.stmt=Move::make(LHS.expr,RHS.expr,MoveType::MemToMem)}
LHS ::= TRef {LHS.expr=TRef.var}
RHS ::= RHS + RHS {RHS.expr=Binary::Make(data_type,BinaryOpType::Add,RHS.expr,RHS.expr)}
        | RHS * RHS...
        | RHS - RHS...
        | RHS / RHS...
        | RHS % RHS...
        | RHS // RHS...
        | (RHS){RHS.expr=RHS.expr}
        | TRef {RHS.expr=TRef.var}
        | SRef {RHS.expr=SRef.var}
        | Const {RHS.expr=Const.value}
TRef ::= Id < CList > [ AList ] {TRef.var=Var::make(data_type,ID.toString,CList.list,Alist.list)}
SRef ::= Id < CList > {SRef.var=Var::make(data_type,ID.toString,CList.list,Alist.list)}
CList ::= CList , IntV {Clist.list.add{IntV.value}}
					| IntV {Clist.list.add{IntV.value}}
AList ::= AList , IdExpr {Alist.list.add(IdExpr)} 
					| IdExpr {Alist.list.add(IdExpr)}
IdExpr ::= Id {Dom::make;Index::make} 
					 | IdExpr + IdExpr {IdExpr=Binary::make(data_type,BinaryOpType::Add,IdExpr.expr,IdExpr.expr)}
					 | IdExpr + IntV ...
					 | IdExpr * IntV ...
					 | IdExpr // IntV ...
					 | IdExpr % IntV ...
					 | (IdExpr) ...
Const ::= FloatV {Const.value=FloatV.value}
					| IntV {Const.value=IntV.value}
```

### III. IR visitor

上一步已经完成了从kernel字符串到IR中Stmt这一转换（显然这一Stmt是Move类型的）。但并未推导Stmt中Var的Index的范围，也并未给Stmt加外层的循环或者boundChecker。这一步用IRVisitor遍历IR语法树，目的是要推导出Stmt中Var的Index的范围。

#### 数据结构

既然要推导Var中Index的范围，那么就要设计数据结构保存。采用的数据结构是`map<string, pair<int,int> >`，key是Index的名字，value是Index的区间（pair的first是左端点，左闭右开）。

#### 算法

IRVisitor的遍历顺序大致是Move (-> Binary) -> Var (-> Binary) -> Index。遍历到Move这个节点的时候，主要是做一些初始化的操作。遍历到Var这个节点的时候，visitor会依次遍历args[i]，此时应该同时设置初始区间[0, shape[i])，如果args[i]是一个Index，那么遍历到Index的时候，区间就是[0, shape[i])，Index的范围就被推导出来了。如果args[i]是Binary，那么就看Binary的两个运算数的类型。如果都不是立即数，那么当前的区间不变，继续visit这两个运算数。如果有一个运算数是立即数，那么就利用这个立即数去更改当前的区间（运算符是mod除外，因为无法推导范围），然后再visit另一个运算数。像这样visit，最终总会visit到Index节点，那么用当前的区间去更新数据结构中存储的区间。更新的规则是，如果map中已经有key，则区间求交集；如果没有key，则直接插入map。

算法的正确性在于，对于下标Expr只含一个Index的情况，显然可以得到正确的范围。对于下标Expr是多个Index的线性组合的情况，虽然算法不能给出正确的范围，但是实际上也无法给出正确的范围（多元不等式有无穷多组解）。

### IV. IR mutator

这一步的目的是给Stmt加外层的循环和boundChecker。

#### 算法

从上面的步骤中，我们已经得到了数个形如`dst = Expr`的Move语句。由实验要求，Expr是数个factor由加减号组合起来的，我们应该对factor中的Index求和。因此，我们的目标是将其翻译成

	for index1 in dst
		if index1 is inbounded then
			temp_dst[index1] = 0
			for factor in Expr
				for index2 in factor and index2 notin dst
					if index2 is inbounded then
						temp_dst[index1] = temp_dst[index1] op factor[index2]
	
	for index1 in dst
		if index1 is inbounded then
			dst[index1] = temp_dst[index1]

即对Move语句，把其中的Expr拆成若干个factor，这些factor不能再被拆开，且用加减号连接；把其中的dst做一个备份temp_dst。外层循环是temp_dst的所有Index，循环体是先把temp_dst置为0。然后对每个factor，先翻译得到factor的Expr，再用temp_dst组装得到Move，再用factor的下标Expr和Move组装出boundchecker，最后在外层用所有factor中出现过且dst中未出现过的Index和boundchecker组装for循环。最后再把temp_dst存回dst中。

如何拆分factor呢？在Binary中，如果发现运算符是加减号，那么就继续visit；否则就认为已经进入了factor。在Var中，如果还没有进入factor，就认为单个的Var也是factor。由于括号被理解成一种一元恒等运算，所以在Unary中，也认为进入了factor。

#### 数据结构

	// key是Index的name，value是Index，用于存储使用过的ID
	map<string, Expr> leftIDTable, currentIDTable;
	// 存储所有dst中使用过的ID
	set<string> isLeftID;
	// 存储factor中下标Expr和范围，用于boundChecker
	vector<pair<Expr, int> > currentExprBound;

### V. IR to cpp

经过上述步骤后，得到了一组Stmt节点，在这些节点中还使用了一些未声明的临时变量符号。

该步骤将上述节点结合case的JSON文件中的信息，生成完整的C++语言代码，并写入目标文件中。首先生成头文件引用，然后生成函数签名，由JSON文件中的data_type字段确定参数的类型，由name字段确定函数名，再根据之前步骤中获得的IRVisitor::varShapeTable确定每个参数的shape。

之后为IRNodes中出现的临时变量生成声明语句，依据前面步骤产生的allTempList完成。

最后，遍历Stmt向量，调用修改过的IRPrinter，为每一个节点生成正确的C++代码。

## 成员分工

 - 张家硕：第二部分（由Kernel字符串生成抽象语法树，再转换为IR节点树）
 - 游凌云：第三部分和第四部分（遍历IR节点树，收集相关信息推导索引范围，并生成边界检查语句）
 - 曹浩威：第一部分和第五部分（输入输出、解析JSON字符串、由IR节点生成C++代码、生成函数签名和临时变量声明语句）及编写CMakeLists对第三方库进行编译链接


