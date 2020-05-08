grammar kernel;

prog: P EOF
|EOF
;

P : [S]+
;

S : LHS '=' RHS 
;
LHS : TRef
;

SimpleRHS : '(' RHS ')'
        | TRef
        | SRef
        | Const
;

RHS : SimpleRHS [RHS2]*
;
RHS2 : '+' SimpleRHS
       	| '*' SimpleRHS
        | '-' SimpleRHS
        | '/' SimpleRHS
        | '%' SimpleRHS
        | '/' '/' SimpleRHS
;

TRef : Id '<' CList '>' '[' AList ']'
;
SRef : Id '<' CList '>'
;

CList : IntV [CListNode]*
;

CListNode : ',' IntV
;

AList : IdExpr [AListNode]*
;
AListNode: ',' IdExpr
;


SimpleIdExpr : Id
|'(' IdExpr ')'
;

IdExpr : SimpleIdExpr [IdExpr2]+
;
IdExpr2 : '+' SimpleIdExpr
| '+' IntV
| '*' IntV
| '/' '/' IntV
| '%' IntV
;

Const : FloatV 
| IntV
;

IntV : [0-9]+
;
FloatV: [0-9]+ ('.')* [0-9]*
;
Id :[a-zA-Z]+
;


WS  : [ \r\n\t]+ -> skip      
    ;

