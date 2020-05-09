
// Generated from kernel.g4 by ANTLR 4.7.2


#include "kernelVisitor.h"

#include "kernelParser.h"


using namespace antlrcpp;
using namespace antlr4;

kernelParser::kernelParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

kernelParser::~kernelParser() {
  delete _interpreter;
}

std::string kernelParser::getGrammarFileName() const {
  return "kernel.g4";
}

const std::vector<std::string>& kernelParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& kernelParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

kernelParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::ProgContext::getRuleIndex() const {
  return kernelParser::RuleProg;
}

void kernelParser::ProgContext::copyFrom(ProgContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StartContext ------------------------------------------------------------------

kernelParser::PContext* kernelParser::StartContext::p() {
  return getRuleContext<kernelParser::PContext>(0);
}

tree::TerminalNode* kernelParser::StartContext::EOF() {
  return getToken(kernelParser::EOF, 0);
}

kernelParser::StartContext::StartContext(ProgContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EndContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::EndContext::EOF() {
  return getToken(kernelParser::EOF, 0);
}

kernelParser::EndContext::EndContext(ProgContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::EndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitEnd(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::ProgContext* kernelParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, kernelParser::RuleProg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(40);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::Id: {
        _localctx = dynamic_cast<ProgContext *>(_tracker.createInstance<kernelParser::StartContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(36);
        p();
        setState(37);
        match(kernelParser::EOF);
        break;
      }

      case kernelParser::EOF: {
        _localctx = dynamic_cast<ProgContext *>(_tracker.createInstance<kernelParser::EndContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(39);
        match(kernelParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PContext ------------------------------------------------------------------

kernelParser::PContext::PContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::PContext::getRuleIndex() const {
  return kernelParser::RuleP;
}

void kernelParser::PContext::copyFrom(PContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VisitPContext ------------------------------------------------------------------

kernelParser::SContext* kernelParser::VisitPContext::s() {
  return getRuleContext<kernelParser::SContext>(0);
}

kernelParser::P1Context* kernelParser::VisitPContext::p1() {
  return getRuleContext<kernelParser::P1Context>(0);
}

kernelParser::VisitPContext::VisitPContext(PContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::VisitPContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitVisitP(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::PContext* kernelParser::p() {
  PContext *_localctx = _tracker.createInstance<PContext>(_ctx, getState());
  enterRule(_localctx, 2, kernelParser::RuleP);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<PContext *>(_tracker.createInstance<kernelParser::VisitPContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(42);
    s();
    setState(43);
    p1();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- P1Context ------------------------------------------------------------------

kernelParser::P1Context::P1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::P1Context::getRuleIndex() const {
  return kernelParser::RuleP1;
}

void kernelParser::P1Context::copyFrom(P1Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- P1NothingContext ------------------------------------------------------------------

kernelParser::P1NothingContext::P1NothingContext(P1Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::P1NothingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitP1Nothing(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VisitP1Context ------------------------------------------------------------------

kernelParser::SContext* kernelParser::VisitP1Context::s() {
  return getRuleContext<kernelParser::SContext>(0);
}

kernelParser::P1Context* kernelParser::VisitP1Context::p1() {
  return getRuleContext<kernelParser::P1Context>(0);
}

kernelParser::VisitP1Context::VisitP1Context(P1Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::VisitP1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitVisitP1(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::P1Context* kernelParser::p1() {
  P1Context *_localctx = _tracker.createInstance<P1Context>(_ctx, getState());
  enterRule(_localctx, 4, kernelParser::RuleP1);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(49);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::Id: {
        _localctx = dynamic_cast<P1Context *>(_tracker.createInstance<kernelParser::VisitP1Context>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(45);
        s();
        setState(46);
        p1();
        break;
      }

      case kernelParser::EOF: {
        _localctx = dynamic_cast<P1Context *>(_tracker.createInstance<kernelParser::P1NothingContext>(_localctx));
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SContext ------------------------------------------------------------------

kernelParser::SContext::SContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::SContext::getRuleIndex() const {
  return kernelParser::RuleS;
}

void kernelParser::SContext::copyFrom(SContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VisitSContext ------------------------------------------------------------------

kernelParser::LhsContext* kernelParser::VisitSContext::lhs() {
  return getRuleContext<kernelParser::LhsContext>(0);
}

kernelParser::RhsContext* kernelParser::VisitSContext::rhs() {
  return getRuleContext<kernelParser::RhsContext>(0);
}

kernelParser::VisitSContext::VisitSContext(SContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::VisitSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitVisitS(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::SContext* kernelParser::s() {
  SContext *_localctx = _tracker.createInstance<SContext>(_ctx, getState());
  enterRule(_localctx, 6, kernelParser::RuleS);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<SContext *>(_tracker.createInstance<kernelParser::VisitSContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(51);
    lhs();
    setState(52);
    match(kernelParser::T__0);
    setState(53);
    rhs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LhsContext ------------------------------------------------------------------

kernelParser::LhsContext::LhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::LhsContext::getRuleIndex() const {
  return kernelParser::RuleLhs;
}

void kernelParser::LhsContext::copyFrom(LhsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LHSContext ------------------------------------------------------------------

kernelParser::TRefContext* kernelParser::LHSContext::tRef() {
  return getRuleContext<kernelParser::TRefContext>(0);
}

kernelParser::LHSContext::LHSContext(LhsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::LHSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitLHS(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::LhsContext* kernelParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 8, kernelParser::RuleLhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<LhsContext *>(_tracker.createInstance<kernelParser::LHSContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(55);
    tRef();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleRHSContext ------------------------------------------------------------------

kernelParser::SimpleRHSContext::SimpleRHSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::SimpleRHSContext::getRuleIndex() const {
  return kernelParser::RuleSimpleRHS;
}

void kernelParser::SimpleRHSContext::copyFrom(SimpleRHSContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- OnesRefContext ------------------------------------------------------------------

kernelParser::SRefContext* kernelParser::OnesRefContext::sRef() {
  return getRuleContext<kernelParser::SRefContext>(0);
}

kernelParser::OnesRefContext::OnesRefContext(SimpleRHSContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::OnesRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitOnesRef(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OneconstNumContext ------------------------------------------------------------------

kernelParser::ConstNumContext* kernelParser::OneconstNumContext::constNum() {
  return getRuleContext<kernelParser::ConstNumContext>(0);
}

kernelParser::OneconstNumContext::OneconstNumContext(SimpleRHSContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::OneconstNumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitOneconstNum(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OnetRefContext ------------------------------------------------------------------

kernelParser::TRefContext* kernelParser::OnetRefContext::tRef() {
  return getRuleContext<kernelParser::TRefContext>(0);
}

kernelParser::OnetRefContext::OnetRefContext(SimpleRHSContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::OnetRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitOnetRef(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OneRHSContext ------------------------------------------------------------------

kernelParser::RhsContext* kernelParser::OneRHSContext::rhs() {
  return getRuleContext<kernelParser::RhsContext>(0);
}

kernelParser::OneRHSContext::OneRHSContext(SimpleRHSContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::OneRHSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitOneRHS(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::SimpleRHSContext* kernelParser::simpleRHS() {
  SimpleRHSContext *_localctx = _tracker.createInstance<SimpleRHSContext>(_ctx, getState());
  enterRule(_localctx, 10, kernelParser::RuleSimpleRHS);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(64);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<SimpleRHSContext *>(_tracker.createInstance<kernelParser::OneRHSContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(57);
      match(kernelParser::T__1);
      setState(58);
      rhs();
      setState(59);
      match(kernelParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<SimpleRHSContext *>(_tracker.createInstance<kernelParser::OnetRefContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(61);
      tRef();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<SimpleRHSContext *>(_tracker.createInstance<kernelParser::OnesRefContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(62);
      sRef();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<SimpleRHSContext *>(_tracker.createInstance<kernelParser::OneconstNumContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(63);
      constNum();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RhsContext ------------------------------------------------------------------

kernelParser::RhsContext::RhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::RhsContext::getRuleIndex() const {
  return kernelParser::RuleRhs;
}

void kernelParser::RhsContext::copyFrom(RhsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RHSContext ------------------------------------------------------------------

kernelParser::SimpleRHSContext* kernelParser::RHSContext::simpleRHS() {
  return getRuleContext<kernelParser::SimpleRHSContext>(0);
}

kernelParser::Rhs2Context* kernelParser::RHSContext::rhs2() {
  return getRuleContext<kernelParser::Rhs2Context>(0);
}

kernelParser::RHSContext::RHSContext(RhsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::RHSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitRHS(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::RhsContext* kernelParser::rhs() {
  RhsContext *_localctx = _tracker.createInstance<RhsContext>(_ctx, getState());
  enterRule(_localctx, 12, kernelParser::RuleRhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<RhsContext *>(_tracker.createInstance<kernelParser::RHSContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(66);
    simpleRHS();
    setState(67);
    rhs2();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rhs2Context ------------------------------------------------------------------

kernelParser::Rhs2Context::Rhs2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::Rhs2Context::getRuleIndex() const {
  return kernelParser::RuleRhs2;
}

void kernelParser::Rhs2Context::copyFrom(Rhs2Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DivRhs2Context ------------------------------------------------------------------

tree::TerminalNode* kernelParser::DivRhs2Context::DIV() {
  return getToken(kernelParser::DIV, 0);
}

kernelParser::SimpleRHSContext* kernelParser::DivRhs2Context::simpleRHS() {
  return getRuleContext<kernelParser::SimpleRHSContext>(0);
}

kernelParser::Rhs2Context* kernelParser::DivRhs2Context::rhs2() {
  return getRuleContext<kernelParser::Rhs2Context>(0);
}

kernelParser::DivRhs2Context::DivRhs2Context(Rhs2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::DivRhs2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitDivRhs2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusRhs2Context ------------------------------------------------------------------

tree::TerminalNode* kernelParser::PlusRhs2Context::PLUS() {
  return getToken(kernelParser::PLUS, 0);
}

kernelParser::SimpleRHSContext* kernelParser::PlusRhs2Context::simpleRHS() {
  return getRuleContext<kernelParser::SimpleRHSContext>(0);
}

kernelParser::Rhs2Context* kernelParser::PlusRhs2Context::rhs2() {
  return getRuleContext<kernelParser::Rhs2Context>(0);
}

kernelParser::PlusRhs2Context::PlusRhs2Context(Rhs2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::PlusRhs2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitPlusRhs2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MinusRhs2Context ------------------------------------------------------------------

tree::TerminalNode* kernelParser::MinusRhs2Context::MINUS() {
  return getToken(kernelParser::MINUS, 0);
}

kernelParser::SimpleRHSContext* kernelParser::MinusRhs2Context::simpleRHS() {
  return getRuleContext<kernelParser::SimpleRHSContext>(0);
}

kernelParser::Rhs2Context* kernelParser::MinusRhs2Context::rhs2() {
  return getRuleContext<kernelParser::Rhs2Context>(0);
}

kernelParser::MinusRhs2Context::MinusRhs2Context(Rhs2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::MinusRhs2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitMinusRhs2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulRhs2Context ------------------------------------------------------------------

tree::TerminalNode* kernelParser::MulRhs2Context::MUL() {
  return getToken(kernelParser::MUL, 0);
}

kernelParser::SimpleRHSContext* kernelParser::MulRhs2Context::simpleRHS() {
  return getRuleContext<kernelParser::SimpleRHSContext>(0);
}

kernelParser::Rhs2Context* kernelParser::MulRhs2Context::rhs2() {
  return getRuleContext<kernelParser::Rhs2Context>(0);
}

kernelParser::MulRhs2Context::MulRhs2Context(Rhs2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::MulRhs2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitMulRhs2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ModRhs2Context ------------------------------------------------------------------

tree::TerminalNode* kernelParser::ModRhs2Context::MOD() {
  return getToken(kernelParser::MOD, 0);
}

kernelParser::SimpleRHSContext* kernelParser::ModRhs2Context::simpleRHS() {
  return getRuleContext<kernelParser::SimpleRHSContext>(0);
}

kernelParser::Rhs2Context* kernelParser::ModRhs2Context::rhs2() {
  return getRuleContext<kernelParser::Rhs2Context>(0);
}

kernelParser::ModRhs2Context::ModRhs2Context(Rhs2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::ModRhs2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitModRhs2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntDivRhs2Context ------------------------------------------------------------------

std::vector<tree::TerminalNode *> kernelParser::IntDivRhs2Context::DIV() {
  return getTokens(kernelParser::DIV);
}

tree::TerminalNode* kernelParser::IntDivRhs2Context::DIV(size_t i) {
  return getToken(kernelParser::DIV, i);
}

kernelParser::SimpleRHSContext* kernelParser::IntDivRhs2Context::simpleRHS() {
  return getRuleContext<kernelParser::SimpleRHSContext>(0);
}

kernelParser::Rhs2Context* kernelParser::IntDivRhs2Context::rhs2() {
  return getRuleContext<kernelParser::Rhs2Context>(0);
}

kernelParser::IntDivRhs2Context::IntDivRhs2Context(Rhs2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::IntDivRhs2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitIntDivRhs2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RHS2NothingContext ------------------------------------------------------------------

kernelParser::RHS2NothingContext::RHS2NothingContext(Rhs2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::RHS2NothingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitRHS2Nothing(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::Rhs2Context* kernelParser::rhs2() {
  Rhs2Context *_localctx = _tracker.createInstance<Rhs2Context>(_ctx, getState());
  enterRule(_localctx, 14, kernelParser::RuleRhs2);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(95);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Rhs2Context *>(_tracker.createInstance<kernelParser::PlusRhs2Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(69);
      match(kernelParser::PLUS);
      setState(70);
      simpleRHS();
      setState(71);
      rhs2();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Rhs2Context *>(_tracker.createInstance<kernelParser::MulRhs2Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(73);
      match(kernelParser::MUL);
      setState(74);
      simpleRHS();
      setState(75);
      rhs2();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Rhs2Context *>(_tracker.createInstance<kernelParser::MinusRhs2Context>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(77);
      match(kernelParser::MINUS);
      setState(78);
      simpleRHS();
      setState(79);
      rhs2();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<Rhs2Context *>(_tracker.createInstance<kernelParser::DivRhs2Context>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(81);
      match(kernelParser::DIV);
      setState(82);
      simpleRHS();
      setState(83);
      rhs2();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<Rhs2Context *>(_tracker.createInstance<kernelParser::ModRhs2Context>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(85);
      match(kernelParser::MOD);
      setState(86);
      simpleRHS();
      setState(87);
      rhs2();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<Rhs2Context *>(_tracker.createInstance<kernelParser::IntDivRhs2Context>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(89);
      match(kernelParser::DIV);
      setState(90);
      match(kernelParser::DIV);
      setState(91);
      simpleRHS();
      setState(92);
      rhs2();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<Rhs2Context *>(_tracker.createInstance<kernelParser::RHS2NothingContext>(_localctx));
      enterOuterAlt(_localctx, 7);

      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TRefContext ------------------------------------------------------------------

kernelParser::TRefContext::TRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::TRefContext::getRuleIndex() const {
  return kernelParser::RuleTRef;
}

void kernelParser::TRefContext::copyFrom(TRefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TREFContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::TREFContext::Id() {
  return getToken(kernelParser::Id, 0);
}

kernelParser::ClistContext* kernelParser::TREFContext::clist() {
  return getRuleContext<kernelParser::ClistContext>(0);
}

kernelParser::AlistContext* kernelParser::TREFContext::alist() {
  return getRuleContext<kernelParser::AlistContext>(0);
}

kernelParser::TREFContext::TREFContext(TRefContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::TREFContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitTREF(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::TRefContext* kernelParser::tRef() {
  TRefContext *_localctx = _tracker.createInstance<TRefContext>(_ctx, getState());
  enterRule(_localctx, 16, kernelParser::RuleTRef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<TRefContext *>(_tracker.createInstance<kernelParser::TREFContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(kernelParser::Id);
    setState(98);
    match(kernelParser::T__3);
    setState(99);
    clist();
    setState(100);
    match(kernelParser::T__4);
    setState(101);
    match(kernelParser::T__5);
    setState(102);
    alist();
    setState(103);
    match(kernelParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SRefContext ------------------------------------------------------------------

kernelParser::SRefContext::SRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::SRefContext::getRuleIndex() const {
  return kernelParser::RuleSRef;
}

void kernelParser::SRefContext::copyFrom(SRefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SREFContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::SREFContext::Id() {
  return getToken(kernelParser::Id, 0);
}

kernelParser::ClistContext* kernelParser::SREFContext::clist() {
  return getRuleContext<kernelParser::ClistContext>(0);
}

kernelParser::SREFContext::SREFContext(SRefContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::SREFContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitSREF(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::SRefContext* kernelParser::sRef() {
  SRefContext *_localctx = _tracker.createInstance<SRefContext>(_ctx, getState());
  enterRule(_localctx, 18, kernelParser::RuleSRef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<SRefContext *>(_tracker.createInstance<kernelParser::SREFContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(kernelParser::Id);
    setState(106);
    match(kernelParser::T__3);
    setState(107);
    clist();
    setState(108);
    match(kernelParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClistContext ------------------------------------------------------------------

kernelParser::ClistContext::ClistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::ClistContext::getRuleIndex() const {
  return kernelParser::RuleClist;
}

void kernelParser::ClistContext::copyFrom(ClistContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CLISTContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::CLISTContext::IntV() {
  return getToken(kernelParser::IntV, 0);
}

kernelParser::ClistNodeContext* kernelParser::CLISTContext::clistNode() {
  return getRuleContext<kernelParser::ClistNodeContext>(0);
}

kernelParser::CLISTContext::CLISTContext(ClistContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::CLISTContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitCLIST(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::ClistContext* kernelParser::clist() {
  ClistContext *_localctx = _tracker.createInstance<ClistContext>(_ctx, getState());
  enterRule(_localctx, 20, kernelParser::RuleClist);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<ClistContext *>(_tracker.createInstance<kernelParser::CLISTContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(110);
    match(kernelParser::IntV);
    setState(111);
    clistNode();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClistNodeContext ------------------------------------------------------------------

kernelParser::ClistNodeContext::ClistNodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::ClistNodeContext::getRuleIndex() const {
  return kernelParser::RuleClistNode;
}

void kernelParser::ClistNodeContext::copyFrom(ClistNodeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CLISTNODENothingContext ------------------------------------------------------------------

kernelParser::CLISTNODENothingContext::CLISTNODENothingContext(ClistNodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::CLISTNODENothingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitCLISTNODENothing(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CLISTNODEContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::CLISTNODEContext::IntV() {
  return getToken(kernelParser::IntV, 0);
}

kernelParser::ClistNodeContext* kernelParser::CLISTNODEContext::clistNode() {
  return getRuleContext<kernelParser::ClistNodeContext>(0);
}

kernelParser::CLISTNODEContext::CLISTNODEContext(ClistNodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::CLISTNODEContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitCLISTNODE(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::ClistNodeContext* kernelParser::clistNode() {
  ClistNodeContext *_localctx = _tracker.createInstance<ClistNodeContext>(_ctx, getState());
  enterRule(_localctx, 22, kernelParser::RuleClistNode);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(117);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::T__7: {
        _localctx = dynamic_cast<ClistNodeContext *>(_tracker.createInstance<kernelParser::CLISTNODEContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(113);
        match(kernelParser::T__7);
        setState(114);
        match(kernelParser::IntV);
        setState(115);
        clistNode();
        break;
      }

      case kernelParser::T__4: {
        _localctx = dynamic_cast<ClistNodeContext *>(_tracker.createInstance<kernelParser::CLISTNODENothingContext>(_localctx));
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AlistContext ------------------------------------------------------------------

kernelParser::AlistContext::AlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::AlistContext::getRuleIndex() const {
  return kernelParser::RuleAlist;
}

void kernelParser::AlistContext::copyFrom(AlistContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ALISTContext ------------------------------------------------------------------

kernelParser::IdExprContext* kernelParser::ALISTContext::idExpr() {
  return getRuleContext<kernelParser::IdExprContext>(0);
}

kernelParser::AlistNodeContext* kernelParser::ALISTContext::alistNode() {
  return getRuleContext<kernelParser::AlistNodeContext>(0);
}

kernelParser::ALISTContext::ALISTContext(AlistContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::ALISTContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitALIST(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::AlistContext* kernelParser::alist() {
  AlistContext *_localctx = _tracker.createInstance<AlistContext>(_ctx, getState());
  enterRule(_localctx, 24, kernelParser::RuleAlist);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<AlistContext *>(_tracker.createInstance<kernelParser::ALISTContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(119);
    idExpr();
    setState(120);
    alistNode();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AlistNodeContext ------------------------------------------------------------------

kernelParser::AlistNodeContext::AlistNodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::AlistNodeContext::getRuleIndex() const {
  return kernelParser::RuleAlistNode;
}

void kernelParser::AlistNodeContext::copyFrom(AlistNodeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ALISTNODEContext ------------------------------------------------------------------

kernelParser::IdExprContext* kernelParser::ALISTNODEContext::idExpr() {
  return getRuleContext<kernelParser::IdExprContext>(0);
}

kernelParser::AlistNodeContext* kernelParser::ALISTNODEContext::alistNode() {
  return getRuleContext<kernelParser::AlistNodeContext>(0);
}

kernelParser::ALISTNODEContext::ALISTNODEContext(AlistNodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::ALISTNODEContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitALISTNODE(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ALISTNODENothingContext ------------------------------------------------------------------

kernelParser::ALISTNODENothingContext::ALISTNODENothingContext(AlistNodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::ALISTNODENothingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitALISTNODENothing(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::AlistNodeContext* kernelParser::alistNode() {
  AlistNodeContext *_localctx = _tracker.createInstance<AlistNodeContext>(_ctx, getState());
  enterRule(_localctx, 26, kernelParser::RuleAlistNode);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::T__7: {
        _localctx = dynamic_cast<AlistNodeContext *>(_tracker.createInstance<kernelParser::ALISTNODEContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(122);
        match(kernelParser::T__7);
        setState(123);
        idExpr();
        setState(124);
        alistNode();
        break;
      }

      case kernelParser::T__6: {
        _localctx = dynamic_cast<AlistNodeContext *>(_tracker.createInstance<kernelParser::ALISTNODENothingContext>(_localctx));
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleIdExprContext ------------------------------------------------------------------

kernelParser::SimpleIdExprContext::SimpleIdExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::SimpleIdExprContext::getRuleIndex() const {
  return kernelParser::RuleSimpleIdExpr;
}

void kernelParser::SimpleIdExprContext::copyFrom(SimpleIdExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ONEEXPRContext ------------------------------------------------------------------

kernelParser::IdExprContext* kernelParser::ONEEXPRContext::idExpr() {
  return getRuleContext<kernelParser::IdExprContext>(0);
}

kernelParser::ONEEXPRContext::ONEEXPRContext(SimpleIdExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::ONEEXPRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitONEEXPR(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IDContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::IDContext::Id() {
  return getToken(kernelParser::Id, 0);
}

kernelParser::IDContext::IDContext(SimpleIdExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::IDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitID(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::SimpleIdExprContext* kernelParser::simpleIdExpr() {
  SimpleIdExprContext *_localctx = _tracker.createInstance<SimpleIdExprContext>(_ctx, getState());
  enterRule(_localctx, 28, kernelParser::RuleSimpleIdExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(134);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::Id: {
        _localctx = dynamic_cast<SimpleIdExprContext *>(_tracker.createInstance<kernelParser::IDContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(129);
        match(kernelParser::Id);
        break;
      }

      case kernelParser::T__1: {
        _localctx = dynamic_cast<SimpleIdExprContext *>(_tracker.createInstance<kernelParser::ONEEXPRContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(130);
        match(kernelParser::T__1);
        setState(131);
        idExpr();
        setState(132);
        match(kernelParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdExprContext ------------------------------------------------------------------

kernelParser::IdExprContext::IdExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::IdExprContext::getRuleIndex() const {
  return kernelParser::RuleIdExpr;
}

void kernelParser::IdExprContext::copyFrom(IdExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IDEXPRContext ------------------------------------------------------------------

kernelParser::SimpleIdExprContext* kernelParser::IDEXPRContext::simpleIdExpr() {
  return getRuleContext<kernelParser::SimpleIdExprContext>(0);
}

kernelParser::IdExpr2Context* kernelParser::IDEXPRContext::idExpr2() {
  return getRuleContext<kernelParser::IdExpr2Context>(0);
}

kernelParser::IDEXPRContext::IDEXPRContext(IdExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::IDEXPRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitIDEXPR(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::IdExprContext* kernelParser::idExpr() {
  IdExprContext *_localctx = _tracker.createInstance<IdExprContext>(_ctx, getState());
  enterRule(_localctx, 30, kernelParser::RuleIdExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<IdExprContext *>(_tracker.createInstance<kernelParser::IDEXPRContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(136);
    simpleIdExpr();
    setState(137);
    idExpr2();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdExpr2Context ------------------------------------------------------------------

kernelParser::IdExpr2Context::IdExpr2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::IdExpr2Context::getRuleIndex() const {
  return kernelParser::RuleIdExpr2;
}

void kernelParser::IdExpr2Context::copyFrom(IdExpr2Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MulINTVContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::MulINTVContext::MUL() {
  return getToken(kernelParser::MUL, 0);
}

tree::TerminalNode* kernelParser::MulINTVContext::IntV() {
  return getToken(kernelParser::IntV, 0);
}

kernelParser::IdExpr2Context* kernelParser::MulINTVContext::idExpr2() {
  return getRuleContext<kernelParser::IdExpr2Context>(0);
}

kernelParser::MulINTVContext::MulINTVContext(IdExpr2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::MulINTVContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitMulINTV(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusSimpleIDEXPRContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::PlusSimpleIDEXPRContext::PLUS() {
  return getToken(kernelParser::PLUS, 0);
}

kernelParser::SimpleIdExprContext* kernelParser::PlusSimpleIDEXPRContext::simpleIdExpr() {
  return getRuleContext<kernelParser::SimpleIdExprContext>(0);
}

kernelParser::IdExpr2Context* kernelParser::PlusSimpleIDEXPRContext::idExpr2() {
  return getRuleContext<kernelParser::IdExpr2Context>(0);
}

kernelParser::PlusSimpleIDEXPRContext::PlusSimpleIDEXPRContext(IdExpr2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::PlusSimpleIDEXPRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitPlusSimpleIDEXPR(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ModINTVContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::ModINTVContext::MOD() {
  return getToken(kernelParser::MOD, 0);
}

tree::TerminalNode* kernelParser::ModINTVContext::IntV() {
  return getToken(kernelParser::IntV, 0);
}

kernelParser::IdExpr2Context* kernelParser::ModINTVContext::idExpr2() {
  return getRuleContext<kernelParser::IdExpr2Context>(0);
}

kernelParser::ModINTVContext::ModINTVContext(IdExpr2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::ModINTVContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitModINTV(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PluesINTVContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::PluesINTVContext::PLUS() {
  return getToken(kernelParser::PLUS, 0);
}

tree::TerminalNode* kernelParser::PluesINTVContext::IntV() {
  return getToken(kernelParser::IntV, 0);
}

kernelParser::IdExpr2Context* kernelParser::PluesINTVContext::idExpr2() {
  return getRuleContext<kernelParser::IdExpr2Context>(0);
}

kernelParser::PluesINTVContext::PluesINTVContext(IdExpr2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::PluesINTVContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitPluesINTV(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IDEXPRNothingContext ------------------------------------------------------------------

kernelParser::IDEXPRNothingContext::IDEXPRNothingContext(IdExpr2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::IDEXPRNothingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitIDEXPRNothing(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntDivINTVContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> kernelParser::IntDivINTVContext::DIV() {
  return getTokens(kernelParser::DIV);
}

tree::TerminalNode* kernelParser::IntDivINTVContext::DIV(size_t i) {
  return getToken(kernelParser::DIV, i);
}

tree::TerminalNode* kernelParser::IntDivINTVContext::IntV() {
  return getToken(kernelParser::IntV, 0);
}

kernelParser::IdExpr2Context* kernelParser::IntDivINTVContext::idExpr2() {
  return getRuleContext<kernelParser::IdExpr2Context>(0);
}

kernelParser::IntDivINTVContext::IntDivINTVContext(IdExpr2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::IntDivINTVContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitIntDivINTV(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::IdExpr2Context* kernelParser::idExpr2() {
  IdExpr2Context *_localctx = _tracker.createInstance<IdExpr2Context>(_ctx, getState());
  enterRule(_localctx, 32, kernelParser::RuleIdExpr2);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(157);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<IdExpr2Context *>(_tracker.createInstance<kernelParser::PlusSimpleIDEXPRContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(139);
      match(kernelParser::PLUS);
      setState(140);
      simpleIdExpr();
      setState(141);
      idExpr2();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<IdExpr2Context *>(_tracker.createInstance<kernelParser::PluesINTVContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(143);
      match(kernelParser::PLUS);
      setState(144);
      match(kernelParser::IntV);
      setState(145);
      idExpr2();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<IdExpr2Context *>(_tracker.createInstance<kernelParser::MulINTVContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(146);
      match(kernelParser::MUL);
      setState(147);
      match(kernelParser::IntV);
      setState(148);
      idExpr2();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<IdExpr2Context *>(_tracker.createInstance<kernelParser::IntDivINTVContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(149);
      match(kernelParser::DIV);
      setState(150);
      match(kernelParser::DIV);
      setState(151);
      match(kernelParser::IntV);
      setState(152);
      idExpr2();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<IdExpr2Context *>(_tracker.createInstance<kernelParser::ModINTVContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(153);
      match(kernelParser::MOD);
      setState(154);
      match(kernelParser::IntV);
      setState(155);
      idExpr2();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<IdExpr2Context *>(_tracker.createInstance<kernelParser::IDEXPRNothingContext>(_localctx));
      enterOuterAlt(_localctx, 6);

      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstNumContext ------------------------------------------------------------------

kernelParser::ConstNumContext::ConstNumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::ConstNumContext::getRuleIndex() const {
  return kernelParser::RuleConstNum;
}

void kernelParser::ConstNumContext::copyFrom(ConstNumContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IntConstContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::IntConstContext::IntV() {
  return getToken(kernelParser::IntV, 0);
}

kernelParser::IntConstContext::IntConstContext(ConstNumContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::IntConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitIntConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatConstContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::FloatConstContext::FloatV() {
  return getToken(kernelParser::FloatV, 0);
}

kernelParser::FloatConstContext::FloatConstContext(ConstNumContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::FloatConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitFloatConst(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::ConstNumContext* kernelParser::constNum() {
  ConstNumContext *_localctx = _tracker.createInstance<ConstNumContext>(_ctx, getState());
  enterRule(_localctx, 34, kernelParser::RuleConstNum);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(161);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::FloatV: {
        _localctx = dynamic_cast<ConstNumContext *>(_tracker.createInstance<kernelParser::FloatConstContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(159);
        match(kernelParser::FloatV);
        break;
      }

      case kernelParser::IntV: {
        _localctx = dynamic_cast<ConstNumContext *>(_tracker.createInstance<kernelParser::IntConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(160);
        match(kernelParser::IntV);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> kernelParser::_decisionToDFA;
atn::PredictionContextCache kernelParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN kernelParser::_atn;
std::vector<uint16_t> kernelParser::_serializedATN;

std::vector<std::string> kernelParser::_ruleNames = {
  "prog", "p", "p1", "s", "lhs", "simpleRHS", "rhs", "rhs2", "tRef", "sRef", 
  "clist", "clistNode", "alist", "alistNode", "simpleIdExpr", "idExpr", 
  "idExpr2", "constNum"
};

std::vector<std::string> kernelParser::_literalNames = {
  "", "'='", "'('", "')'", "'<'", "'>'", "'['", "']'", "','", "", "", "", 
  "'+'", "'*'", "'/'", "'%'", "'-'"
};

std::vector<std::string> kernelParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "IntV", "FloatV", "Id", "PLUS", "MUL", 
  "DIV", "MOD", "MINUS", "WS"
};

dfa::Vocabulary kernelParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> kernelParser::_tokenNames;

kernelParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x13, 0xa6, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x5, 0x2, 0x2b, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x34, 0xa, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x43, 0xa, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x5, 0x9, 0x62, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x78, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 
    0x82, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x5, 0x10, 0x89, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xa0, 0xa, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xa4, 0xa, 0x13, 0x3, 0x13, 0x2, 0x2, 
    0x14, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x2, 0x2, 0x2, 0xa7, 0x2, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x6, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x35, 0x3, 0x2, 0x2, 0x2, 0xa, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x42, 0x3, 0x2, 0x2, 0x2, 0xe, 0x44, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x61, 0x3, 0x2, 0x2, 0x2, 0x12, 0x63, 0x3, 0x2, 0x2, 0x2, 0x14, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x70, 0x3, 0x2, 0x2, 0x2, 0x18, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x79, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x88, 0x3, 0x2, 0x2, 0x2, 0x20, 0x8a, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x24, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x27, 0x5, 0x4, 0x3, 0x2, 0x27, 0x28, 0x7, 0x2, 0x2, 0x3, 0x28, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2b, 0x7, 0x2, 0x2, 0x3, 0x2a, 0x26, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x2d, 0x5, 0x8, 0x5, 0x2, 0x2d, 0x2e, 0x5, 0x6, 
    0x4, 0x2, 0x2e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x5, 0x8, 0x5, 
    0x2, 0x30, 0x31, 0x5, 0x6, 0x4, 0x2, 0x31, 0x34, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0x34, 0x3, 0x2, 0x2, 0x2, 0x33, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x33, 
    0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x7, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 
    0x5, 0xa, 0x6, 0x2, 0x36, 0x37, 0x7, 0x3, 0x2, 0x2, 0x37, 0x38, 0x5, 
    0xe, 0x8, 0x2, 0x38, 0x9, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x5, 0x12, 
    0xa, 0x2, 0x3a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x4, 0x2, 
    0x2, 0x3c, 0x3d, 0x5, 0xe, 0x8, 0x2, 0x3d, 0x3e, 0x7, 0x5, 0x2, 0x2, 
    0x3e, 0x43, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x43, 0x5, 0x12, 0xa, 0x2, 0x40, 
    0x43, 0x5, 0x14, 0xb, 0x2, 0x41, 0x43, 0x5, 0x24, 0x13, 0x2, 0x42, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 
    0x2, 0x2, 0x2, 0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x45, 0x5, 0xc, 0x7, 0x2, 0x45, 0x46, 0x5, 0x10, 0x9, 
    0x2, 0x46, 0xf, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 0xe, 0x2, 0x2, 
    0x48, 0x49, 0x5, 0xc, 0x7, 0x2, 0x49, 0x4a, 0x5, 0x10, 0x9, 0x2, 0x4a, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0xf, 0x2, 0x2, 0x4c, 0x4d, 
    0x5, 0xc, 0x7, 0x2, 0x4d, 0x4e, 0x5, 0x10, 0x9, 0x2, 0x4e, 0x62, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x12, 0x2, 0x2, 0x50, 0x51, 0x5, 0xc, 
    0x7, 0x2, 0x51, 0x52, 0x5, 0x10, 0x9, 0x2, 0x52, 0x62, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x54, 0x7, 0x10, 0x2, 0x2, 0x54, 0x55, 0x5, 0xc, 0x7, 0x2, 
    0x55, 0x56, 0x5, 0x10, 0x9, 0x2, 0x56, 0x62, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x58, 0x7, 0x11, 0x2, 0x2, 0x58, 0x59, 0x5, 0xc, 0x7, 0x2, 0x59, 0x5a, 
    0x5, 0x10, 0x9, 0x2, 0x5a, 0x62, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x7, 
    0x10, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x10, 0x2, 0x2, 0x5d, 0x5e, 0x5, 0xc, 
    0x7, 0x2, 0x5e, 0x5f, 0x5, 0x10, 0x9, 0x2, 0x5f, 0x62, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x62, 0x3, 0x2, 0x2, 0x2, 0x61, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x61, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x61, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x61, 
    0x53, 0x3, 0x2, 0x2, 0x2, 0x61, 0x57, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5b, 
    0x3, 0x2, 0x2, 0x2, 0x61, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0xd, 0x2, 0x2, 0x64, 0x65, 0x7, 0x6, 
    0x2, 0x2, 0x65, 0x66, 0x5, 0x16, 0xc, 0x2, 0x66, 0x67, 0x7, 0x7, 0x2, 
    0x2, 0x67, 0x68, 0x7, 0x8, 0x2, 0x2, 0x68, 0x69, 0x5, 0x1a, 0xe, 0x2, 
    0x69, 0x6a, 0x7, 0x9, 0x2, 0x2, 0x6a, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6b, 
    0x6c, 0x7, 0xd, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x6, 0x2, 0x2, 0x6d, 0x6e, 
    0x5, 0x16, 0xc, 0x2, 0x6e, 0x6f, 0x7, 0x7, 0x2, 0x2, 0x6f, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 0xb, 0x2, 0x2, 0x71, 0x72, 0x5, 0x18, 
    0xd, 0x2, 0x72, 0x17, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 0xa, 0x2, 
    0x2, 0x74, 0x75, 0x7, 0xb, 0x2, 0x2, 0x75, 0x78, 0x5, 0x18, 0xd, 0x2, 
    0x76, 0x78, 0x3, 0x2, 0x2, 0x2, 0x77, 0x73, 0x3, 0x2, 0x2, 0x2, 0x77, 
    0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x19, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 
    0x5, 0x20, 0x11, 0x2, 0x7a, 0x7b, 0x5, 0x1c, 0xf, 0x2, 0x7b, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0xa, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x20, 
    0x11, 0x2, 0x7e, 0x7f, 0x5, 0x1c, 0xf, 0x2, 0x7f, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x80, 0x82, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7c, 0x3, 0x2, 0x2, 0x2, 
    0x81, 0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x83, 
    0x89, 0x7, 0xd, 0x2, 0x2, 0x84, 0x85, 0x7, 0x4, 0x2, 0x2, 0x85, 0x86, 
    0x5, 0x20, 0x11, 0x2, 0x86, 0x87, 0x7, 0x5, 0x2, 0x2, 0x87, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x88, 0x83, 0x3, 0x2, 0x2, 0x2, 0x88, 0x84, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x5, 0x1e, 0x10, 
    0x2, 0x8b, 0x8c, 0x5, 0x22, 0x12, 0x2, 0x8c, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x8d, 0x8e, 0x7, 0xe, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x1e, 0x10, 0x2, 0x8f, 
    0x90, 0x5, 0x22, 0x12, 0x2, 0x90, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 
    0x7, 0xe, 0x2, 0x2, 0x92, 0x93, 0x7, 0xb, 0x2, 0x2, 0x93, 0xa0, 0x5, 
    0x22, 0x12, 0x2, 0x94, 0x95, 0x7, 0xf, 0x2, 0x2, 0x95, 0x96, 0x7, 0xb, 
    0x2, 0x2, 0x96, 0xa0, 0x5, 0x22, 0x12, 0x2, 0x97, 0x98, 0x7, 0x10, 0x2, 
    0x2, 0x98, 0x99, 0x7, 0x10, 0x2, 0x2, 0x99, 0x9a, 0x7, 0xb, 0x2, 0x2, 
    0x9a, 0xa0, 0x5, 0x22, 0x12, 0x2, 0x9b, 0x9c, 0x7, 0x11, 0x2, 0x2, 0x9c, 
    0x9d, 0x7, 0xb, 0x2, 0x2, 0x9d, 0xa0, 0x5, 0x22, 0x12, 0x2, 0x9e, 0xa0, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x91, 0x3, 
    0x2, 0x2, 0x2, 0x9f, 0x94, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x97, 0x3, 0x2, 
    0x2, 0x2, 0x9f, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9e, 0x3, 0x2, 0x2, 
    0x2, 0xa0, 0x23, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa4, 0x7, 0xc, 0x2, 0x2, 
    0xa2, 0xa4, 0x7, 0xb, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa3, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x25, 0x3, 0x2, 0x2, 0x2, 0xb, 0x2a, 
    0x33, 0x42, 0x61, 0x77, 0x81, 0x88, 0x9f, 0xa3, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

kernelParser::Initializer kernelParser::_init;
