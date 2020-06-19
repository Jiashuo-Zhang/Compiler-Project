#include <iostream>
#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/kernelLexer.h"
#include "antlr4-runtime/kernelParser.h"
#include "Kernel2IRVisitor.h"
#include "IR.h"
#include "IRMutator.h"
#include "IRVisitor.h"
#include "IRPrinter.h"
#include "IRDiffer.h"
#include "type.h"
using namespace std;
using namespace antlr4;
using namespace Boost::Internal;

int main(int argc, const char *argv[]) {
    std::ifstream stream;
    stream.open("input.kernel");
    ANTLRInputStream input(stream);
    kernelLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    kernelParser parser(&tokens);
    kernelParser::ProgContext *tree = parser.prog();
    //kernel2IRVisitor visitor;
    //antlrcpp::Any p=visitor.visitStart(tree);
    //simpleVisitor visitor;
    //antlrcpp::Any p=visitor.visitStart(tree);
    Kernel2IRVisitor visitor;
    vector<Stmt> stmtList = visitor.visit(tree).as<vector<Stmt> >();
    vector<string> grad_to;
    grad_to.push_back("B");
    grad_to.push_back("C");
    /*vector<Stmt> stmtList;

    Type data_type = Type::float_scalar(32);
    Type index_type = Type::int_scalar(32);

    const int N = 256;
    const int C = 1024;
    const int P = 7;
    const int Q = 7;
    const int H = 9;
    const int W = 9;
    const int K = 1024;
    const int R = 3;
    const int S = 3;

    // index n
    Expr dom_n = Dom::make(index_type, 0, N);
    Expr n = Index::make(index_type, "n", dom_n, IndexType::Spatial);

    // index k
    Expr dom_k = Dom::make(index_type, 0, K);
    Expr k = Index::make(index_type, "k", dom_k, IndexType::Spatial);

    // index p
    Expr dom_p = Dom::make(index_type, 0, P);
    Expr p = Index::make(index_type, "p", dom_p, IndexType::Spatial);

    // index q
    Expr dom_q = Dom::make(index_type, 0, Q);
    Expr q = Index::make(index_type, "q", dom_q, IndexType::Spatial);

    // index c
    Expr dom_c = Dom::make(index_type, 0, C);
    Expr c = Index::make(index_type, "c", dom_c, IndexType::Reduce);

    // index h
    Expr dom_h = Dom::make(index_type, 0, H);
    Expr h = Index::make(index_type, "h", dom_h, IndexType::Spatial);

    // index w
    Expr dom_w = Dom::make(index_type, 0, W);
    Expr w = Index::make(index_type, "w", dom_w, IndexType::Spatial);

    // index r
    Expr dom_r = Dom::make(index_type, 0, R);
    Expr r = Index::make(index_type, "r", dom_r, IndexType::Reduce);

    // index s
    Expr dom_s = Dom::make(index_type, 0, S);
    Expr s = Index::make(index_type, "s", dom_s, IndexType::Reduce);

    // I
    Expr expr_I = Var::make(data_type, "I",
        {n, c, Binary::make(index_type, BinaryOpType::Add, p, r),
               Binary::make(index_type, BinaryOpType::Add, q, s)},
        {N, C, H, W});

    // W
    Expr expr_W = Var::make(data_type, "W", {k, c, r, s}, {K, C, R, S});

    // O
    Expr expr_O = Var::make(data_type, "O", {n, k, p, q}, {N, K, P, Q});

    // main stmt
    Stmt main_stmt = Move::make(
        expr_O,
        Binary::make(data_type, BinaryOpType::Add, expr_O,
            Binary::make(data_type, BinaryOpType::Mul, expr_I, expr_W)),
        MoveType::MemToMem
    );

    stmtList.push_back(main_stmt);*/

    vector<Stmt> bodyList;
    map<string, vector<size_t> > allTempList;
    set<string> ins, outs;
    for (auto stmt : stmtList) {
        vector<Stmt> newStmtList;
        for (auto g : grad_to) {
            IRDiffer differ;
            differ.grad_to = g;
            Stmt newStmt = differ.mutate(stmt).as<Stmt>();
            newStmtList.push_back(newStmt);
        }

        for (auto newStmt : newStmtList) {
            IRVisitor visitor;
            newStmt.visit_stmt(&visitor);
            for (auto tmp : visitor.boundTable)
                cout << tmp.first << " [" << tmp.second.first <<  ", " << tmp.second.second << ")" << endl;
            cout << endl;
            for (auto in : visitor.in)
                ins.insert(in);
            for (auto out : visitor.out)
                outs.insert(out);
            /*for (size_t i = 0; i < visitor.indexTable.size(); ++i) {
                cout << i << " {";
                for (auto tmp2 : visitor.indexTable[i])
                    cout << tmp2 << ", ";
                cout << "$}" << endl;
            }
            cout << endl;*/

            IRMutator mutator;
            mutator.boundTable = visitor.boundTable;
            vector<Stmt> tmp = mutator.mutate(newStmt).as<vector<Stmt> >();
            for (Stmt s : tmp)
                bodyList.push_back(s);
            for (auto p : mutator.tempList)
                allTempList.insert(p);
        }
    }

    for (auto p : allTempList) {
        cout << p.first << ": (";
        for (size_t l : p.second)
            cout << l << ", ";
        cout << "$)" << endl;
    }

    cout << "ins: (";
    for (auto in : ins) {
        cout << in << ", ";
    }
    cout << "$)" << endl;

    cout << "outs: (";
    for (auto out : outs) {
        cout << out << ", ";
    }
    cout << "$)" << endl;

    for (Stmt s : bodyList) {
        IRPrinter printer;
        string code = printer.print(s);
        cout << code;
    }
    return 0;
}

