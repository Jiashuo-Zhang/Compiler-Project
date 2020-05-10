#include <iostream>
#include <string>
#include <vector>
#include "antlr4-runtime.h"
#include "kernelBaseVisitor.h"

#include "../include/IR.h"
#include "../include/IRMutator.h"
#include "../include/IRVisitor.h"
#include "../include/IRPrinter.h"
#include "../include/type.h"
using namespace Boost::Internal;
using namespace std;

class Kernel2IRVisitor : public kernelBaseVisitor
{
    antlrcpp::Any visitStart(kernelParser::StartContext *ctx) override {
        cout<<"############## Begin Kernel2IRVisitor ! ############"<<endl;
        antlrcpp::Any p = visit(ctx->p());
        cout<<"############## Kernel2IRVisitor Finished! ##########"<<endl;
        return p;
    }
    
    antlrcpp::Any visitEnd(kernelParser::EndContext *ctx) override {
      
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitVisitP(kernelParser::VisitPContext *ctx) override {
        vector<Stmt> StmtList;
        StmtList.push_back(visit(ctx->s()));////s should return stmt
        vector<Stmt> LeftList;
        LeftList=visit(ctx->p1()).as<vector<Stmt>>();
        for(vector<Stmt>::iterator it=LeftList.begin();it!=LeftList.end();it++)
        {
            StmtList.push_back(*it);
        }
        return StmtList;
    }
    
    antlrcpp::Any visitVisitP1(kernelParser::VisitP1Context *ctx) override {
        vector<Stmt> StmtList;
        StmtList.push_back(visit(ctx->s()));////s should return stmt
        vector<Stmt> LeftList;
        LeftList=visit(ctx->p1()).as<vector<Stmt>>();
        for(vector<Stmt>::iterator it=LeftList.begin();it!=LeftList.end();it++)
        {
            StmtList.push_back(*it);
        }
        return StmtList;
    }
    
    antlrcpp::Any visitP1Nothing(kernelParser::P1NothingContext *ctx) override {
        vector<Stmt> StmtList;
        return StmtList;
    }
    
    antlrcpp::Any visitVisitS(kernelParser::VisitSContext *ctx) override {
        Expr lhsExpr=visit(ctx->lhs()).as<Expr>();
        Expr rhsExpr=visit(ctx->rhs()).as<Expr>();
        //Stmt s= Move::make(lhsExpr,rhsExpr,MoveType::MemToMem);
        return s;
    }
    
    antlrcpp::Any visitLHS(kernelParser::LHSContext *ctx) override {
        Expr tRef=visit(ctx->tRef());
        return tRef;
    }
    
    antlrcpp::Any visitRHSconstNum(kernelParser::RHSconstNumContext *ctx) override {
        //TODO
        Expr s;
        return s;
    }
    
    antlrcpp::Any visitRHSSecondopRHS(kernelParser::RHSSecondopRHSContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitOneRHS(kernelParser::OneRHSContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitRHSFirstropRHS(kernelParser::RHSFirstropRHSContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitRHSsRef(kernelParser::RHSsRefContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitRHStRef(kernelParser::RHStRefContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitRHSFirstCalcIsMUL(kernelParser::RHSFirstCalcIsMULContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitRHSFirstCalcIsDIV(kernelParser::RHSFirstCalcIsDIVContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitRHSFirstCalcMOD(kernelParser::RHSFirstCalcMODContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitRHSFirstCalcINTDIV(kernelParser::RHSFirstCalcINTDIVContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitRHSSecondCalcIsPLUS(kernelParser::RHSSecondCalcIsPLUSContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitRHSSecondCalcIsMINUS(kernelParser::RHSSecondCalcIsMINUSContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitTREF(kernelParser::TREFContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitSREF(kernelParser::SREFContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitCLIST(kernelParser::CLISTContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitCLISTNODE(kernelParser::CLISTNODEContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitCLISTNODENothing(kernelParser::CLISTNODENothingContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitALIST(kernelParser::ALISTContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitALISTNODE(kernelParser::ALISTNODEContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitALISTNODENothing(kernelParser::ALISTNODENothingContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitFirstIdIntV(kernelParser::FirstIdIntVContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitIdId(kernelParser::IdIdContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitSecondIdIntV(kernelParser::SecondIdIntVContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitOneId(kernelParser::OneIdContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitOneIdExpr(kernelParser::OneIdExprContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitIdExprCalcIsMUL(kernelParser::IdExprCalcIsMULContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitIdExprCalcIsINTDIV(kernelParser::IdExprCalcIsINTDIVContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitIdExprCalcIsMOD(kernelParser::IdExprCalcIsMODContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitFloatConst(kernelParser::FloatConstContext *ctx) override {
        return visitChildren(ctx);
    }
    
    antlrcpp::Any visitIntConst(kernelParser::IntConstContext *ctx) override {
        return visitChildren(ctx);
    }
};
