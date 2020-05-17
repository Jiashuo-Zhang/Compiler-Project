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

#include "json/json.h"

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
    stringstream ss;

    string data_type;
    string json_filename;
    string filename;
    string kernel;

    Json::Reader reader;
    Json::Value root;

    for(int i = 0;i <= 10;++i) {
        ss.clear();
        ss << "./kernels/kernel_case" << i << ".cc";
        ss >> filename;
        ss.clear();
        ss << "./cases/case" << i << ".json";
        ss >> json_filename;

        if(i == 0) {
            filename = "./kernels/kernel_example.cc";
            json_filename = "./cases/example.json";
        }

        FILE *fcc = fopen(filename.c_str(), "r");
        if(!fcc)
            continue;
        char buf[4096];
        memset(buf, 0, 4096);
        int cnt = fread(buf, 1, 4096, fcc);
        buf[cnt - 1] = buf[cnt - 2] = 0;
        cnt -= 2;
        fclose(fcc);

        char json_buf[4096];
        memset(json_buf, 0, 4096);
        FILE *fcase = fopen(json_filename.c_str(), "r");
        fread(json_buf, 1, 4096, fcase);
        reader.parse(json_buf, root);
        kernel = root["kernel"].asString();
        data_type = root["data_type"].asString();

        std::ofstream temp;
        temp.open("input.kernel");
        temp.clear();
        temp << kernel;
        temp.close();

        std::ofstream result;
        result.open(filename);
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
    }
    return 0;
}