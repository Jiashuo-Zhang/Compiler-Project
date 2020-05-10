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


class Kernel2IRVisitor : public kernelBaseVisitor
{
public:
 	antlrcpp::Any visitStart(kernelParser::StartContext *ctx) {
 	return visit(ctx->p());
    //return visitChildren(ctx);
  }

	antlrcpp::Any visitEnd(kernelParser::EndContext *ctx) {
    return visitChildren(ctx);
  }

	antlrcpp::Any visitVisitP(kernelParser::VisitPContext *ctx) {
    //return visitChildren(ctx);
		vector<Stmt> StmtList= new vector<Stmt>();
		StmtList.push_back(visit(ctx->s()));////s should return stmt
		vector<Stmt> LeftList;
		LeftList=visit(ctx->p1());
		for(vector<Stmt>::iterator it=LeftList.begin();it!=LeftList.end();it++)
		{
			StmtList.push_back(*it);
		}
		return StmtList;
  }

  	antlrcpp::Any visitVisitP1(kernelParser::VisitP1Context *ctx) {
    	vector<Stmt> StmtList= new vector<Stmt>();
		StmtList.push_back(visit(ctx->s()));////s should return stmt
		vector<Stmt> LeftList;
		LeftList=visit(ctx->p1());
		for(vector<Stmt>::iterator it=LeftList.begin();it!=LeftList.end();it++)
		{
			StmtList.push_back(*it);
		}
		return StmtList;  
	}

  	antlrcpp::Any visitP1Nothing(kernelParser::P1NothingContext *ctx) {
    	vector<Stmt> StmtList= new vector<Stmt>();
    	return StmtList;
  }

  	antlrcpp::Any visitVisitS(kernelParser::VisitSContext *ctx) {
	  	Expr lhsExpr=visit(ctx->lhs());
	  	Expr rhsExpr=visit(ctx->rhs());
	  	Stmt s= Move::make(lhsExpr,rhsExpr,MoveType::MemToMem);
	    return s;
  }

  	antlrcpp::Any visitLHS(kernelParser::LHSContext *ctx) {
    	Expr tRef=visit(ctx->tRef());
    	return tRef;
  }

  	antlrcpp::Any visitOneRHS(kernelParser::OneRHSContext *ctx) {
  		Expr RHS=visit(ctx->rhs());
    	return RHS;
  }

  	antlrcpp::Any visitOnetRef(kernelParser::OnetRefContext *ctx) {
    	Expr tRef=visit(ctx->tRef());
    	return tRef;
  }

  	antlrcpp::Any visitOnesRef(kernelParser::OnesRefContext *ctx) {
  		Expr sRef=visit(ctx->sRef());
    	return sRef;
  }

  	antlrcpp::Any visitOneconstNum(kernelParser::OneconstNumContext *ctx) {
    	Expr ConstNum=visit(ctx->constNum);
    	return ConstNum;
  }

  	antlrcpp::Any visitRHS(kernelParser::RHSContext *ctx) {
  		Expr firstExpr=visit(ctx->simpleRHS());
    	pair<bool,pair<int,Expr>> p=visit(ctx->rhs2());
    	Expr res;
    	if(p.first==true)
    	{
	    	switch p.second.first
	    	{
	    		case 0 :
	    			res=Binary::make(data_type,BinaryOpType::Add,firstExpr,p.second.second);////TODO :type未处理
	    			break;
	    		case 1 :
	    			res=Binary::make(data_type,BinaryOpType::Sub,firstExpr,p.second.second);
	    			break;
	    		case 2 :
	    			res=Binary::make(data_type,BinaryOpType::Mul,firstExpr,p.second.second);
	    			break;
	    		case 3 :
	    			res=Binary::make(data_type,BinaryOpType::Div,firstExpr,p.second.second);
	    			break;
	    		case 4 :
	    			res=Binary::make(data_type,BinaryOpType::Mod,firstExpr,p.second.second);
	    			break;
	    		default:
	    			break;
	    	}
	    	return res;
	    }
	    else
	    {
	    	return firstExpr;
	    }
    	
  }

