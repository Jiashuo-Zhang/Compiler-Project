
// Generated from kernel.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  kernelParser : public antlr4::Parser {
public:
  enum {
    P = 1, P1 = 2, S = 3, LHS = 4, RHS1 = 5, RHS = 6, RHS2 = 7, TRef = 8, 
    SRef = 9, CList = 10, CList1 = 11, AList = 12, AList1 = 13, IdExpr1 = 14, 
    IdExpr = 15, IdExpr2 = 16, Const = 17, IntV = 18, FloatV = 19, Id = 20, 
    WS = 21
  };

  enum {
    RuleProg = 0
  };

  kernelParser(antlr4::TokenStream *input);
  ~kernelParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *P();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();


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

