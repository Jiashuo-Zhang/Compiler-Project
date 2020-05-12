#include <iostream>
#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/kernelLexer.h"
#include "antlr4-runtime/kernelParser.h"
#include "Kernel2IRVisitor.h"
#include "IRPrinter.h"
#include "type.h"
#include "IR.h"
using namespace std;
using namespace antlr4;
using namespace Boost::Internal;

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open("input.kernel");
    ANTLRInputStream input(stream);
    kernelLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    kernelParser parser(&tokens);
    kernelParser::ProgContext* tree = parser.prog();
    //kernel2IRVisitor visitor;
    //antlrcpp::Any p=visitor.visitStart(tree);
   // simpleVisitor visitor;
    //antlrcpp::Any p=visitor.visitStart(tree);
    Kernel2IRVisitor visitor;
    vector<Stmt> p=visitor.visit(tree).as<vector<Stmt>>();
   
   
    IRPrinter printer;
    //std::string code = printer.print(kernel);
    string code =printer.print(p[0]);
    cout<<code<<endl;
    return 0;
}

