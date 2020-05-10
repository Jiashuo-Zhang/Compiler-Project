
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
    virtual antlrcpp::Any visitStart(kernelParser::StartContext *context) = 0;

    virtual antlrcpp::Any visitEnd(kernelParser::EndContext *context) = 0;

    virtual antlrcpp::Any visitVisitP(kernelParser::VisitPContext *context) = 0;

    virtual antlrcpp::Any visitVisitP1(kernelParser::VisitP1Context *context) = 0;

    virtual antlrcpp::Any visitP1Nothing(kernelParser::P1NothingContext *context) = 0;

    virtual antlrcpp::Any visitVisitS(kernelParser::VisitSContext *context) = 0;

    virtual antlrcpp::Any visitLHS(kernelParser::LHSContext *context) = 0;

    virtual antlrcpp::Any visitRHSconstNum(kernelParser::RHSconstNumContext *context) = 0;

    virtual antlrcpp::Any visitRHSSecondopRHS(kernelParser::RHSSecondopRHSContext *context) = 0;

    virtual antlrcpp::Any visitOneRHS(kernelParser::OneRHSContext *context) = 0;

    virtual antlrcpp::Any visitRHSFirstropRHS(kernelParser::RHSFirstropRHSContext *context) = 0;

    virtual antlrcpp::Any visitRHSsRef(kernelParser::RHSsRefContext *context) = 0;

    virtual antlrcpp::Any visitRHStRef(kernelParser::RHStRefContext *context) = 0;

    virtual antlrcpp::Any visitRHSFirstCalcIsMUL(kernelParser::RHSFirstCalcIsMULContext *context) = 0;

    virtual antlrcpp::Any visitRHSFirstCalcIsDIV(kernelParser::RHSFirstCalcIsDIVContext *context) = 0;

    virtual antlrcpp::Any visitRHSFirstCalcMOD(kernelParser::RHSFirstCalcMODContext *context) = 0;

    virtual antlrcpp::Any visitRHSFirstCalcINTDIV(kernelParser::RHSFirstCalcINTDIVContext *context) = 0;

    virtual antlrcpp::Any visitRHSSecondCalcIsPLUS(kernelParser::RHSSecondCalcIsPLUSContext *context) = 0;

    virtual antlrcpp::Any visitRHSSecondCalcIsMINUS(kernelParser::RHSSecondCalcIsMINUSContext *context) = 0;

    virtual antlrcpp::Any visitTREF(kernelParser::TREFContext *context) = 0;

    virtual antlrcpp::Any visitSREF(kernelParser::SREFContext *context) = 0;

    virtual antlrcpp::Any visitCLIST(kernelParser::CLISTContext *context) = 0;

    virtual antlrcpp::Any visitCLISTNODE(kernelParser::CLISTNODEContext *context) = 0;

    virtual antlrcpp::Any visitCLISTNODENothing(kernelParser::CLISTNODENothingContext *context) = 0;

    virtual antlrcpp::Any visitALIST(kernelParser::ALISTContext *context) = 0;

    virtual antlrcpp::Any visitALISTNODE(kernelParser::ALISTNODEContext *context) = 0;

    virtual antlrcpp::Any visitALISTNODENothing(kernelParser::ALISTNODENothingContext *context) = 0;

    virtual antlrcpp::Any visitFirstIdIntV(kernelParser::FirstIdIntVContext *context) = 0;

    virtual antlrcpp::Any visitIdId(kernelParser::IdIdContext *context) = 0;

    virtual antlrcpp::Any visitSecondIdIntV(kernelParser::SecondIdIntVContext *context) = 0;

    virtual antlrcpp::Any visitOneId(kernelParser::OneIdContext *context) = 0;

    virtual antlrcpp::Any visitOneIdExpr(kernelParser::OneIdExprContext *context) = 0;

    virtual antlrcpp::Any visitIdExprCalcIsMUL(kernelParser::IdExprCalcIsMULContext *context) = 0;

    virtual antlrcpp::Any visitIdExprCalcIsINTDIV(kernelParser::IdExprCalcIsINTDIVContext *context) = 0;

    virtual antlrcpp::Any visitIdExprCalcIsMOD(kernelParser::IdExprCalcIsMODContext *context) = 0;

    virtual antlrcpp::Any visitIdSecondCalcIsPLUS(kernelParser::IdSecondCalcIsPLUSContext *context) = 0;

    virtual antlrcpp::Any visitIdSecondCalcIsMINUS(kernelParser::IdSecondCalcIsMINUSContext *context) = 0;

    virtual antlrcpp::Any visitFloatConst(kernelParser::FloatConstContext *context) = 0;

    virtual antlrcpp::Any visitIntConst(kernelParser::IntConstContext *context) = 0;


};

