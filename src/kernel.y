%{
	#include "IR.h";
	#include "IRMutator.h"
	#include "IRVisitor.h"
	#include "IRPrinter.h"
	#include "type.h"
	#include <vector>
	#include <deque>
	#define YYSTYPE string
	using namespace Boost::Internal;
	struct PDef
	{
		deque<Expr> StmtList;
	}P,P1;
	struct SDef
	{
		Expr stmt;
	}S;
	struct HsDef
	{
		Expr expr;
	}LHS,RHS;
	struct RHSDef
	{
		Expr expr;
	}RHS,RHS1,RHS2,LHS;
	sturct ConstDef
	{
		Expr value;
	}Const;
	String Id,TRefId,SRefId;
	struct CListDef
	{
		vector<int> List;
	}TRefClist,SRefClistClist;
	Struct AListDef
	{
	 	vector<String> list;
	}TRefAlist,Alist;

%}
%token FloatV IntV Id Lt Lb Lr Rt Rb Rr Plus Multi Minus Mod Div IntDiv Comma Eq

%%
P : S P1 {P.StmtList=P1.StmtList; P.StmtList.push_front(S.stmt);}
;
P1: {}
| S P1 {P1.StmlList.push_back(S.stmt);}
;
S : LHS Eq RHS {S.stmt=Move::make(LHS.expr,RHS.expr,MoveType::MemToMem);}
;

LHS : TRef {LHS.expr=TRef.var;}
;
RHS : RHS{RHS1=RHS} + RHS {RHS2=RHS}{RHS.expr=Binary::Make(data_type,BinaryOpType::Add,RHS1.expr,RHS2.expr);}
|RHS{RHS1=RHS} * RHS {RHS2=RHS}{RHS.expr=Binary::Make(data_type,BinaryOpType::Mul,RHS1.expr,RHS2.expr);}
|RHS{RHS1=RHS} - RHS {RHS2=RHS}{RHS.expr=Binary::Make(data_type,BinaryOpType::Sub,RHS1.expr,RHS2.expr);}
|RHS{RHS1=RHS} / RHS {RHS2=RHS}{RHS.expr=Binary::Make(data_type,BinaryOpType::Div,RHS1.expr,RHS2.expr);}
|RHS{RHS1=RHS} % RHS {RHS2=RHS}{RHS.expr=Binary::Make(data_type,BinaryOpType::Mod,RHS1.expr,RHS2.expr);}
|RHS{RHS1=RHS} // RHS {RHS2=RHS}{RHS.expr=Binary::Make(index_type,BinaryOpType::Div,RHS1.expr,RHS2.expr);}
|Lr RHS Rr{RHS.expr=RHS.expr;}
|TRef{RHS.expr=TRef.var;}
|SRef{RHS.expr=SRef.var;}
|Const{RHS.expr=Const.value;}
;

TRef : Id{TRefId=Id} Lt Clist{TRefClist=Clist} Rt Lb Alist{TRefAlist=Alist} Rb {Var::make(data_type,Id,TRefClist.list,TRefAlist.list);}
;
SRef : Id{SRefId=Id} Lt Clist{SRefClist=Clist} Rt {Var::make(data_type,Id,TRefClist.list,null);}
;

Clist : IntV  Clist1{Clist=new Clist();Clist.push_back(IntV.value)}
;
Clist1 :{}
| IntV Clist1
;

TODO: 还剩几个产生式未完成；Make时的参数类型不匹配；SDD求值正确性（特别是重复RHS: RHS + RHS这种有类似“覆盖”的情况）；编译；测试





%%
void main()
 {
     yyparse();
 }
 int yyerror(char* msg)
 {
 printf("Error: %s encountered \n", msg);
 }