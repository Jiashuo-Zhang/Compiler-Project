#include <iostream>
#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/kernelLexer.h"
#include "antlr4-runtime/kernelParser.h"
#include "antlr4-runtime/simpleVisitor.h"
using namespace std;
using namespace antlr4;
int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open("input.kernel");
    
    ANTLRInputStream input(stream);
    kernelLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    kernelParser parser(&tokens);
    kernelParser::ProgContext* tree = parser.prog();
    simpleVisitor visitor;
    antlrcpp::Any p=visitor.visitStart(tree);

    return 0;
}
