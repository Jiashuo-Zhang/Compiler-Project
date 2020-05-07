grammar kernel;

prog: P EOF
;

P : S P1
;
P1 
: S P1
| 
;

S : LHS '=' RHS 
;
LHS : TRef
;
RHS1 : '(' RHS ')'
        | TRef
        | SRef
        | Const
;

RHS : RHS1 RHS2
;
RHS2 : '+' RHS2
       	| '*' RHS2
        | '-' RHS2
        | '/' RHS2
        | '%' RHS2
        | '/' '/' RHS2
        | RHS1
        |
;
TRef : Id '<' CList '>' '[' AList ']'
;
SRef : Id '<' CList '>'
;

CList : IntV CList1
;
CList1 : ',' IntV CList1
| 
;

AList : IdExpr AList1
;
AList1 : ',' IdExpr AList1
| 
;

IdExpr1 : Id
|'(' IdExpr ')'
;
IdExpr : IdExpr1 IdExpr2
;
IdExpr2 : '+' IdExpr IdExpr2
| '+' IntV IdExpr2
| '*' IntV IdExpr2
| '/' '/' IntV IdExpr2
| '%' IntV IdExpr2
;
Const : FloatV 
| IntV
;

IntV : [0-9]+
;
FloatV: [0-9]+ ('.')* [0-9]*
;
Id :[a-z,A-Z]+
;


WS  : [ \r\n\t]+ -> skip      
    ;