  	antlrcpp::Any visitPlusRhs2(kernelParser::PlusRhs2Context *ctx) {
    	Expr firstExpr=visit(ctx->simpleRHS());
    	pair<bool,pair<int,Expr>> p=visit(ctx->rhs2());
    	Expr res;
    	if(p.first==true)
    	{
	    	switch p.second.first
	    	{
	    		case 0 :
	    			res=Binary::make(data_type,BinaryOpType::Add,firstExpr,p.second.second);////TODO :type未处理
	    			break;
	    		case 1 :
	    			res=Binary::make(data_type,BinaryOpType::Sub,firstExpr,p.second.second);
	    			break;
	    		case 2 :
	    			res=Binary::make(data_type,BinaryOpType::Mul,firstExpr,p.second.second);
	    			break;
	    		case 3 :
	    			res=Binary::make(data_type,BinaryOpType::Div,firstExpr,p.second.second);
	    			break;
	    		case 4 :
	    			res=Binary::make(data_type,BinaryOpType::Mod,firstExpr,p.second.second);
	    			break;
	    		default:
	    			break;
	    	}
	    	return make_pair(true,make_pair(0,res));
	    }
	    else
	    {
	    	return make_pair(true,make_pair(0,firstExpr));
	    }
  }

  	antlrcpp::Any visitMulRhs2(kernelParser::MulRhs2Context *ctx) {
    	Expr firstExpr=visit(ctx->simpleRHS());
    	pair<bool pair<int,Expr>> p=visit(ctx->rhs2());
    	Expr res;
    	if(p.first==true)
    	{
	    	switch p.second.first
	    	{
	    		case 0 :
	    			res=Binary::make(data_type,BinaryOpType::Add,firstExpr,p.second.second);////TODO :type未处理
	    			break;
	    		case 1 :
	    			res=Binary::make(data_type,BinaryOpType::Sub,firstExpr,p.second.second);
	    			break;
	    		case 2 :
	    			res=Binary::make(data_type,BinaryOpType::Mul,firstExpr,p.second.second);
	    			break;
	    		case 3 :
	    			res=Binary::make(data_type,BinaryOpType::Div,firstExpr,p.second.second);
	    			break;
	    		case 4 :
	    			res=Binary::make(data_type,BinaryOpType::Mod,firstExpr,p.second.second);
	    			break;
	    		default:
	    			break;
	    	}
	    	return make_pair(true,make_pair(2,res));
	    }
	    else
	    {
	    	return make_pair(true,make_pair(2,firstExpr));
	    }
  }

  	antlrcpp::Any visitMinusRhs2(kernelParser::MinusRhs2Context *ctx) {
    	Expr firstExpr=visit(ctx->simpleRHS());
    	pair<bool pair<int,Expr>> p=visit(ctx->rhs2());
    	Expr res;
    	if(p.first==true)
    	{
	    	switch p.second.first
	    	{
	    		case 0 :
	    			res=Binary::make(data_type,BinaryOpType::Add,firstExpr,p.second.second);////TODO :type未处理
	    			break;
	    		case 1 :
	    			res=Binary::make(data_type,BinaryOpType::Sub,firstExpr,p.second.second);
	    			break;
	    		case 2 :
	    			res=Binary::make(data_type,BinaryOpType::Mul,firstExpr,p.second.second);
	    			break;
	    		case 3 :
	    			res=Binary::make(data_type,BinaryOpType::Div,firstExpr,p.second.second);
	    			break;
	    		case 4 :
	    			res=Binary::make(data_type,BinaryOpType::Mod,firstExpr,p.second.second);
	    			break;
	    		default:
	    			break;
	    	}
	    	return make_pair(true,make_pair(1,res));
	    }
	    else
	    {
	    	return make_pair(true,make_pair(1,firstExpr));
	    }
  }

