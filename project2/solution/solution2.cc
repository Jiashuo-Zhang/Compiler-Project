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

extern vector<string> grad_to;

int main() {
    stringstream ss;

    string data_type;
    string name;
    string json_filename;
    string filename;
    string kernel;

    Json::Reader reader;
    Json::Value root;

    for(int i = 1;i <= 10;++i) {
        ss.clear();
        ss << "./kernels/grad_case" << i << ".cc";
        ss >> filename;
        ss.clear();
        ss << "./cases/case" << i << ".json";
        ss >> json_filename;

        char json_buf[4096];
        memset(json_buf, 0, 4096);
        FILE *fcase = fopen(json_filename.c_str(), "r");
        if(!fcase)
            continue;
        fread(json_buf, 1, 4096, fcase);
        reader.parse(json_buf, root);
        kernel = root["kernel"].asString();
        data_type = root["data_type"].asString();
        name = root["name"].asString();
        grad_to = root["grad_to"].asString();

        std::ofstream temp;
        temp.open("input.kernel");
        temp.clear();
        temp << kernel;
        temp.close();

        std::ofstream result;
        result.open(filename);
        result.clear();
        result << "#include \"../run2.h\"\n\n";

        std::ifstream stream;
        stream.open("input.kernel");
        ANTLRInputStream input(stream);
        kernelLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        kernelParser parser(&tokens);
        kernelParser::ProgContext* tree = parser.prog();

        Kernel2IRVisitor kvisitor;
        vector<Stmt> stmtList = kvisitor.visit(tree).as<vector<Stmt> >();

        vector<Stmt> bodyList;
        map<string, vector<size_t> > allTempList;
        IRVisitor visitor;
        for (auto stmt : stmtList) {
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

        result << "void " << name << '(';
        bool first = true;
        set<string> arg_set;
        for(int i = 0;i < root["ins"].size();++i) {
            string arg_name = root["ins"][i].asString();
            arg_set.insert(arg_name);
            auto shape = visitor.varShapeTable[arg_name];
            if(!first)
                result << ", ";
            first = false;
            if(shape.size() == 1 && shape[0] == 1){
                result << data_type << " &" << arg_name;
                continue;
            }
            result << data_type << " (&" << arg_name << ")";
            for(auto l : shape) {
                result << "[" << l << "]";
            } 
        }
        for(int i = 0;i < root["outs"].size();++i) {
            string arg_name = root["outs"][i].asString();
            if(arg_set.count(arg_name))
                continue;
            if(!first)
                result << ", ";
            first = false;
            auto shape = visitor.varShapeTable[arg_name];
            if(shape.size() == 1 && shape[0] == 1){
                result << data_type << " &" << arg_name;
                continue;
            }
            result << data_type << " (&" << arg_name << ")";
            for(auto l : shape) {
                result << "[" << l << "]";
            } 
        }
        result << ") {\n";

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