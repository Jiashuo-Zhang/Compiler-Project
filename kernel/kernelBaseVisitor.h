
// Generated from kernel.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "kernelVisitor.h"


/**
 * This class provides an empty implementation of kernelVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  kernelBaseVisitor : public kernelVisitor {
public:

  virtual antlrcpp::Any visitProg(kernelParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }


};

