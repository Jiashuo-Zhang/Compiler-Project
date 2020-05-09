
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

    virtual antlrcpp::Any visitOneRHS(kernelParser::OneRHSContext *context) = 0;

    virtual antlrcpp::Any visitOnetRef(kernelParser::OnetRefContext *context) = 0;

    virtual antlrcpp::Any visitOnesRef(kernelParser::OnesRefContext *context) = 0;

    virtual antlrcpp::Any visitOneconstNum(kernelParser::OneconstNumContext *context) = 0;

    virtual antlrcpp::Any visitRHS(kernelParser::RHSContext *context) = 0;

    virtual antlrcpp::Any visitPlusRhs2(kernelParser::PlusRhs2Context *context) = 0;

    virtual antlrcpp::Any visitMulRhs2(kernelParser::MulRhs2Context *context) = 0;

    virtual antlrcpp::Any visitMinusRhs2(kernelParser::MinusRhs2Context *context) = 0;

    virtual antlrcpp::Any visitDivRhs2(kernelParser::DivRhs2Context *context) = 0;

    virtual antlrcpp::Any visitModRhs2(kernelParser::ModRhs2Context *context) = 0;

    virtual antlrcpp::Any visitIntDivRhs2(kernelParser::IntDivRhs2Context *context) = 0;

    virtual antlrcpp::Any visitRHS2Nothing(kernelParser::RHS2NothingContext *context) = 0;

    virtual antlrcpp::Any visitTREF(kernelParser::TREFContext *context) = 0;

    virtual antlrcpp::Any visitSREF(kernelParser::SREFContext *context) = 0;

    virtual antlrcpp::Any visitCLIST(kernelParser::CLISTContext *context) = 0;

    virtual antlrcpp::Any visitCLISTNODE(kernelParser::CLISTNODEContext *context) = 0;

    virtual antlrcpp::Any visitCLISTNODENothing(kernelParser::CLISTNODENothingContext *context) = 0;

    virtual antlrcpp::Any visitALIST(kernelParser::ALISTContext *context) = 0;

    virtual antlrcpp::Any visitALISTNODE(kernelParser::ALISTNODEContext *context) = 0;

    virtual antlrcpp::Any visitALISTNODENothing(kernelParser::ALISTNODENothingContext *context) = 0;

    virtual antlrcpp::Any visitID(kernelParser::IDContext *context) = 0;

    virtual antlrcpp::Any visitONEEXPR(kernelParser::ONEEXPRContext *context) = 0;

    virtual antlrcpp::Any visitIDEXPR(kernelParser::IDEXPRContext *context) = 0;

    virtual antlrcpp::Any visitPlusSimpleIDEXPR(kernelParser::PlusSimpleIDEXPRContext *context) = 0;

    virtual antlrcpp::Any visitPluesINTV(kernelParser::PluesINTVContext *context) = 0;

    virtual antlrcpp::Any visitMulINTV(kernelParser::MulINTVContext *context) = 0;

    virtual antlrcpp::Any visitIntDivINTV(kernelParser::IntDivINTVContext *context) = 0;

    virtual antlrcpp::Any visitModINTV(kernelParser::ModINTVContext *context) = 0;

    virtual antlrcpp::Any visitIDEXPRNothing(kernelParser::IDEXPRNothingContext *context) = 0;

    virtual antlrcpp::Any visitFloatConst(kernelParser::FloatConstContext *context) = 0;

    virtual antlrcpp::Any visitIntConst(kernelParser::IntConstContext *context) = 0;


};

