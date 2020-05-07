
// Generated from kernel.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "kernelListener.h"


/**
 * This class provides an empty implementation of kernelListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  kernelBaseListener : public kernelListener {
public:

  virtual void enterProg(kernelParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(kernelParser::ProgContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

