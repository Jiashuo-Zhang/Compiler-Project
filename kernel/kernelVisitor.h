
// Generated from kernel.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "kernelParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by kernelParser.
 */
class  kernelVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by kernelParser.
   */
    virtual antlrcpp::Any visitProg(kernelParser::ProgContext *context) = 0;


};

