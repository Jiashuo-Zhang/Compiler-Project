
// Generated from kernel.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "kernelParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by kernelParser.
 */
class  kernelListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(kernelParser::ProgContext *ctx) = 0;
  virtual void exitProg(kernelParser::ProgContext *ctx) = 0;


};

