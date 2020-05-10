
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

  virtual antlrcpp::Any visitRHSconstNum(kernelParser::RHSconstNumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRHSSecondopRHS(kernelParser::RHSSecondopRHSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneRHS(kernelParser::OneRHSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRHSFirstropRHS(kernelParser::RHSFirstropRHSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRHSsRef(kernelParser::RHSsRefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRHStRef(kernelParser::RHStRefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRHSFirstCalcIsMUL(kernelParser::RHSFirstCalcIsMULContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRHSFirstCalcIsDIV(kernelParser::RHSFirstCalcIsDIVContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRHSFirstCalcMOD(kernelParser::RHSFirstCalcMODContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRHSFirstCalcINTDIV(kernelParser::RHSFirstCalcINTDIVContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRHSSecondCalcIsPLUS(kernelParser::RHSSecondCalcIsPLUSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRHSSecondCalcIsMINUS(kernelParser::RHSSecondCalcIsMINUSContext *ctx) override {
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

  virtual antlrcpp::Any visitFirstIdIntV(kernelParser::FirstIdIntVContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdId(kernelParser::IdIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSecondIdIntV(kernelParser::SecondIdIntVContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneId(kernelParser::OneIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneIdExpr(kernelParser::OneIdExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdExprCalcIsMUL(kernelParser::IdExprCalcIsMULContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdExprCalcIsINTDIV(kernelParser::IdExprCalcIsINTDIVContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdExprCalcIsMOD(kernelParser::IdExprCalcIsMODContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloatConst(kernelParser::FloatConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntConst(kernelParser::IntConstContext *ctx) override {
    return visitChildren(ctx);
  }


};

