
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

  virtual antlrcpp::Any visitStart(kernelParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnd(kernelParser::EndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVisitP(kernelParser::VisitPContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVisitP1(kernelParser::VisitP1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitP1Nothing(kernelParser::P1NothingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVisitS(kernelParser::VisitSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLHS(kernelParser::LHSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneRHS(kernelParser::OneRHSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOnetRef(kernelParser::OnetRefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOnesRef(kernelParser::OnesRefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneconstNum(kernelParser::OneconstNumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRHS(kernelParser::RHSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPlusRhs2(kernelParser::PlusRhs2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulRhs2(kernelParser::MulRhs2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMinusRhs2(kernelParser::MinusRhs2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDivRhs2(kernelParser::DivRhs2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModRhs2(kernelParser::ModRhs2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntDivRhs2(kernelParser::IntDivRhs2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRHS2Nothing(kernelParser::RHS2NothingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTREF(kernelParser::TREFContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSREF(kernelParser::SREFContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCLIST(kernelParser::CLISTContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCLISTNODE(kernelParser::CLISTNODEContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCLISTNODENothing(kernelParser::CLISTNODENothingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitALIST(kernelParser::ALISTContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitALISTNODE(kernelParser::ALISTNODEContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitALISTNODENothing(kernelParser::ALISTNODENothingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitID(kernelParser::IDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitONEEXPR(kernelParser::ONEEXPRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIDEXPR(kernelParser::IDEXPRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPlusSimpleIDEXPR(kernelParser::PlusSimpleIDEXPRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPluesINTV(kernelParser::PluesINTVContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulINTV(kernelParser::MulINTVContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntDivINTV(kernelParser::IntDivINTVContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModINTV(kernelParser::ModINTVContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIDEXPRNothing(kernelParser::IDEXPRNothingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloatConst(kernelParser::FloatConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntConst(kernelParser::IntConstContext *ctx) override {
    return visitChildren(ctx);
  }


};

