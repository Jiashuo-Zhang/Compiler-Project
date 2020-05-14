#ifndef Kernel2IRVisitor_H
#define Kernel2IRVisitor_H

#include <iostream>
#include <string>
#include <vector>
#include "antlr4-runtime.h"
#include "kernelBaseVisitor.h"

#include "IR.h"
#include "IRMutator.h"
#include "IRVisitor.h"
#include "IRPrinter.h"
#include "type.h"
using namespace Boost::Internal;
using namespace std;
using namespace antlr4;


class Kernel2IRVisitor : public kernelBaseVisitor
{
    Type kernel_index_type = Type::int_scalar(32);
    Type kernel_data_type = Type::float_scalar(32);
    
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
        //cout<<"EnterVisitP"<<endl;
        StmtList.push_back(visit(ctx->s()).as<Stmt>());//s should return stmt
        vector<Stmt> LeftList;
        //cout<<StmtList.size()<<endl;
        LeftList=visit(ctx->p1()).as<vector<Stmt>>();
        
        for(vector<Stmt>::iterator it=LeftList.begin();it!=LeftList.end();it++)
        {
            //cout<<"ADD STATEMENT!"<<endl;
            StmtList.push_back(*it);
        }
        return StmtList;
    }
    
    antlrcpp::Any visitVisitP1(kernelParser::VisitP1Context *ctx) override {
        vector<Stmt> StmtList;
        StmtList.push_back(visit(ctx->s()).as<Stmt>());//s should return stmt
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
        //cout<<"EnterVisitS"<<endl;
        Expr lhsExpr=visit(ctx->lhs()).as<Expr>();
        Expr rhsExpr=visit(ctx->rhs()).as<Expr>();
        Stmt s= Move::make(lhsExpr,rhsExpr,MoveType::MemToMem);
        return s;
    }
    
    antlrcpp::Any visitLHS(kernelParser::LHSContext *ctx) override {
        //cout<<"EnterVisitLHS"<<endl;
        Expr tRef;
        tRef=visit(ctx->tRef()).as<Expr>();
        return tRef;
    }
    
    antlrcpp::Any visitRHSconstNum(kernelParser::RHSconstNumContext *ctx) override {
        Expr ConstNum=visit(ctx->constNum()).as<Expr>();
        return ConstNum;
    }
    
    antlrcpp::Any visitRHSSecondopRHS(kernelParser::RHSSecondopRHSContext *ctx) override {
        cout<<"Enter SecondOpRHS"<<endl;
        Expr first=visit(ctx->rhs(0)).as<Expr>();
        Expr second=visit(ctx->rhs(1)).as<Expr>();
        int t=visit(ctx->rhsSecondCalc()).as<int>();
        if(t==1)
        {
            Expr res1=Expr(Binary::make(kernel_data_type,BinaryOpType::Add,first,second));
            cout<<"+"<<endl;
            cout<<"Leave SecondOpRHS"<<endl;
            return res1;
        }
        else if(t==2)
        {
            Expr res1=Expr(Binary::make(kernel_data_type,BinaryOpType::Sub,first,second));
            cout<<"-"<<endl;
            cout<<"Leave SecondOpRHS"<<endl;
            return res1;
        }
        
        return first;
        
    }
    
    antlrcpp::Any visitOneRHS(kernelParser::OneRHSContext *ctx) override {
        cout<<"Meet ( )"<<endl;
        Expr exp=visit(ctx->rhs()).as<Expr>();
        Expr res=Unary::make(kernel_index_type,UnaryOpType::Not, exp);
        return res;
    }
    
    antlrcpp::Any visitRHSFirstropRHS(kernelParser::RHSFirstropRHSContext *ctx) override {
        cout<<"Enter FirstOpRHS"<<endl;
        Expr first=visit(ctx->rhs(0)).as<Expr>();
        Expr second=visit(ctx->rhs(1)).as<Expr>();
        
        int t=visit(ctx->rhsFirstCalc()).as<int>();
        Expr res;
        if(t==3)
        {
            
            res=Binary::make(kernel_data_type,BinaryOpType::Mul,first,second);
            cout<<"*"<<endl;
        }
        else if(t==4)
        {
            res=Binary::make(kernel_data_type,BinaryOpType::Div,first,second);
            cout<<"/"<<endl;
        }
        else if(t==5)
        {
            res=Binary::make(kernel_data_type,BinaryOpType::Mod,first,second);
            cout<<"%"<<endl;
        }
        else if(t==6)
        {
            res=Binary::make(kernel_index_type,BinaryOpType::Div,first,second);
            cout<<"/"<<"/"<<endl;
        }
       
        cout<<"Leave FirstOpRHS"<<endl;
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
        string Id=ctx->Id()->getText();
        vector<size_t> Clist=visit(ctx->clist()).as<vector<size_t>>();
        vector<Expr> Alist=visit(ctx->alist()).as<vector<Expr>>();
        Expr res=Var::make(kernel_data_type,Id,Alist,Clist);
        return res;
    }
    
    antlrcpp::Any visitSREF(kernelParser::SREFContext *ctx) override {
        string Id=ctx->Id()->getText();
        vector<size_t> Clist=visit(ctx->clist()).as<vector<size_t>>();
        vector<Expr> Alist;
        Expr res=Var::make(kernel_data_type,Id,Alist,Clist);
        return res;
    }
    
    antlrcpp::Any visitCLIST(kernelParser::CLISTContext *ctx) override {
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
        return CList;
    }
    
    antlrcpp::Any visitCLISTNODE(kernelParser::CLISTNODEContext *ctx) override {
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
        return CList;
    }
    
    antlrcpp::Any visitCLISTNODENothing(kernelParser::CLISTNODENothingContext *ctx) override {
        vector<size_t> nothing;
        return nothing;
    }
    
    antlrcpp::Any visitALIST(kernelParser::ALISTContext *ctx) override {
        vector<Expr> AList;
        AList.push_back(visit(ctx->idExpr()).as<Expr>());
        vector<Expr> LeftList;
        LeftList=visit(ctx->alistNode()).as<vector<Expr>>();
        for(vector<Expr>::iterator it=LeftList.begin();it!=LeftList.end();it++)
        {
            AList.push_back(*it);
        }
        return AList;
        
        
        vector<Expr> nothing;
        return nothing;
    }
    
    antlrcpp::Any visitALISTNODE(kernelParser::ALISTNODEContext *ctx) override {
        vector<Expr> AList;
         AList.push_back(visit(ctx->idExpr()).as<Expr>());
         vector<Expr> LeftList;
         LeftList=visit(ctx->alistNode()).as<vector<Expr>>();
         for(vector<Expr>::iterator it=LeftList.begin();it!=LeftList.end();it++)
         {
         AList.push_back(*it);
         }
         return AList;
        
        vector<Expr> nothing;
        return nothing;
    }
    
    antlrcpp::Any visitALISTNODENothing(kernelParser::ALISTNODENothingContext *ctx) override {
        vector<Expr> nothing;
        return nothing;
    }
    
    antlrcpp::Any visitFirstIdIntV(kernelParser::FirstIdIntVContext *ctx) override {
        cout<<"Enter FirstIdOpIntV"<<endl;
        Expr first=visit(ctx->idExpr()).as<Expr>();
        int t=visit(ctx->idExprFirstCalc()).as<int>();
        size_t num;
        string s = ctx->IntV()->getText();
        std::stringstream sstream(s);
        sstream >> num;
        Expr second=Expr(int(num));
        
        Expr res;
        switch (t) {
            case 3:
                res=Binary::make(kernel_index_type,BinaryOpType::Mul,first,second);
                cout<<"*"<<endl;
                break;
            case 4:
                res=Binary::make(kernel_index_type,BinaryOpType::Div,first,second);
                cout<<"//"<<endl;
                break;
            case 5:
                res=Binary::make(kernel_index_type,BinaryOpType::Mod,first,second);
                cout<<"%"<<endl;
                break;
            default:
                break;
        }
        cout<<"Leave FirstIdOpIntV"<<endl;
        return res;
    }
    
    antlrcpp::Any visitIdId(kernelParser::IdIdContext *ctx) override {
        Expr first=visit(ctx->idExpr(0)).as<Expr>();
        Expr second=visit(ctx->idExpr(1)).as<Expr>();
        Expr res;
        res=Binary::make(kernel_index_type,BinaryOpType::Add,first,second);
        return res;
    }
    
    antlrcpp::Any visitSecondIdIntV(kernelParser::SecondIdIntVContext *ctx) override {
        cout<<"Enter IdOpIntV"<<endl;
        Expr first=visit(ctx->idExpr()).as<Expr>();
        int t=visit(ctx->idExprSecondCalc()).as<int>();
        size_t num;
        string s = ctx->IntV()->getText();
        std::stringstream sstream(s);
        sstream >> num;
        Expr second=Expr(int(num));
        Expr res;
        switch (t) {
            case 1:
                res=Binary::make(kernel_index_type,BinaryOpType::Add,first,second);
                cout<<"+"<<endl;
                break;
            case 2:
                res=Binary::make(kernel_index_type,BinaryOpType::Sub,first,second);
                cout<<"-"<<endl;
                break;
            default:
                break;
        }
        cout<<"Leave IdOpIntV"<<endl;
        return res;
    }
    
    antlrcpp::Any visitOneId(kernelParser::OneIdContext *ctx) override {
        //Expr p;
        Expr dom_p = Dom::make(kernel_index_type, 0, 0);
        Expr p = Index::make(kernel_index_type,ctx->Id()->getText(), dom_p, IndexType::Spatial);
        return p;
    }
    
    antlrcpp::Any visitOneIdExpr(kernelParser::OneIdExprContext *ctx) override {
        cout<<"Meet ( )"<<endl;
        Expr exp=visit(ctx->idExpr()).as<Expr>();
        Expr res=Unary::make(kernel_index_type,UnaryOpType::Not, exp);
        return res;
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
        Expr expr=Expr(float(f));
        return expr;
    }
    
    antlrcpp::Any visitIntConst(kernelParser::IntConstContext *ctx) override {
        int f;
        string s = ctx->IntV()->getText();
        std::stringstream sstream(s);
        sstream >> f;
        Expr expr=Expr(float(f));
        return expr;
    }
};

#endif
