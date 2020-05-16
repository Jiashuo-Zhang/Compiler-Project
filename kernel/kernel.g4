grammar kernel;

prog: p EOF # Start
|EOF # End
;

p : s ';' p1 # VisitP
;
p1 : s ';' p1 # VisitP1
| # P1Nothing
;

s : lhs '=' rhs   # VisitS
;

lhs : tRef  # LHS
;


rhs : rhs rhsFirstCalc rhs # RHSFirstropRHS
| rhs rhsSecondCalc rhs # RHSSecondopRHS
| tRef # RHStRef
| sRef # RHSsRef
| constNum # RHSconstNum
| '(' rhs ')' # OneRHS
;
rhsFirstCalc : MUL # RHSFirstCalcIsMUL
|DIV # RHSFirstCalcIsDIV
|MOD # RHSFirstCalcMOD
|INTDIV # RHSFirstCalcINTDIV
; 
rhsSecondCalc : PLUS # RHSSecondCalcIsPLUS
|MINUS # RHSSecondCalcIsMINUS
;




tRef : Id '<' clist '>' '[' alist ']' # TREF
;
sRef : Id '<' clist '>' # SREF
;

clist : IntV clistNode #CLIST
;

clistNode : ',' IntV clistNode # CLISTNODE
| # CLISTNODENothing
;

alist : idExpr alistNode # ALIST
;
alistNode: ',' idExpr alistNode # ALISTNODE
| # ALISTNODENothing
;


idExpr : idExpr idExprFirstCalc IntV # FirstIdIntV
| idExpr idExprSecondCalc IntV # SecondIdIntV
| idExpr PLUS idExpr #IdId
| Id # OneId
| '(' idExpr ')' # OneIdExpr
;

idExprFirstCalc : MUL # idExprCalcIsMUL
|INTDIV # idExprCalcIsINTDIV
|MOD # idExprCalcIsMOD
;
idExprSecondCalc: PLUS # idSecondCalcIsPLUS
|MINUS # idSecondCalcIsMINUS
;



constNum : FloatV # FloatConst
| IntV # IntConst
;


IntV : '-'*[0-9]+ 
;
FloatV: '-'*[0-9]+ '.'* [0-9]* 
;
Id :[a-zA-Z]+ 
;
PLUS: '+';
MUL: '*';
INTDIV: '/''/';
DIV: '/';
MOD: '%';
MINUS: '-';

WS  : [ \r\n\t]+ -> skip      
    ;

