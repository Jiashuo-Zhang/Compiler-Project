grammar kernel;

prog: p EOF # Start
|EOF # End
;

p : s p1 # VisitP
;
p1 : s p1 # VisitP1
| # P1Nothing
;

s : lhs '=' rhs   # VisitS
;

lhs : tRef  # LHS
;

simpleRHS 
: '(' rhs ')' # OneRHS
| tRef # OnetRef
| sRef # OnesRef
| constNum # OneconstNum
;

rhs : simpleRHS rhs2 # RHS
;
rhs2 : PLUS simpleRHS rhs2 # plusRhs2
       	| MUL simpleRHS rhs2 # mulRhs2
        | MINUS simpleRHS rhs2 # minusRhs2
        | DIV simpleRHS rhs2 # divRhs2
        | MOD simpleRHS rhs2 # modRhs2
        | DIV DIV simpleRHS rhs2 #intDivRhs2
        | # RHS2Nothing
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


simpleIdExpr : Id  # ID
|'(' idExpr ')'  # ONEEXPR
;

idExpr : simpleIdExpr idExpr2 # IDEXPR
;

idExpr2 : PLUS simpleIdExpr idExpr2 # PlusSimpleIDEXPR
| PLUS IntV idExpr2  # PluesINTV
| MUL IntV idExpr2 # MulINTV
| DIV DIV IntV idExpr2 # IntDivINTV  
| MOD IntV idExpr2 # ModINTV
| # IDEXPRNothing
;

constNum : FloatV # FloatConst
| IntV # IntConst
;

IntV : [0-9]+ 
;
FloatV: [0-9]+ ('.')* [0-9]* 
;
Id :[a-zA-Z]+ 
;
PLUS: '+';
MUL: '*';
DIV: '/';
MOD: '%';
MINUS: '-';

WS  : [ \r\n\t]+ -> skip      
    ;

