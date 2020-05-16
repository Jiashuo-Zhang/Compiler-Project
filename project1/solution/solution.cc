// this is a silly solution
// just to show you how different
// components of this framework work
// please bring your wise to write
// a 'real' solution :)

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

#include "antlr4-runtime.h"
#include "kernelLexer.h"
#include "kernelParser.h"
#include "Kernel2IRVisitor.h"
#include "IR.h"
#include "IRMutator.h"
#include "IRVisitor.h"
#include "IRPrinter.h"
#include "type.h"

using namespace std;


int main() {
    FILE *fcc = fopen("./kernels/kernel_case1.cc", "r");
    char buf[4096];
    memset(buf, 0, 4096);
    int cnt = fread(buf, 1, 4096, fcc);
    buf[cnt - 1] = buf[cnt - 2] = 0;
    cnt -= 2;
    fclose(fcc);
    
    string data_type = "float";

    std::ofstream temp;
    temp.open("input.kernel");
    temp.clear();
    temp << "A<32, 16>[i, j] = 2;";
    temp.close();

    std::ofstream result;
    result.open("./kernels/kernel_case1.cc");
    result.clear();
    result << buf << " {\n";

    std::ifstream stream;
    stream.open("input.kernel");
    ANTLRInputStream input(stream);
    kernelLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    kernelParser parser(&tokens);
    kernelParser::ProgContext* tree = parser.prog();

    Kernel2IRVisitor visitor;
    vector<Stmt> stmtList = visitor.visit(tree).as<vector<Stmt> >();

    vector<Stmt> bodyList;
    map<string, vector<size_t> > allTempList;
    for (auto stmt : stmtList) {
        IRVisitor visitor;
        stmt.visit_stmt(&visitor);
        for (auto tmp : visitor.boundTable)
            cout << tmp.first << " [" << tmp.second.first <<  ", " << tmp.second.second << ")" << endl;
        cout << endl;
        IRMutator mutator;
        mutator.boundTable = visitor.boundTable;
        vector<Stmt> tmp = mutator.mutate(stmt).as<vector<Stmt> >();
        for (Stmt s : tmp)
            bodyList.push_back(s);
        for (auto p : mutator.tempList)
            allTempList.insert(p);
    }

    for (auto p : allTempList) {
        result << " " << data_type << " " << p.first;
        for (size_t l : p.second)
            result << "[" << l << "]";
        result << ";\n";
    }

    for (Stmt s : bodyList) {
        IRPrinter printer;
        string code = printer.print(s);
        result << code;
    }

    result << "}\n";
    result.close();
    return 0;
}