
// Generated from kernel.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"

class  kernelParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, IntV = 9, FloatV = 10, Id = 11, PLUS = 12, MUL = 13, DIV = 14, 
    MOD = 15, MINUS = 16, WS = 17
  };

  enum {
    RuleProg = 0, RuleP = 1, RuleP1 = 2, RuleS = 3, RuleLhs = 4, RuleSimpleRHS = 5, 
    RuleRhs = 6, RuleRhs2 = 7, RuleTRef = 8, RuleSRef = 9, RuleClist = 10, 
    RuleClistNode = 11, RuleAlist = 12, RuleAlistNode = 13, RuleSimpleIdExpr = 14, 
    RuleIdExpr = 15, RuleIdExpr2 = 16, RuleConstNum = 17
  };

  kernelParser(antlr4::TokenStream *input);
  ~kernelParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext;
  class PContext;
  class P1Context;
  class SContext;
  class LhsContext;
  class SimpleRHSContext;
  class RhsContext;
  class Rhs2Context;
  class TRefContext;
  class SRefContext;
  class ClistContext;
  class ClistNodeContext;
  class AlistContext;
  class AlistNodeContext;
  class SimpleIdExprContext;
  class IdExprContext;
  class IdExpr2Context;
  class ConstNumContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ProgContext() = default;
    void copyFrom(ProgContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StartContext : public ProgContext {
  public:
    StartContext(ProgContext *ctx);

    PContext *p();
    antlr4::tree::TerminalNode *EOF();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EndContext : public ProgContext {
  public:
    EndContext(ProgContext *ctx);

    antlr4::tree::TerminalNode *EOF();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ProgContext* prog();

  class  PContext : public antlr4::ParserRuleContext {
  public:
    PContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PContext() = default;
    void copyFrom(PContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VisitPContext : public PContext {
  public:
    VisitPContext(PContext *ctx);

    SContext *s();
    P1Context *p1();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PContext* p();

  class  P1Context : public antlr4::ParserRuleContext {
  public:
    P1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    P1Context() = default;
    void copyFrom(P1Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  P1NothingContext : public P1Context {
  public:
    P1NothingContext(P1Context *ctx);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VisitP1Context : public P1Context {
  public:
    VisitP1Context(P1Context *ctx);

    SContext *s();
    P1Context *p1();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  P1Context* p1();

  class  SContext : public antlr4::ParserRuleContext {
  public:
    SContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    SContext() = default;
    void copyFrom(SContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VisitSContext : public SContext {
  public:
    VisitSContext(SContext *ctx);

    LhsContext *lhs();
    RhsContext *rhs();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  SContext* s();

  class  LhsContext : public antlr4::ParserRuleContext {
  public:
    LhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LhsContext() = default;
    void copyFrom(LhsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LHSContext : public LhsContext {
  public:
    LHSContext(LhsContext *ctx);

    TRefContext *tRef();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LhsContext* lhs();

  class  SimpleRHSContext : public antlr4::ParserRuleContext {
  public:
    SimpleRHSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    SimpleRHSContext() = default;
    void copyFrom(SimpleRHSContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  OnesRefContext : public SimpleRHSContext {
  public:
    OnesRefContext(SimpleRHSContext *ctx);

    SRefContext *sRef();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OneconstNumContext : public SimpleRHSContext {
  public:
    OneconstNumContext(SimpleRHSContext *ctx);

    ConstNumContext *constNum();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OnetRefContext : public SimpleRHSContext {
  public:
    OnetRefContext(SimpleRHSContext *ctx);

    TRefContext *tRef();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OneRHSContext : public SimpleRHSContext {
  public:
    OneRHSContext(SimpleRHSContext *ctx);

    RhsContext *rhs();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  SimpleRHSContext* simpleRHS();

  class  RhsContext : public antlr4::ParserRuleContext {
  public:
    RhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RhsContext() = default;
    void copyFrom(RhsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RHSContext : public RhsContext {
  public:
    RHSContext(RhsContext *ctx);

    SimpleRHSContext *simpleRHS();
    Rhs2Context *rhs2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RhsContext* rhs();

  class  Rhs2Context : public antlr4::ParserRuleContext {
  public:
    Rhs2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Rhs2Context() = default;
    void copyFrom(Rhs2Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DivRhs2Context : public Rhs2Context {
  public:
    DivRhs2Context(Rhs2Context *ctx);

    antlr4::tree::TerminalNode *DIV();
    SimpleRHSContext *simpleRHS();
    Rhs2Context *rhs2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PlusRhs2Context : public Rhs2Context {
  public:
    PlusRhs2Context(Rhs2Context *ctx);

    antlr4::tree::TerminalNode *PLUS();
    SimpleRHSContext *simpleRHS();
    Rhs2Context *rhs2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MinusRhs2Context : public Rhs2Context {
  public:
    MinusRhs2Context(Rhs2Context *ctx);

    antlr4::tree::TerminalNode *MINUS();
    SimpleRHSContext *simpleRHS();
    Rhs2Context *rhs2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulRhs2Context : public Rhs2Context {
  public:
    MulRhs2Context(Rhs2Context *ctx);

    antlr4::tree::TerminalNode *MUL();
    SimpleRHSContext *simpleRHS();
    Rhs2Context *rhs2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ModRhs2Context : public Rhs2Context {
  public:
    ModRhs2Context(Rhs2Context *ctx);

    antlr4::tree::TerminalNode *MOD();
    SimpleRHSContext *simpleRHS();
    Rhs2Context *rhs2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntDivRhs2Context : public Rhs2Context {
  public:
    IntDivRhs2Context(Rhs2Context *ctx);

    std::vector<antlr4::tree::TerminalNode *> DIV();
    antlr4::tree::TerminalNode* DIV(size_t i);
    SimpleRHSContext *simpleRHS();
    Rhs2Context *rhs2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RHS2NothingContext : public Rhs2Context {
  public:
    RHS2NothingContext(Rhs2Context *ctx);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Rhs2Context* rhs2();

  class  TRefContext : public antlr4::ParserRuleContext {
  public:
    TRefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TRefContext() = default;
    void copyFrom(TRefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TREFContext : public TRefContext {
  public:
    TREFContext(TRefContext *ctx);

    antlr4::tree::TerminalNode *Id();
    ClistContext *clist();
    AlistContext *alist();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TRefContext* tRef();

  class  SRefContext : public antlr4::ParserRuleContext {
  public:
    SRefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    SRefContext() = default;
    void copyFrom(SRefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SREFContext : public SRefContext {
  public:
    SREFContext(SRefContext *ctx);

    antlr4::tree::TerminalNode *Id();
    ClistContext *clist();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  SRefContext* sRef();

  class  ClistContext : public antlr4::ParserRuleContext {
  public:
    ClistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ClistContext() = default;
    void copyFrom(ClistContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CLISTContext : public ClistContext {
  public:
    CLISTContext(ClistContext *ctx);

    antlr4::tree::TerminalNode *IntV();
    ClistNodeContext *clistNode();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ClistContext* clist();

  class  ClistNodeContext : public antlr4::ParserRuleContext {
  public:
    ClistNodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ClistNodeContext() = default;
    void copyFrom(ClistNodeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CLISTNODENothingContext : public ClistNodeContext {
  public:
    CLISTNODENothingContext(ClistNodeContext *ctx);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CLISTNODEContext : public ClistNodeContext {
  public:
    CLISTNODEContext(ClistNodeContext *ctx);

    antlr4::tree::TerminalNode *IntV();
    ClistNodeContext *clistNode();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ClistNodeContext* clistNode();

  class  AlistContext : public antlr4::ParserRuleContext {
  public:
    AlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AlistContext() = default;
    void copyFrom(AlistContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ALISTContext : public AlistContext {
  public:
    ALISTContext(AlistContext *ctx);

    IdExprContext *idExpr();
    AlistNodeContext *alistNode();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AlistContext* alist();

  class  AlistNodeContext : public antlr4::ParserRuleContext {
  public:
    AlistNodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AlistNodeContext() = default;
    void copyFrom(AlistNodeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ALISTNODEContext : public AlistNodeContext {
  public:
    ALISTNODEContext(AlistNodeContext *ctx);

    IdExprContext *idExpr();
    AlistNodeContext *alistNode();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ALISTNODENothingContext : public AlistNodeContext {
  public:
    ALISTNODENothingContext(AlistNodeContext *ctx);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AlistNodeContext* alistNode();

  class  SimpleIdExprContext : public antlr4::ParserRuleContext {
  public:
    SimpleIdExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    SimpleIdExprContext() = default;
    void copyFrom(SimpleIdExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ONEEXPRContext : public SimpleIdExprContext {
  public:
    ONEEXPRContext(SimpleIdExprContext *ctx);

    IdExprContext *idExpr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IDContext : public SimpleIdExprContext {
  public:
    IDContext(SimpleIdExprContext *ctx);

    antlr4::tree::TerminalNode *Id();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  SimpleIdExprContext* simpleIdExpr();

  class  IdExprContext : public antlr4::ParserRuleContext {
  public:
    IdExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    IdExprContext() = default;
    void copyFrom(IdExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IDEXPRContext : public IdExprContext {
  public:
    IDEXPRContext(IdExprContext *ctx);

    SimpleIdExprContext *simpleIdExpr();
    IdExpr2Context *idExpr2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IdExprContext* idExpr();

  class  IdExpr2Context : public antlr4::ParserRuleContext {
  public:
    IdExpr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    IdExpr2Context() = default;
    void copyFrom(IdExpr2Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MulINTVContext : public IdExpr2Context {
  public:
    MulINTVContext(IdExpr2Context *ctx);

    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *IntV();
    IdExpr2Context *idExpr2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PlusSimpleIDEXPRContext : public IdExpr2Context {
  public:
    PlusSimpleIDEXPRContext(IdExpr2Context *ctx);

    antlr4::tree::TerminalNode *PLUS();
    SimpleIdExprContext *simpleIdExpr();
    IdExpr2Context *idExpr2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ModINTVContext : public IdExpr2Context {
  public:
    ModINTVContext(IdExpr2Context *ctx);

    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *IntV();
    IdExpr2Context *idExpr2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PluesINTVContext : public IdExpr2Context {
  public:
    PluesINTVContext(IdExpr2Context *ctx);

    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *IntV();
    IdExpr2Context *idExpr2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IDEXPRNothingContext : public IdExpr2Context {
  public:
    IDEXPRNothingContext(IdExpr2Context *ctx);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntDivINTVContext : public IdExpr2Context {
  public:
    IntDivINTVContext(IdExpr2Context *ctx);

    std::vector<antlr4::tree::TerminalNode *> DIV();
    antlr4::tree::TerminalNode* DIV(size_t i);
    antlr4::tree::TerminalNode *IntV();
    IdExpr2Context *idExpr2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IdExpr2Context* idExpr2();

  class  ConstNumContext : public antlr4::ParserRuleContext {
  public:
    ConstNumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstNumContext() = default;
    void copyFrom(ConstNumContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IntConstContext : public ConstNumContext {
  public:
    IntConstContext(ConstNumContext *ctx);

    antlr4::tree::TerminalNode *IntV();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FloatConstContext : public ConstNumContext {
  public:
    FloatConstContext(ConstNumContext *ctx);

    antlr4::tree::TerminalNode *FloatV();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ConstNumContext* constNum();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

