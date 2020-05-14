
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
    match(kernelParser::T__0);
    setState(44);
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
    setState(51);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::Id: {
        _localctx = dynamic_cast<P1Context *>(_tracker.createInstance<kernelParser::VisitP1Context>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(46);
        s();
        setState(47);
        match(kernelParser::T__0);
        setState(48);
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
    setState(53);
    lhs();
    setState(54);
    match(kernelParser::T__1);
    setState(55);
    rhs(0);
   
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
    setState(57);
    tRef();
   
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

//----------------- RHSconstNumContext ------------------------------------------------------------------

kernelParser::ConstNumContext* kernelParser::RHSconstNumContext::constNum() {
  return getRuleContext<kernelParser::ConstNumContext>(0);
}

kernelParser::RHSconstNumContext::RHSconstNumContext(RhsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::RHSconstNumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitRHSconstNum(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RHSSecondopRHSContext ------------------------------------------------------------------

std::vector<kernelParser::RhsContext *> kernelParser::RHSSecondopRHSContext::rhs() {
  return getRuleContexts<kernelParser::RhsContext>();
}

kernelParser::RhsContext* kernelParser::RHSSecondopRHSContext::rhs(size_t i) {
  return getRuleContext<kernelParser::RhsContext>(i);
}

kernelParser::RhsSecondCalcContext* kernelParser::RHSSecondopRHSContext::rhsSecondCalc() {
  return getRuleContext<kernelParser::RhsSecondCalcContext>(0);
}

kernelParser::RHSSecondopRHSContext::RHSSecondopRHSContext(RhsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::RHSSecondopRHSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitRHSSecondopRHS(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OneRHSContext ------------------------------------------------------------------

kernelParser::RhsContext* kernelParser::OneRHSContext::rhs() {
  return getRuleContext<kernelParser::RhsContext>(0);
}

kernelParser::OneRHSContext::OneRHSContext(RhsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::OneRHSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitOneRHS(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RHSFirstropRHSContext ------------------------------------------------------------------

std::vector<kernelParser::RhsContext *> kernelParser::RHSFirstropRHSContext::rhs() {
  return getRuleContexts<kernelParser::RhsContext>();
}

kernelParser::RhsContext* kernelParser::RHSFirstropRHSContext::rhs(size_t i) {
  return getRuleContext<kernelParser::RhsContext>(i);
}

kernelParser::RhsFirstCalcContext* kernelParser::RHSFirstropRHSContext::rhsFirstCalc() {
  return getRuleContext<kernelParser::RhsFirstCalcContext>(0);
}

kernelParser::RHSFirstropRHSContext::RHSFirstropRHSContext(RhsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::RHSFirstropRHSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitRHSFirstropRHS(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RHSsRefContext ------------------------------------------------------------------

kernelParser::SRefContext* kernelParser::RHSsRefContext::sRef() {
  return getRuleContext<kernelParser::SRefContext>(0);
}

kernelParser::RHSsRefContext::RHSsRefContext(RhsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::RHSsRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitRHSsRef(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RHStRefContext ------------------------------------------------------------------

kernelParser::TRefContext* kernelParser::RHStRefContext::tRef() {
  return getRuleContext<kernelParser::TRefContext>(0);
}

kernelParser::RHStRefContext::RHStRefContext(RhsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::RHStRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitRHStRef(this);
  else
    return visitor->visitChildren(this);
}

kernelParser::RhsContext* kernelParser::rhs() {
   return rhs(0);
}

kernelParser::RhsContext* kernelParser::rhs(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  kernelParser::RhsContext *_localctx = _tracker.createInstance<RhsContext>(_ctx, parentState);
  kernelParser::RhsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, kernelParser::RuleRhs, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(67);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<RHStRefContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(60);
      tRef();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<RHSsRefContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(61);
      sRef();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<RHSconstNumContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(62);
      constNum();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<OneRHSContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(63);
      match(kernelParser::T__2);
      setState(64);
      rhs(0);
      setState(65);
      match(kernelParser::T__3);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(79);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(77);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<RHSFirstropRHSContext>(_tracker.createInstance<RhsContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleRhs);
          setState(69);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(70);
          rhsFirstCalc();
          setState(71);
          rhs(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<RHSSecondopRHSContext>(_tracker.createInstance<RhsContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleRhs);
          setState(73);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(74);
          rhsSecondCalc();
          setState(75);
          rhs(6);
          break;
        }

        } 
      }
      setState(81);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RhsFirstCalcContext ------------------------------------------------------------------

kernelParser::RhsFirstCalcContext::RhsFirstCalcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::RhsFirstCalcContext::getRuleIndex() const {
  return kernelParser::RuleRhsFirstCalc;
}

void kernelParser::RhsFirstCalcContext::copyFrom(RhsFirstCalcContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RHSFirstCalcIsDIVContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::RHSFirstCalcIsDIVContext::DIV() {
  return getToken(kernelParser::DIV, 0);
}

kernelParser::RHSFirstCalcIsDIVContext::RHSFirstCalcIsDIVContext(RhsFirstCalcContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::RHSFirstCalcIsDIVContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitRHSFirstCalcIsDIV(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RHSFirstCalcINTDIVContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::RHSFirstCalcINTDIVContext::INTDIV() {
  return getToken(kernelParser::INTDIV, 0);
}

kernelParser::RHSFirstCalcINTDIVContext::RHSFirstCalcINTDIVContext(RhsFirstCalcContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::RHSFirstCalcINTDIVContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitRHSFirstCalcINTDIV(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RHSFirstCalcIsMULContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::RHSFirstCalcIsMULContext::MUL() {
  return getToken(kernelParser::MUL, 0);
}

kernelParser::RHSFirstCalcIsMULContext::RHSFirstCalcIsMULContext(RhsFirstCalcContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::RHSFirstCalcIsMULContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitRHSFirstCalcIsMUL(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RHSFirstCalcMODContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::RHSFirstCalcMODContext::MOD() {
  return getToken(kernelParser::MOD, 0);
}

kernelParser::RHSFirstCalcMODContext::RHSFirstCalcMODContext(RhsFirstCalcContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::RHSFirstCalcMODContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitRHSFirstCalcMOD(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::RhsFirstCalcContext* kernelParser::rhsFirstCalc() {
  RhsFirstCalcContext *_localctx = _tracker.createInstance<RhsFirstCalcContext>(_ctx, getState());
  enterRule(_localctx, 12, kernelParser::RuleRhsFirstCalc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(86);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::MUL: {
        _localctx = dynamic_cast<RhsFirstCalcContext *>(_tracker.createInstance<kernelParser::RHSFirstCalcIsMULContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(82);
        match(kernelParser::MUL);
        break;
      }

      case kernelParser::DIV: {
        _localctx = dynamic_cast<RhsFirstCalcContext *>(_tracker.createInstance<kernelParser::RHSFirstCalcIsDIVContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(83);
        match(kernelParser::DIV);
        break;
      }

      case kernelParser::MOD: {
        _localctx = dynamic_cast<RhsFirstCalcContext *>(_tracker.createInstance<kernelParser::RHSFirstCalcMODContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(84);
        match(kernelParser::MOD);
        break;
      }

      case kernelParser::INTDIV: {
        _localctx = dynamic_cast<RhsFirstCalcContext *>(_tracker.createInstance<kernelParser::RHSFirstCalcINTDIVContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(85);
        match(kernelParser::INTDIV);
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

//----------------- RhsSecondCalcContext ------------------------------------------------------------------

kernelParser::RhsSecondCalcContext::RhsSecondCalcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::RhsSecondCalcContext::getRuleIndex() const {
  return kernelParser::RuleRhsSecondCalc;
}

void kernelParser::RhsSecondCalcContext::copyFrom(RhsSecondCalcContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RHSSecondCalcIsPLUSContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::RHSSecondCalcIsPLUSContext::PLUS() {
  return getToken(kernelParser::PLUS, 0);
}

kernelParser::RHSSecondCalcIsPLUSContext::RHSSecondCalcIsPLUSContext(RhsSecondCalcContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::RHSSecondCalcIsPLUSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitRHSSecondCalcIsPLUS(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RHSSecondCalcIsMINUSContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::RHSSecondCalcIsMINUSContext::MINUS() {
  return getToken(kernelParser::MINUS, 0);
}

kernelParser::RHSSecondCalcIsMINUSContext::RHSSecondCalcIsMINUSContext(RhsSecondCalcContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::RHSSecondCalcIsMINUSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitRHSSecondCalcIsMINUS(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::RhsSecondCalcContext* kernelParser::rhsSecondCalc() {
  RhsSecondCalcContext *_localctx = _tracker.createInstance<RhsSecondCalcContext>(_ctx, getState());
  enterRule(_localctx, 14, kernelParser::RuleRhsSecondCalc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(90);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::PLUS: {
        _localctx = dynamic_cast<RhsSecondCalcContext *>(_tracker.createInstance<kernelParser::RHSSecondCalcIsPLUSContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(88);
        match(kernelParser::PLUS);
        break;
      }

      case kernelParser::MINUS: {
        _localctx = dynamic_cast<RhsSecondCalcContext *>(_tracker.createInstance<kernelParser::RHSSecondCalcIsMINUSContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(89);
        match(kernelParser::MINUS);
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
    setState(92);
    match(kernelParser::Id);
    setState(93);
    match(kernelParser::T__4);
    setState(94);
    clist();
    setState(95);
    match(kernelParser::T__5);
    setState(96);
    match(kernelParser::T__6);
    setState(97);
    alist();
    setState(98);
    match(kernelParser::T__7);
   
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
    setState(100);
    match(kernelParser::Id);
    setState(101);
    match(kernelParser::T__4);
    setState(102);
    clist();
    setState(103);
    match(kernelParser::T__5);
   
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
    setState(105);
    match(kernelParser::IntV);
    setState(106);
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
    setState(112);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::T__8: {
        _localctx = dynamic_cast<ClistNodeContext *>(_tracker.createInstance<kernelParser::CLISTNODEContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(108);
        match(kernelParser::T__8);
        setState(109);
        match(kernelParser::IntV);
        setState(110);
        clistNode();
        break;
      }

      case kernelParser::T__5: {
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
    setState(114);
    idExpr(0);
    setState(115);
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
    setState(122);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::T__8: {
        _localctx = dynamic_cast<AlistNodeContext *>(_tracker.createInstance<kernelParser::ALISTNODEContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(117);
        match(kernelParser::T__8);
        setState(118);
        idExpr(0);
        setState(119);
        alistNode();
        break;
      }

      case kernelParser::T__7: {
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

//----------------- FirstIdIntVContext ------------------------------------------------------------------

kernelParser::IdExprContext* kernelParser::FirstIdIntVContext::idExpr() {
  return getRuleContext<kernelParser::IdExprContext>(0);
}

kernelParser::IdExprFirstCalcContext* kernelParser::FirstIdIntVContext::idExprFirstCalc() {
  return getRuleContext<kernelParser::IdExprFirstCalcContext>(0);
}

tree::TerminalNode* kernelParser::FirstIdIntVContext::IntV() {
  return getToken(kernelParser::IntV, 0);
}

kernelParser::FirstIdIntVContext::FirstIdIntVContext(IdExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::FirstIdIntVContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitFirstIdIntV(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdIdContext ------------------------------------------------------------------

std::vector<kernelParser::IdExprContext *> kernelParser::IdIdContext::idExpr() {
  return getRuleContexts<kernelParser::IdExprContext>();
}

kernelParser::IdExprContext* kernelParser::IdIdContext::idExpr(size_t i) {
  return getRuleContext<kernelParser::IdExprContext>(i);
}

tree::TerminalNode* kernelParser::IdIdContext::PLUS() {
  return getToken(kernelParser::PLUS, 0);
}

kernelParser::IdIdContext::IdIdContext(IdExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::IdIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitIdId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SecondIdIntVContext ------------------------------------------------------------------

kernelParser::IdExprContext* kernelParser::SecondIdIntVContext::idExpr() {
  return getRuleContext<kernelParser::IdExprContext>(0);
}

kernelParser::IdExprSecondCalcContext* kernelParser::SecondIdIntVContext::idExprSecondCalc() {
  return getRuleContext<kernelParser::IdExprSecondCalcContext>(0);
}

tree::TerminalNode* kernelParser::SecondIdIntVContext::IntV() {
  return getToken(kernelParser::IntV, 0);
}

kernelParser::SecondIdIntVContext::SecondIdIntVContext(IdExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::SecondIdIntVContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitSecondIdIntV(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OneIdContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::OneIdContext::Id() {
  return getToken(kernelParser::Id, 0);
}

kernelParser::OneIdContext::OneIdContext(IdExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::OneIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitOneId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OneIdExprContext ------------------------------------------------------------------

kernelParser::IdExprContext* kernelParser::OneIdExprContext::idExpr() {
  return getRuleContext<kernelParser::IdExprContext>(0);
}

kernelParser::OneIdExprContext::OneIdExprContext(IdExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::OneIdExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitOneIdExpr(this);
  else
    return visitor->visitChildren(this);
}

kernelParser::IdExprContext* kernelParser::idExpr() {
   return idExpr(0);
}

kernelParser::IdExprContext* kernelParser::idExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  kernelParser::IdExprContext *_localctx = _tracker.createInstance<IdExprContext>(_ctx, parentState);
  kernelParser::IdExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, kernelParser::RuleIdExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(130);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::Id: {
        _localctx = _tracker.createInstance<OneIdContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(125);
        match(kernelParser::Id);
        break;
      }

      case kernelParser::T__2: {
        _localctx = _tracker.createInstance<OneIdExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(126);
        match(kernelParser::T__2);
        setState(127);
        idExpr(0);
        setState(128);
        match(kernelParser::T__3);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(145);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(143);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<IdIdContext>(_tracker.createInstance<IdExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleIdExpr);
          setState(132);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(133);
          match(kernelParser::PLUS);
          setState(134);
          idExpr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<FirstIdIntVContext>(_tracker.createInstance<IdExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleIdExpr);
          setState(135);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(136);
          idExprFirstCalc();
          setState(137);
          match(kernelParser::IntV);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<SecondIdIntVContext>(_tracker.createInstance<IdExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleIdExpr);
          setState(139);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(140);
          idExprSecondCalc();
          setState(141);
          match(kernelParser::IntV);
          break;
        }

        } 
      }
      setState(147);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IdExprFirstCalcContext ------------------------------------------------------------------

kernelParser::IdExprFirstCalcContext::IdExprFirstCalcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::IdExprFirstCalcContext::getRuleIndex() const {
  return kernelParser::RuleIdExprFirstCalc;
}

void kernelParser::IdExprFirstCalcContext::copyFrom(IdExprFirstCalcContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IdExprCalcIsMODContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::IdExprCalcIsMODContext::MOD() {
  return getToken(kernelParser::MOD, 0);
}

kernelParser::IdExprCalcIsMODContext::IdExprCalcIsMODContext(IdExprFirstCalcContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::IdExprCalcIsMODContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitIdExprCalcIsMOD(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdExprCalcIsMULContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::IdExprCalcIsMULContext::MUL() {
  return getToken(kernelParser::MUL, 0);
}

kernelParser::IdExprCalcIsMULContext::IdExprCalcIsMULContext(IdExprFirstCalcContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::IdExprCalcIsMULContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitIdExprCalcIsMUL(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdExprCalcIsINTDIVContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::IdExprCalcIsINTDIVContext::INTDIV() {
  return getToken(kernelParser::INTDIV, 0);
}

kernelParser::IdExprCalcIsINTDIVContext::IdExprCalcIsINTDIVContext(IdExprFirstCalcContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::IdExprCalcIsINTDIVContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitIdExprCalcIsINTDIV(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::IdExprFirstCalcContext* kernelParser::idExprFirstCalc() {
  IdExprFirstCalcContext *_localctx = _tracker.createInstance<IdExprFirstCalcContext>(_ctx, getState());
  enterRule(_localctx, 30, kernelParser::RuleIdExprFirstCalc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(151);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::MUL: {
        _localctx = dynamic_cast<IdExprFirstCalcContext *>(_tracker.createInstance<kernelParser::IdExprCalcIsMULContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(148);
        match(kernelParser::MUL);
        break;
      }

      case kernelParser::INTDIV: {
        _localctx = dynamic_cast<IdExprFirstCalcContext *>(_tracker.createInstance<kernelParser::IdExprCalcIsINTDIVContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(149);
        match(kernelParser::INTDIV);
        break;
      }

      case kernelParser::MOD: {
        _localctx = dynamic_cast<IdExprFirstCalcContext *>(_tracker.createInstance<kernelParser::IdExprCalcIsMODContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(150);
        match(kernelParser::MOD);
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

//----------------- IdExprSecondCalcContext ------------------------------------------------------------------

kernelParser::IdExprSecondCalcContext::IdExprSecondCalcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t kernelParser::IdExprSecondCalcContext::getRuleIndex() const {
  return kernelParser::RuleIdExprSecondCalc;
}

void kernelParser::IdExprSecondCalcContext::copyFrom(IdExprSecondCalcContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IdSecondCalcIsMINUSContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::IdSecondCalcIsMINUSContext::MINUS() {
  return getToken(kernelParser::MINUS, 0);
}

kernelParser::IdSecondCalcIsMINUSContext::IdSecondCalcIsMINUSContext(IdExprSecondCalcContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::IdSecondCalcIsMINUSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitIdSecondCalcIsMINUS(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdSecondCalcIsPLUSContext ------------------------------------------------------------------

tree::TerminalNode* kernelParser::IdSecondCalcIsPLUSContext::PLUS() {
  return getToken(kernelParser::PLUS, 0);
}

kernelParser::IdSecondCalcIsPLUSContext::IdSecondCalcIsPLUSContext(IdExprSecondCalcContext *ctx) { copyFrom(ctx); }


antlrcpp::Any kernelParser::IdSecondCalcIsPLUSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitIdSecondCalcIsPLUS(this);
  else
    return visitor->visitChildren(this);
}
kernelParser::IdExprSecondCalcContext* kernelParser::idExprSecondCalc() {
  IdExprSecondCalcContext *_localctx = _tracker.createInstance<IdExprSecondCalcContext>(_ctx, getState());
  enterRule(_localctx, 32, kernelParser::RuleIdExprSecondCalc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(155);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::PLUS: {
        _localctx = dynamic_cast<IdExprSecondCalcContext *>(_tracker.createInstance<kernelParser::IdSecondCalcIsPLUSContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(153);
        match(kernelParser::PLUS);
        break;
      }

      case kernelParser::MINUS: {
        _localctx = dynamic_cast<IdExprSecondCalcContext *>(_tracker.createInstance<kernelParser::IdSecondCalcIsMINUSContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(154);
        match(kernelParser::MINUS);
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
    setState(159);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case kernelParser::FloatV: {
        _localctx = dynamic_cast<ConstNumContext *>(_tracker.createInstance<kernelParser::FloatConstContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(157);
        match(kernelParser::FloatV);
        break;
      }

      case kernelParser::IntV: {
        _localctx = dynamic_cast<ConstNumContext *>(_tracker.createInstance<kernelParser::IntConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(158);
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

bool kernelParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 5: return rhsSempred(dynamic_cast<RhsContext *>(context), predicateIndex);
    case 14: return idExprSempred(dynamic_cast<IdExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool kernelParser::rhsSempred(RhsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool kernelParser::idExprSempred(IdExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 3);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> kernelParser::_decisionToDFA;
atn::PredictionContextCache kernelParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN kernelParser::_atn;
std::vector<uint16_t> kernelParser::_serializedATN;

std::vector<std::string> kernelParser::_ruleNames = {
  "prog", "p", "p1", "s", "lhs", "rhs", "rhsFirstCalc", "rhsSecondCalc", 
  "tRef", "sRef", "clist", "clistNode", "alist", "alistNode", "idExpr", 
  "idExprFirstCalc", "idExprSecondCalc", "constNum"
};

std::vector<std::string> kernelParser::_literalNames = {
  "", "';'", "'='", "'('", "')'", "'<'", "'>'", "'['", "']'", "','", "", 
  "", "", "'+'", "'*'", "", "'/'", "'%'", "'-'"
};

std::vector<std::string> kernelParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "IntV", "FloatV", "Id", "PLUS", 
  "MUL", "INTDIV", "DIV", "MOD", "MINUS", "WS"
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
    0x3, 0x15, 0xa4, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x5, 0x2, 0x2b, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x36, 0xa, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0x46, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x50, 0xa, 0x7, 0xc, 
    0x7, 0xe, 0x7, 0x53, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0x59, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x5d, 0xa, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 
    0x73, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x7d, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x85, 0xa, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x92, 0xa, 
    0x10, 0xc, 0x10, 0xe, 0x10, 0x95, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x5, 0x11, 0x9a, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x9e, 
    0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xa2, 0xa, 0x13, 0x3, 0x13, 
    0x2, 0x4, 0xc, 0x1e, 0x14, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x2, 0x2, 
    0x2, 0xa6, 0x2, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2c, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x35, 0x3, 0x2, 0x2, 0x2, 0x8, 0x37, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x45, 0x3, 0x2, 0x2, 0x2, 0xe, 0x58, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x12, 0x5e, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x66, 0x3, 0x2, 0x2, 0x2, 0x16, 0x6b, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x72, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x74, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x84, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x99, 0x3, 0x2, 0x2, 0x2, 0x22, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xa1, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x5, 0x4, 0x3, 0x2, 0x27, 0x28, 
    0x7, 0x2, 0x2, 0x3, 0x28, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2b, 0x7, 
    0x2, 0x2, 0x3, 0x2a, 0x26, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x2b, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x5, 0x8, 0x5, 
    0x2, 0x2d, 0x2e, 0x7, 0x3, 0x2, 0x2, 0x2e, 0x2f, 0x5, 0x6, 0x4, 0x2, 
    0x2f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x5, 0x8, 0x5, 0x2, 0x31, 
    0x32, 0x7, 0x3, 0x2, 0x2, 0x32, 0x33, 0x5, 0x6, 0x4, 0x2, 0x33, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x30, 0x3, 
    0x2, 0x2, 0x2, 0x35, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x37, 0x38, 0x5, 0xa, 0x6, 0x2, 0x38, 0x39, 0x7, 0x4, 0x2, 
    0x2, 0x39, 0x3a, 0x5, 0xc, 0x7, 0x2, 0x3a, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x3b, 0x3c, 0x5, 0x12, 0xa, 0x2, 0x3c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3d, 
    0x3e, 0x8, 0x7, 0x1, 0x2, 0x3e, 0x46, 0x5, 0x12, 0xa, 0x2, 0x3f, 0x46, 
    0x5, 0x14, 0xb, 0x2, 0x40, 0x46, 0x5, 0x24, 0x13, 0x2, 0x41, 0x42, 0x7, 
    0x5, 0x2, 0x2, 0x42, 0x43, 0x5, 0xc, 0x7, 0x2, 0x43, 0x44, 0x7, 0x6, 
    0x2, 0x2, 0x44, 0x46, 0x3, 0x2, 0x2, 0x2, 0x45, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x45, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x45, 0x40, 0x3, 0x2, 0x2, 0x2, 
    0x45, 0x41, 0x3, 0x2, 0x2, 0x2, 0x46, 0x51, 0x3, 0x2, 0x2, 0x2, 0x47, 
    0x48, 0xc, 0x8, 0x2, 0x2, 0x48, 0x49, 0x5, 0xe, 0x8, 0x2, 0x49, 0x4a, 
    0x5, 0xc, 0x7, 0x9, 0x4a, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0xc, 
    0x7, 0x2, 0x2, 0x4c, 0x4d, 0x5, 0x10, 0x9, 0x2, 0x4d, 0x4e, 0x5, 0xc, 
    0x7, 0x8, 0x4e, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x47, 0x3, 0x2, 0x2, 
    0x2, 0x4f, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x50, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 0x2, 0x2, 0x2, 0x52, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 0x54, 0x59, 
    0x7, 0x10, 0x2, 0x2, 0x55, 0x59, 0x7, 0x12, 0x2, 0x2, 0x56, 0x59, 0x7, 
    0x13, 0x2, 0x2, 0x57, 0x59, 0x7, 0x11, 0x2, 0x2, 0x58, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x5d, 0x7, 0xf, 0x2, 0x2, 0x5b, 0x5d, 0x7, 0x14, 0x2, 0x2, 0x5c, 
    0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0xe, 0x2, 0x2, 0x5f, 0x60, 0x7, 
    0x7, 0x2, 0x2, 0x60, 0x61, 0x5, 0x16, 0xc, 0x2, 0x61, 0x62, 0x7, 0x8, 
    0x2, 0x2, 0x62, 0x63, 0x7, 0x9, 0x2, 0x2, 0x63, 0x64, 0x5, 0x1a, 0xe, 
    0x2, 0x64, 0x65, 0x7, 0xa, 0x2, 0x2, 0x65, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x66, 0x67, 0x7, 0xe, 0x2, 0x2, 0x67, 0x68, 0x7, 0x7, 0x2, 0x2, 0x68, 
    0x69, 0x5, 0x16, 0xc, 0x2, 0x69, 0x6a, 0x7, 0x8, 0x2, 0x2, 0x6a, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0xc, 0x2, 0x2, 0x6c, 0x6d, 0x5, 
    0x18, 0xd, 0x2, 0x6d, 0x17, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0xb, 
    0x2, 0x2, 0x6f, 0x70, 0x7, 0xc, 0x2, 0x2, 0x70, 0x73, 0x5, 0x18, 0xd, 
    0x2, 0x71, 0x73, 0x3, 0x2, 0x2, 0x2, 0x72, 0x6e, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 0x19, 0x3, 0x2, 0x2, 0x2, 0x74, 
    0x75, 0x5, 0x1e, 0x10, 0x2, 0x75, 0x76, 0x5, 0x1c, 0xf, 0x2, 0x76, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0xb, 0x2, 0x2, 0x78, 0x79, 0x5, 
    0x1e, 0x10, 0x2, 0x79, 0x7a, 0x5, 0x1c, 0xf, 0x2, 0x7a, 0x7d, 0x3, 0x2, 
    0x2, 0x2, 0x7b, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x7c, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x7f, 0x8, 0x10, 0x1, 0x2, 0x7f, 0x85, 0x7, 0xe, 0x2, 0x2, 0x80, 
    0x81, 0x7, 0x5, 0x2, 0x2, 0x81, 0x82, 0x5, 0x1e, 0x10, 0x2, 0x82, 0x83, 
    0x7, 0x6, 0x2, 0x2, 0x83, 0x85, 0x3, 0x2, 0x2, 0x2, 0x84, 0x7e, 0x3, 
    0x2, 0x2, 0x2, 0x84, 0x80, 0x3, 0x2, 0x2, 0x2, 0x85, 0x93, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x87, 0xc, 0x5, 0x2, 0x2, 0x87, 0x88, 0x7, 0xf, 0x2, 
    0x2, 0x88, 0x92, 0x5, 0x1e, 0x10, 0x6, 0x89, 0x8a, 0xc, 0x7, 0x2, 0x2, 
    0x8a, 0x8b, 0x5, 0x20, 0x11, 0x2, 0x8b, 0x8c, 0x7, 0xc, 0x2, 0x2, 0x8c, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0xc, 0x6, 0x2, 0x2, 0x8e, 0x8f, 
    0x5, 0x22, 0x12, 0x2, 0x8f, 0x90, 0x7, 0xc, 0x2, 0x2, 0x90, 0x92, 0x3, 
    0x2, 0x2, 0x2, 0x91, 0x86, 0x3, 0x2, 0x2, 0x2, 0x91, 0x89, 0x3, 0x2, 
    0x2, 0x2, 0x91, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x92, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 
    0x94, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0x9a, 0x7, 0x10, 0x2, 0x2, 0x97, 0x9a, 0x7, 0x11, 0x2, 0x2, 0x98, 0x9a, 
    0x7, 0x13, 0x2, 0x2, 0x99, 0x96, 0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x9b, 0x9e, 0x7, 0xf, 0x2, 0x2, 0x9c, 0x9e, 0x7, 0x14, 0x2, 
    0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9c, 0x3, 0x2, 0x2, 0x2, 
    0x9e, 0x23, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa2, 0x7, 0xd, 0x2, 0x2, 0xa0, 
    0xa2, 0x7, 0xc, 0x2, 0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa0, 
    0x3, 0x2, 0x2, 0x2, 0xa2, 0x25, 0x3, 0x2, 0x2, 0x2, 0x11, 0x2a, 0x35, 
    0x45, 0x4f, 0x51, 0x58, 0x5c, 0x72, 0x7c, 0x84, 0x91, 0x93, 0x99, 0x9d, 
    0xa1, 
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
