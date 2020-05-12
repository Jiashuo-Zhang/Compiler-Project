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
using namespace antlr4;

class Kernel2IRVisitor : public kernelBaseVisitor
{
    Type data_type = Type::float_scalar(32);
    Type index_type = Type::int_scalar(32);
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
        cout<<"EnterVisitP"<<endl;  
        StmtList.push_back(visit(ctx->s()).as<Stmt>());////s should return stmt
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
        StmtList.push_back(visit(ctx->s()).as<Stmt>());////s should return stmt
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
        cout<<"EnterVisitS"<<endl;
        Expr lhsExpr=visit(ctx->lhs()).as<Expr>();
        Expr rhsExpr=visit(ctx->rhs()).as<Expr>();
        Stmt s;
        s= Move::make(lhsExpr,rhsExpr,MoveType::MemToMem);
        return s;
    }
    
    antlrcpp::Any visitLHS(kernelParser::LHSContext *ctx) override {
        cout<<"EnterVisitLHS"<<endl;
        Expr tRef=visit(ctx->tRef()).as<Expr>();
        return tRef;
    }
    
    antlrcpp::Any visitRHSconstNum(kernelParser::RHSconstNumContext *ctx) override {
        Expr ConstNum=visit(ctx->constNum()).as<Expr>();
        return ConstNum;
    }
    
    antlrcpp::Any visitRHSSecondopRHS(kernelParser::RHSSecondopRHSContext *ctx) override {
        cout<<"EnterSecondOpRHS"<<endl;
        Expr first=visit(ctx->rhs(0)).as<Expr>();
        Expr second=visit(ctx->rhs(1)).as<Expr>();
        int t=visit(ctx->rhsSecondCalc()).as<int>();
        Expr res;
        //Expr res=Binary::make(data_type,BinaryOpType::Add,first,second);
        switch (t) {
            case 1:
                res=Binary::make(data_type,BinaryOpType::Add,first,second);
                cout<<"+"<<endl;
                return res;
                break;
            case 2:
                //res=Binary::make(mydata_type,BinaryOpType::Sub,first,second);
                cout<<"-"<<endl;
                break;
            default:
                break;
        }
        cout<<"FinishSecondOpRHS"<<endl;
        return res;
        
    }
    
    antlrcpp::Any visitOneRHS(kernelParser::OneRHSContext *ctx) override {
        return visit(ctx->rhs()).as<Expr>();
    }
    
    antlrcpp::Any visitRHSFirstropRHS(kernelParser::RHSFirstropRHSContext *ctx) override {
        cout<<"EnterRHSFirstOp"<<endl;
        Expr first=visit(ctx->rhs(0)).as<Expr>();
        Expr second=visit(ctx->rhs(1)).as<Expr>();
        
        int t=visit(ctx->rhsFirstCalc()).as<int>();
        Expr res;
        
        switch (t) {
            case 3:
                //res=Binary::make(mydata_type,BinaryOpType::Mul,first,second);
                cout<<"*"<<endl;
                break;
            case 4:
                //res=Binary::make(mydata_type,BinaryOpType::Div,first,second);
                cout<<"/"<<endl;
                break;
            case 5:
                //res=Binary::make(mydata_type,BinaryOpType::Mod,first,second);
                cout<<"%"<<endl;
            case 6:
                //res=Binary::make(myindex_type,BinaryOpType::Div,first,second);
                cout<<"/"<<"/"<<endl;
            default:
                break;
        }
        cout<<"FinishRHSFirstOp"<<endl;
        return res;
    }
    
    antlrcpp::Any visitRHSsRef(kernelParser::RHSsRefContext *ctx) override {
        Expr sRef=visit(ctx->sRef()).as<Expr>();
        return sRef;
    }
    
    antlrcpp::Any visitRHStRef(kernelParser::RHStRefContext *ctx) override {
        Expr tRef=visit(ctx->tRef()).as<Expr>();
        return tRef;
    }
    
    antlrcpp::Any visitRHSFirstCalcIsMUL(kernelParser::RHSFirstCalcIsMULContext *ctx) override {
        return 3;
    }
    
    antlrcpp::Any visitRHSFirstCalcIsDIV(kernelParser::RHSFirstCalcIsDIVContext *ctx) override {
        return 4;
    }
    
    antlrcpp::Any visitRHSFirstCalcMOD(kernelParser::RHSFirstCalcMODContext *ctx) override {
        return 5;
    }
    
    antlrcpp::Any visitRHSFirstCalcINTDIV(kernelParser::RHSFirstCalcINTDIVContext *ctx) override {
        return 6;
    }
    
    antlrcpp::Any visitRHSSecondCalcIsPLUS(kernelParser::RHSSecondCalcIsPLUSContext *ctx) override {
        return 1;
    }
    
    antlrcpp::Any visitRHSSecondCalcIsMINUS(kernelParser::RHSSecondCalcIsMINUSContext *ctx) override {
        return 2;
    }
    
    
    antlrcpp::Any visitTREF(kernelParser::TREFContext *ctx) override {
        cout<<"EnterTREF"<<endl;
        string Id=ctx->Id()->getText();
        vector<size_t> Clist=visit(ctx->clist()).as<vector<size_t>>();
        vector<Expr> Alist=visit(ctx->alist()).as<vector<Expr>>();
        Expr res;
        //Expr res=Var::make(mydata_type,Id,Clist,Alist);
        return res;
    }
    
    antlrcpp::Any visitSREF(kernelParser::SREFContext *ctx) override {
        string Id=ctx->Id()->getText();
        vector<Expr> Clist=visit(ctx->clist()).as<vector<Expr>>();
        vector<size_t> Alist;
        Expr res;
        //Expr res=Var::make(mydata_type,Id,Clist,Alist);
        return res;
    }
    
    antlrcpp::Any visitCLIST(kernelParser::CLISTContext *ctx) override {
        cout<<"EnterCList"<<endl;
        vector<size_t> CList;
        size_t first;
        string s = ctx->IntV()->getText();
        std::stringstream sstream(s);
        sstream >> first;
        CList.push_back(first);
        vector<size_t> LeftList;
        LeftList=visit(ctx->clistNode()).as<vector<size_t>>();
        for(vector<size_t>::iterator it=LeftList.begin();it!=LeftList.end();it++)
        {
            CList.push_back(*it);
        }
        cout<<"FinishCList"<<endl;
        return CList;
    }
    
    antlrcpp::Any visitCLISTNODE(kernelParser::CLISTNODEContext *ctx) override {
        cout<<"EnterClistNode"<<endl;
        vector<size_t> CList;
        size_t first;
        string s = ctx->IntV()->getText();
        std::stringstream sstream(s);
        sstream >> first;
        CList.push_back(first);
        vector<size_t> LeftList;
        LeftList=visit(ctx->clistNode()).as<vector<size_t>>();
        for(vector<size_t>::iterator it=LeftList.begin();it!=LeftList.end();it++)
        {
            CList.push_back(*it);
        }
        cout<<"FinishClistNode"<<endl;
        return CList;
    }
    
    antlrcpp::Any visitCLISTNODENothing(kernelParser::CLISTNODENothingContext *ctx) override {
        vector<size_t> nothing;
        return nothing;
    }
    
    antlrcpp::Any visitALIST(kernelParser::ALISTContext *ctx) override {
        cout<<"EnterAlist"<<endl;
        //TODO
        /*vector<Expr> AList;
        AList.push_back(visit(ctx->idExpr()).as<Expr>());
        vector<Expr> LeftList;
        LeftList=visit(ctx->alistNode()).as<vector<Expr>>();
        for(vector<Expr>::iterator it=LeftList.begin();it!=LeftList.end();it++)
        {
            AList.push_back(*it);
        }
        return AList;
        */
        
        vector<Expr> nothing;
        return nothing;
    }
    
    antlrcpp::Any visitALISTNODE(kernelParser::ALISTNODEContext *ctx) override {
        //TODO
        /*vector<Expr> AList;
         AList.push_back(visit(ctx->idExpr()).as<Expr>());
         vector<Expr> LeftList;
         LeftList=visit(ctx->alistNode()).as<vector<Expr>>();
         for(vector<Expr>::iterator it=LeftList.begin();it!=LeftList.end();it++)
         {
         AList.push_back(*it);
         }
         return AList;
         */
        vector<Expr> nothing;
        return nothing;
    }
    
    antlrcpp::Any visitALISTNODENothing(kernelParser::ALISTNODENothingContext *ctx) override {
        vector<Expr> nothing;
        return nothing;
    }
    
    antlrcpp::Any visitFirstIdIntV(kernelParser::FirstIdIntVContext *ctx) override {
        Expr first=visit(ctx->idExpr()).as<Expr>();
        int t=visit(ctx->idExprFirstCalc()).as<int>();
        size_t num;
        string s = ctx->IntV()->getText();
        std::stringstream sstream(s);
        sstream >> num;
        //TODO Expr second=num;
        Expr second;
        Expr res;
        switch (t) {
            case 3:
                //res=Binary::make(myindex_type,BinaryOpType::Mul,x,first,second);
                break;
            case 4:
                //res=Binary::make(myindex_type,BinaryOpType::Div,x,first,second);
                break;
            case 5:
                //res=Binary::make(myindex_type,BinaryOpType::Mod,x,first,second);
                break;
            default:
                break;
        }
        return res;
    }
    
    antlrcpp::Any visitIdId(kernelParser::IdIdContext *ctx) override {
        Expr first=visit(ctx->idExpr(0)).as<Expr>();
        Expr second=visit(ctx->idExpr(1)).as<Expr>();
        Expr res;
        //res=Binary::make(myindex_type,BinaryOpType::Add,x,first,second);
        return res;
    }
    
    antlrcpp::Any visitSecondIdIntV(kernelParser::SecondIdIntVContext *ctx) override {
        Expr first=visit(ctx->idExpr()).as<Expr>();
        int t=visit(ctx->idExprSecondCalc()).as<int>();
        size_t num;
        string s = ctx->IntV()->getText();
        std::stringstream sstream(s);
        sstream >> num;
        //TODO: Expr second=num;
        Expr second;
        Expr res;
        switch (t) {
            case 1:
                //res=Binary::make(myindex_type,BinaryOpType::Add,x,first,second);
                break;
            case 2:
                //res=Binary::make(myindex_type,BinaryOpType::Sub,x,first,second);
                break;
            default:
                break;
        }
        return res;
    }
    
    antlrcpp::Any visitOneId(kernelParser::OneIdContext *ctx) override {
        Expr p;
        //Expr dom_p = Dom::make(myindex_type, 0, 0);
        //Expr p = Index::make(myindex_type,ctx->Id()->getText(), dom_p, IndexType::Spatial);
        return p;
    }
    
    antlrcpp::Any visitOneIdExpr(kernelParser::OneIdExprContext *ctx) override {
        return visit(ctx->idExpr());
    }
    
    antlrcpp::Any visitIdExprCalcIsMUL(kernelParser::IdExprCalcIsMULContext *ctx) override {
        return 3;
    }
    
    antlrcpp::Any visitIdExprCalcIsINTDIV(kernelParser::IdExprCalcIsINTDIVContext *ctx) override {
        return 4;
    }
    
    antlrcpp::Any visitIdExprCalcIsMOD(kernelParser::IdExprCalcIsMODContext *ctx) override {
        return 5;
    }
    antlrcpp::Any visitIdSecondCalcIsPLUS(kernelParser::IdSecondCalcIsPLUSContext *context) override
    {
        return 1;
    }
    
    antlrcpp::Any visitIdSecondCalcIsMINUS(kernelParser::IdSecondCalcIsMINUSContext *context) override
    {
        return 2;
    }

    
    antlrcpp::Any visitFloatConst(kernelParser::FloatConstContext *ctx) override {
        float f;
        string s = ctx->FloatV()->getText();
        std::stringstream sstream(s);
        sstream >> f;
        //Expr expr=Expr(f);
        Expr expr;
        return expr;
    }
    
    antlrcpp::Any visitIntConst(kernelParser::IntConstContext *ctx) override {
        int f;
        string s = ctx->IntV()->getText();
        std::stringstream sstream(s);
        sstream >> f;
        //TODO Expr expr=Expr(f);
        Expr expr;
        return expr;
    }
};