  	antlrcpp::Any visitDivRhs2(kernelParser::DivRhs2Context *ctx) {
    	Expr firstExpr=visit(ctx->simpleRHS());
    	pair<bool pair<int,Expr>> p=visit(ctx->rhs2());
    	Expr res;
    	if(p.first==true)
    	{
	    	switch p.second.first
	    	{
	    		case 0 :
	    			res=Binary::make(data_type,BinaryOpType::Add,firstExpr,p.second.second);////TODO :type未处理
	    			break;
	    		case 1 :
	    			res=Binary::make(data_type,BinaryOpType::Sub,firstExpr,p.second.second);
	    			break;
	    		case 2 :
	    			res=Binary::make(data_type,BinaryOpType::Mul,firstExpr,p.second.second);
	    			break;
	    		case 3 :
	    			res=Binary::make(data_type,BinaryOpType::Div,firstExpr,p.second.second);
	    			break;
	    		case 4 :
	    			res=Binary::make(data_type,BinaryOpType::Mod,firstExpr,p.second.second);
	    			break;
	    		default:
	    			break;
	    	}
	    	return make_pair(true,make_pair(3,res));
	    }
	    else
	    {
	    	return make_pair(true,make_pair(0,firstExpr));
	    }
  }

  	antlrcpp::Any visitModRhs2(kernelParser::ModRhs2Context *ctx) {
    	Expr firstExpr=visit(ctx->simpleRHS());
    	pair<bool pair<int,Expr>> p=visit(ctx->rhs2());
    	Expr res;
    	if(p.first==true)
    	{
	    	switch p.second.first
	    	{
	    		case 0 :
	    			res=Binary::make(data_type,BinaryOpType::Add,firstExpr,p.second.second);////TODO :type未处理
	    			break;
	    		case 1 :
	    			res=Binary::make(data_type,BinaryOpType::Sub,firstExpr,p.second.second);
	    			break;
	    		case 2 :
	    			res=Binary::make(data_type,BinaryOpType::Mul,firstExpr,p.second.second);
	    			break;
	    		case 3 :
	    			res=Binary::make(data_type,BinaryOpType::Div,firstExpr,p.second.second);
	    			break;
	    		case 4 :
	    			res=Binary::make(data_type,BinaryOpType::Mod,firstExpr,p.second.second);
	    			break;
	    		default:
	    			break;
	    	}
	    	return make_pair(true,make_pair(4,res));
	    }
	    else
	    {
	    	return make_pair(true,make_pair(4,firstExpr));
	    }
  }

  	antlrcpp::Any visitIntDivRhs2(kernelParser::IntDivRhs2Context *ctx) {
    	Expr firstExpr=visit(ctx->simpleRHS());
    	pair<bool pair<int,Expr>> p=visit(ctx->rhs2());
    	Expr res;
    	if(p.first==true)
    	{
	    	switch p.second.first
	    	{
	    		case 0 :
	    			res=Binary::make(data_type,BinaryOpType::Add,firstExpr,p.second.second);////TODO :type未处理
	    			break;
	    		case 1 :
	    			res=Binary::make(data_type,BinaryOpType::Sub,firstExpr,p.second.second);
	    			break;
	    		case 2 :
	    			res=Binary::make(data_type,BinaryOpType::Mul,firstExpr,p.second.second);
	    			break;
	    		case 3 :
	    			res=Binary::make(data_type,BinaryOpType::Div,firstExpr,p.second.second);
	    			break;
	    		case 4 :
	    			res=Binary::make(data_type,BinaryOpType::Mod,firstExpr,p.second.second);
	    			break;
	    		default:
	    			break;
	    	}
	    	return make_pair(true,make_pair(3,res));
	    }
	    else
	    {
	    	return make_pair(true,make_pair(3,firstExpr));
	    }
  }

  	antlrcpp::Any visitRHS2Nothing(kernelParser::RHS2NothingContext *ctx) {
	    Expr p;
	    return make_pair(false,make_pair(0,p));
  }

  	antlrcpp::Any visitTREF(kernelParser::TREFContext *ctx) {
  		string Id=ctx->Id().getText();
  		vector<Expr> Clist=visit(ctx->clist());
  		vector<size_t> Alist=visit(ctx->alist());
  		Expr res=Var::make(data_type,Id,Clist,Alist);
    	return res;
  }

