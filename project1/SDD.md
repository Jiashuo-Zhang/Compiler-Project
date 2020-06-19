```
P ::= P S{P.stmtList.add(S.stmt))| S {P.stmtList.add(S.stmt)}
S ::= LHS = RHS{S.stmt=Move::make(LHS.expr,RHS.expr,MoveType::MemToMem};
LHS ::= TRef{LHS.expr=TRef.var}
RHS ::= RHS + RHS{RHS.expr=Binary::Make(data_type,BinaryOpType::Add,RHS.expr,RHS.expr)}
        | RHS * RHS{同}
        | RHS - RHS...
        | RHS / RHS...
        | RHS % RHS{同}
        | RHS // RHS{同}
        | (RHS){RHS.expr=RHS.expr}
        | TRef {RHS.expr=TRef.var}
        | SRef {RHS.expr=SRef.var}
        | Const {RHS.expr=Const.value}
TRef ::= Id < CList > [ AList ] {TRef.var=Var::make(data_type,ID.toString,CList.list,Alist.list)}
SRef ::= Id < CList > {SRef.var=Var::make(data_type,ID.toString,CList.list,Alist.list)}
CList ::= CList , IntV {Clist.list.add{IntV.value}}| IntV {Clist.list.add{IntV.value}}
AList ::= AList , IdExpr{Alist.list.add(IdExpr.toString)} | IdExpr{Alist.list.add(IdExpr.toString)}
IdExpr ::= Id{Dom::make，Index::make} | IdExpr + IdExpr | IdExpr + IntV | IdExpr * IntV | IdExpr // IntV | IdExpr % IntV | (IdExpr){IdExpr.toString=IdExpr.toString+"+"+IdExpr.toString（以IdExpr+IdExpr为例）}
Const ::= FloatV {Const.value=FloatV.value}| IntV {Const.value=IntV.value}
```

