
// Generated from kernel.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  kernelLexer : public antlr4::Lexer {
public:
  enum {
    P = 1, P1 = 2, S = 3, LHS = 4, RHS1 = 5, RHS = 6, RHS2 = 7, TRef = 8, 
    SRef = 9, CList = 10, CList1 = 11, AList = 12, AList1 = 13, IdExpr1 = 14, 
    IdExpr = 15, IdExpr2 = 16, Const = 17, IntV = 18, FloatV = 19, Id = 20, 
    WS = 21
  };

  kernelLexer(antlr4::CharStream *input);
  ~kernelLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