  	antlrcpp::Any visitSREF(kernelParsestring Id=ctx->Id().getText();
  		vector<Expr> Clist=visit(ctx->clist());
  		vector<size_t> Alist=new vector<size_t>();
  		Expr res=Var::make(data_type,Id,Clist,Alist);
    	return res;return visitChildren(ctx);
  }

  	antlrcpp::Any visitCLIST(kernelParser::CLISTContext *ctx) {
    	vector<size_t> CList= new vector<size_t>();
    	size_t first;
    	string s = ctx->IntV()->getText();
		std::stringstream sstream(s);
		sstream >> first;
		StmtList.push_back(first);////s should return stmt
		vector<size_t> LeftList;
		LeftList=visit(ctx->clistNode());
		for(vector<size_t>::iterator it=LeftList.begin();it!=LeftList.end();it++)
		{
			CList.push_back(*it);
		}
		return CList;
  }

  	antlrcpp::Any visitCLISTNODE(kernelParser::CLISTNODEContext *ctx) {
    	vector<size_t> CList= new vector<size_t>();
    	size_t first;
    	string s = ctx->IntV()->getText();
		std::stringstream sstream(s);
		sstream >> first;
		StmtList.push_back(first);////s should return stmt
		vector<size_t> LeftList;
		LeftList=visit(ctx->clistNode());
		for(vector<size_t>::iterator it=LeftList.begin();it!=LeftList.end();it++)
		{
			CList.push_back(*it);
		}
		return CList;
  }

 	antlrcpp::Any visitCLISTNODENothing(kernelParser::CLISTNODENothingContext *ctx) {
 		vector<size_t> nothing =new vector<size_t>();
    	return nothing;
  }

  	antlrcpp::Any visitALIST(kernelParser::ALISTContext *ctx) {
    	vector<Expr> AList= new vector<Expr>();
		AList.push_back(visit(ctx->idExpr()));////s should return stmt
		vector<Expr> LeftList;
		LeftList=visit(ctx->alistNode());
		for(vector<Expr>::iterator it=LeftList.begin();it!=LeftList.end();it++)
		{
			AList.push_back(*it);
		}
		return AList;
  }

  	antlrcpp::Any visitALISTNODE(kernelParser::ALISTNODEContext *ctx) {
    	vector<Expr> AList= new vector<Expr>();
		AList.push_back(visit(ctx->idExpr()));////s should return stmt
		vector<Expr> LeftList;
		LeftList=visit(ctx->alistNode());
		for(vector<Expr>::iterator it=LeftList.begin();it!=LeftList.end();it++)
		{
			AList.push_back(*it);
		}
		return AList;
  }

  	antlrcpp::Any visitALISTNODENothing(kernelParser::ALISTNODENothingContext *ctx) {
    	vector<Expr> nothing=new vector<Expr>();
    	return nothing;
  }

   	antlrcpp::Any visitID(kernelParser::IDContext *ctx) {
   		Expr dom_p = Dom::make(index_type, 0, 0);
    	Expr p = Index::make(index_type,ctx->Id()->getText(), dom_p, IndexType::Spatial);
    	return p;
  }

  	antlrcpp::Any visitONEEXPR(kernelParser::ONEEXPRContext *ctx) {
    	return visit(ctx->idExpr());
  }

  	antlrcpp::Any visitIDEXPR(kernelParser::IDEXPRContext *ctx)  {
    	Expr firstExpr=visit(ctx->simpleIdExpr());
    	pair<bool pair<int,Expr>> p=visit(ctx->idExpr2());
    	Expr res;
    	if(p.first==true)
    	{
	    	switch p.second.first
	    	{
	    		case 0 :
	    			res=Binary::make(index_type,BinaryOpType::Add,firstExpr,p.second.second);////TODO :type未处理
	    			break;
	    		case 1 :
	    			res=Binary::make(index_type,BinaryOpType::Sub,firstExpr,p.second.second);
	    			break;
	    		case 2 :
	    			res=Binary::make(index_type,BinaryOpType::Mul,firstExpr,p.second.second);
	    			break;
	    		case 3 :
	    			res=Binary::make(index_type,BinaryOpType::Div,firstExpr,p.second.second);
	    			break;
	    		case 4 :
	    			res=Binary::make(index_type,BinaryOpType::Mod,firstExpr,p.second.second);
	    			break;
	    		default:
	    			break;
	    	}
	    	return res;
	    }
	    else
	    {
	    	return firstExpr;
	    }
  }

