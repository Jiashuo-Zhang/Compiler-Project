
// Generated from kernel.g4 by ANTLR 4.7.2


#include "kernelListener.h"
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

tree::TerminalNode* kernelParser::ProgContext::P() {
  return getToken(kernelParser::P, 0);
}

tree::TerminalNode* kernelParser::ProgContext::EOF() {
  return getToken(kernelParser::EOF, 0);
}


size_t kernelParser::ProgContext::getRuleIndex() const {
  return kernelParser::RuleProg;
}

void kernelParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kernelListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void kernelParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kernelListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


antlrcpp::Any kernelParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<kernelVisitor*>(visitor))
    return parserVisitor->visitProg(this);
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
    enterOuterAlt(_localctx, 1);
    setState(2);
    match(kernelParser::P);
    setState(3);
    match(kernelParser::EOF);
   
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
  "prog"
};

std::vector<std::string> kernelParser::_literalNames = {
};

std::vector<std::string> kernelParser::_symbolicNames = {
  "", "P", "P1", "S", "LHS", "RHS1", "RHS", "RHS2", "TRef", "SRef", "CList", 
  "CList1", "AList", "AList1", "IdExpr1", "IdExpr", "IdExpr2", "Const", 
  "IntV", "FloatV", "Id", "WS"
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
    0x3, 0x17, 0x8, 0x4, 0x2, 0x9, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x2, 0x2, 0x3, 0x2, 0x2, 0x2, 0x2, 0x6, 0x2, 0x4, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x5, 0x7, 0x3, 0x2, 0x2, 0x5, 0x6, 0x7, 0x2, 0x2, 0x3, 0x6, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 
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
