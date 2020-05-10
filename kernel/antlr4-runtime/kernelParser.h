
// Generated from kernel.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  kernelParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, IntV = 9, FloatV = 10, Id = 11, PLUS = 12, MUL = 13, INTDIV = 14, 
    DIV = 15, MOD = 16, MINUS = 17, WS = 18
  };

  enum {
    RuleProg = 0, RuleP = 1, RuleP1 = 2, RuleS = 3, RuleLhs = 4, RuleRhs = 5, 
    RuleRhsFirstCalc = 6, RuleRhsSecondCalc = 7, RuleTRef = 8, RuleSRef = 9, 
    RuleClist = 10, RuleClistNode = 11, RuleAlist = 12, RuleAlistNode = 13, 
    RuleIdExpr = 14, RuleIdExprFirstCalc = 15, RuleConstNum = 16
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
  class RhsContext;
  class RhsFirstCalcContext;
  class RhsSecondCalcContext;
  class TRefContext;
  class SRefContext;
  class ClistContext;
  class ClistNodeContext;
  class AlistContext;
  class AlistNodeContext;
  class IdExprContext;
  class IdExprFirstCalcContext;
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

  class  RhsContext : public antlr4::ParserRuleContext {
  public:
    RhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RhsContext() = default;
    void copyFrom(RhsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RHSconstNumContext : public RhsContext {
  public:
    RHSconstNumContext(RhsContext *ctx);

    ConstNumContext *constNum();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RHSSecondopRHSContext : public RhsContext {
  public:
    RHSSecondopRHSContext(RhsContext *ctx);

    std::vector<RhsContext *> rhs();
    RhsContext* rhs(size_t i);
    RhsSecondCalcContext *rhsSecondCalc();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OneRHSContext : public RhsContext {
  public:
    OneRHSContext(RhsContext *ctx);

    RhsContext *rhs();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RHSFirstropRHSContext : public RhsContext {
  public:
    RHSFirstropRHSContext(RhsContext *ctx);

    std::vector<RhsContext *> rhs();
    RhsContext* rhs(size_t i);
    RhsFirstCalcContext *rhsFirstCalc();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RHSsRefContext : public RhsContext {
  public:
    RHSsRefContext(RhsContext *ctx);

    SRefContext *sRef();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RHStRefContext : public RhsContext {
  public:
    RHStRefContext(RhsContext *ctx);

    TRefContext *tRef();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RhsContext* rhs();
  RhsContext* rhs(int precedence);
  class  RhsFirstCalcContext : public antlr4::ParserRuleContext {
  public:
    RhsFirstCalcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RhsFirstCalcContext() = default;
    void copyFrom(RhsFirstCalcContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RHSFirstCalcIsDIVContext : public RhsFirstCalcContext {
  public:
    RHSFirstCalcIsDIVContext(RhsFirstCalcContext *ctx);

    antlr4::tree::TerminalNode *DIV();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RHSFirstCalcINTDIVContext : public RhsFirstCalcContext {
  public:
    RHSFirstCalcINTDIVContext(RhsFirstCalcContext *ctx);

    antlr4::tree::TerminalNode *INTDIV();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RHSFirstCalcIsMULContext : public RhsFirstCalcContext {
  public:
    RHSFirstCalcIsMULContext(RhsFirstCalcContext *ctx);

    antlr4::tree::TerminalNode *MUL();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RHSFirstCalcMODContext : public RhsFirstCalcContext {
  public:
    RHSFirstCalcMODContext(RhsFirstCalcContext *ctx);

    antlr4::tree::TerminalNode *MOD();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RhsFirstCalcContext* rhsFirstCalc();

  class  RhsSecondCalcContext : public antlr4::ParserRuleContext {
  public:
    RhsSecondCalcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RhsSecondCalcContext() = default;
    void copyFrom(RhsSecondCalcContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RHSSecondCalcIsPLUSContext : public RhsSecondCalcContext {
  public:
    RHSSecondCalcIsPLUSContext(RhsSecondCalcContext *ctx);

    antlr4::tree::TerminalNode *PLUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RHSSecondCalcIsMINUSContext : public RhsSecondCalcContext {
  public:
    RHSSecondCalcIsMINUSContext(RhsSecondCalcContext *ctx);

    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RhsSecondCalcContext* rhsSecondCalc();

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

  class  IdExprContext : public antlr4::ParserRuleContext {
  public:
    IdExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    IdExprContext() = default;
    void copyFrom(IdExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FirstIdIntVContext : public IdExprContext {
  public:
    FirstIdIntVContext(IdExprContext *ctx);

    IdExprContext *idExpr();
    IdExprFirstCalcContext *idExprFirstCalc();
    antlr4::tree::TerminalNode *IntV();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdIdContext : public IdExprContext {
  public:
    IdIdContext(IdExprContext *ctx);

    std::vector<IdExprContext *> idExpr();
    IdExprContext* idExpr(size_t i);
    antlr4::tree::TerminalNode *PLUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SecondIdIntVContext : public IdExprContext {
  public:
    SecondIdIntVContext(IdExprContext *ctx);

    IdExprContext *idExpr();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *IntV();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OneIdContext : public IdExprContext {
  public:
    OneIdContext(IdExprContext *ctx);

    antlr4::tree::TerminalNode *Id();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OneIdExprContext : public IdExprContext {
  public:
    OneIdExprContext(IdExprContext *ctx);

    IdExprContext *idExpr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IdExprContext* idExpr();
  IdExprContext* idExpr(int precedence);
  class  IdExprFirstCalcContext : public antlr4::ParserRuleContext {
  public:
    IdExprFirstCalcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    IdExprFirstCalcContext() = default;
    void copyFrom(IdExprFirstCalcContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IdExprCalcIsMODContext : public IdExprFirstCalcContext {
  public:
    IdExprCalcIsMODContext(IdExprFirstCalcContext *ctx);

    antlr4::tree::TerminalNode *MOD();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdExprCalcIsMULContext : public IdExprFirstCalcContext {
  public:
    IdExprCalcIsMULContext(IdExprFirstCalcContext *ctx);

    antlr4::tree::TerminalNode *MUL();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdExprCalcIsINTDIVContext : public IdExprFirstCalcContext {
  public:
    IdExprCalcIsINTDIVContext(IdExprFirstCalcContext *ctx);

    antlr4::tree::TerminalNode *INTDIV();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IdExprFirstCalcContext* idExprFirstCalc();

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


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool rhsSempred(RhsContext *_localctx, size_t predicateIndex);
  bool idExprSempred(IdExprContext *_localctx, size_t predicateIndex);

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