  	antlrcpp::Any visitPlusSimpleIDEXPR(kernelParser::PlusSimpleIDEXPRContext *ctx) {
    	Expr firstExpr=visit(ctx->simpleIdExpr());
    	pair<bool pair<int,Expr>> p=visit(ctx->idExpr2());
    	Expr res;
    	if(p.first==true)
    	{
	    	switch p.second.first
	    	{
	    		case 0 :
	    			res=Binary::make(index_type,BinaryOpType::Add,firstExpr,p.second.second);////TODO :type未处理
	    			break;
	    		case 1 :
	    			res=Binary::make(index_type,BinaryOpType::Sub,firstExpr,p.second.second);
	    			break;
	    		case 2 :
	    			res=Binary::make(index_type,BinaryOpType::Mul,firstExpr,p.second.second);
	    			break;
	    		case 3 :
	    			res=Binary::make(index_type,BinaryOpType::Div,firstExpr,p.second.second);
	    			break;
	    		case 4 :
	    			res=Binary::make(index_type,BinaryOpType::Mod,firstExpr,p.second.second);
	    			break;
	    		default:
	    			break;
	    	}
	    	return make_pair(true,make_pair(0,res);
	    }
	    else
	    {
	    	return make_pair(true,make_pair(0,firstExpr);
	    }
  }

  	antlrcpp::Any visitPluesINTV(kernelParser::PluesINTVContext *ctx) {
    	int number;
    	string s = ctx->IntV()->getText();
		std::stringstream sstream(s);
		sstream >> number;
		Expr firstExpr=number;
    	pair<bool pair<int,Expr>> p=visit(ctx->idExpr2());
    	Expr res;
    	if(p.first==true)
    	{
	    	switch p.second.first
	    	{
	    		case 0 :
	    			res=Binary::make(index_type,BinaryOpType::Add,firstExpr,p.second.second);////TODO :type未处理
	    			break;
	    		case 1 :
	    			res=Binary::make(index_type,BinaryOpType::Sub,firstExpr,p.second.second);
	    			break;
	    		case 2 :
	    			res=Binary::make(index_type,BinaryOpType::Mul,firstExpr,p.second.second);
	    			break;
	    		case 3 :
	    			res=Binary::make(index_type,BinaryOpType::Div,firstExpr,p.second.second);
	    			break;
	    		case 4 :
	    			res=Binary::make(index_type,BinaryOpType::Mod,firstExpr,p.second.second);
	    			break;
	    		default:
	    			break;
	    	}
	    	return make_pair(true,make_pair(0,res);
	    }
	    else
	    {
	    	return make_pair(true,make_pair(0,firstExpr);
	    }

  }

  	antlrcpp::Any visitMulINTV(kernelParser::MulINTVContext *ctx) {
    	int number;
    	string s = ctx->IntV()->getText();
		std::stringstream sstream(s);
		sstream >> number;
		Expr firstExpr=number;
    	pair<bool pair<int,Expr>> p=visit(ctx->idExpr2());
    	Expr res;
    	if(p.first==true)
    	{
	    	switch p.second.first
	    	{
	    		case 0 :
	    			res=Binary::make(index_type,BinaryOpType::Add,firstExpr,p.second.second);////TODO :type未处理
	    			break;
	    		case 1 :
	    			res=Binary::make(index_type,BinaryOpType::Sub,firstExpr,p.second.second);
	    			break;
	    		case 2 :
	    			res=Binary::make(index_type,BinaryOpType::Mul,firstExpr,p.second.second);
	    			break;
	    		case 3 :
	    			res=Binary::make(index_type,BinaryOpType::Div,firstExpr,p.second.second);
	    			break;
	    		case 4 :
	    			res=Binary::make(index_type,BinaryOpType::Mod,firstExpr,p.second.second);
	    			break;
	    		default:
	    			break;
	    	}
	    	return make_pair(true,make_pair(2,res);
	    }
	    else
	    {
	    	return make_pair(true,make_pair(2,firstExpr);
	    }
  }

  	antlrcpp::Any visitIntDivINTV(kernelParser::IntDivINTVContext *ctx) {
   		int number;
    	string s = ctx->IntV()->getText();
		std::stringstream sstream(s);
		sstream >> number;
		Expr firstExpr=number;
    	pair<bool pair<int,Expr>> p=visit(ctx->idExpr2());
    	Expr res;
    	if(p.first==true)
    	{
	    	switch p.second.first
	    	{
	    		case 0 :
	    			res=Binary::make(index_type,BinaryOpType::Add,firstExpr,p.second.second);////TODO :type未处理
	    			break;
	    		case 1 :
	    			res=Binary::make(index_type,BinaryOpType::Sub,firstExpr,p.second.second);
	    			break;
	    		case 2 :
	    			res=Binary::make(index_type,BinaryOpType::Mul,firstExpr,p.second.second);
	    			break;
	    		case 3 :
	    			res=Binary::make(index_type,BinaryOpType::Div,firstExpr,p.second.second);
	    			break;
	    		case 4 :
	    			res=Binary::make(index_type,BinaryOpType::Mod,firstExpr,p.second.second);
	    			break;
	    		default:
	    			break;
	    	}
	    	return make_pair(true,make_pair(3,res);
	    }
	    else
	    {
	    	return make_pair(true,make_pair(3,firstExpr);
	    }
  }

  	antlrcpp::Any visitModINTV(kernelParser::ModINTVContext *ctx) {
  		int number;
    	string s = ctx->IntV()->getText();
		std::stringstream sstream(s);
		sstream >> number;
		Expr firstExpr=number;
    	pair<bool pair<int,Expr>> p=visit(ctx->idExpr2());
    	Expr res;
    	if(p.first==true)
    	{
	    	switch p.second.first
	    	{
	    		case 0 :
	    			res=Binary::make(index_type,BinaryOpType::Add,firstExpr,p.second.second);////TODO :type未处理
	    			break;
	    		case 1 :
	    			res=Binary::make(index_type,BinaryOpType::Sub,firstExpr,p.second.second);
	    			break;
	    		case 2 :
	    			res=Binary::make(index_type,BinaryOpType::Mul,firstExpr,p.second.second);
	    			break;
	    		case 3 :
	    			res=Binary::make(index_type,BinaryOpType::Div,firstExpr,p.second.second);
	    			break;
	    		case 4 :
	    			res=Binary::make(index_type,BinaryOpType::Mod,firstExpr,p.second.second);
	    			break;
	    		default:
	    			break;
	    	}
	    	return make_pair(true,make_pair(4,res));
	    }
	    else
	    {
	    	return make_pair(true,make_pair(4,firstExpr));
	    }
    	return visitChildren(ctx);
  }

 	antlrcpp::Any visitIDEXPRNothing(kernelParser::IDEXPRNothingContext *ctx) {
    	Expr p;
    	return make_pair(false,make_pair(-1,p));
  }
 	antlrcpp::Any visitFloatConst(kernelParser::FloatConstContext *context) {
 		float f;
 		string s = ctx->FloatV()->getText();
		std::stringstream sstream(s);
		sstream >> f;
		Expr expr=f;
		return expr;

 	}

    antlrcpp::Any visitIntConst(kernelParser::IntConstContext *context) {
    	int f;
 		string s = ctx->IntV()->getText();
		std::stringstream sstream(s);
		sstream >> f;
		Expr expr=f;
		return expr;
    }

}