/*
 * MIT License
 * 
 * Copyright (c) 2020 Size Zheng

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#ifndef BOOST_IRMUTATOR_H
#define BOOST_IRMUTATOR_H

#include "IR.h"
#include <vector>
#include <map>
#include <set>
#include "antlr4-runtime.h"

using namespace std;
using namespace antlr4;

namespace Boost {

namespace Internal {

class IRMutator {
 public:
    antlrcpp::Any mutate(const Expr&);
    antlrcpp::Any mutate(const Stmt&);
    antlrcpp::Any mutate(const Group&);

    virtual antlrcpp::Any visit(Ref<const IntImm>);
    virtual antlrcpp::Any visit(Ref<const UIntImm>);
    virtual antlrcpp::Any visit(Ref<const FloatImm>);
    virtual antlrcpp::Any visit(Ref<const StringImm>);
    virtual antlrcpp::Any visit(Ref<const Unary>);
    virtual antlrcpp::Any visit(Ref<const Binary>);
    virtual antlrcpp::Any visit(Ref<const Select>);
    virtual antlrcpp::Any visit(Ref<const Compare>);
    virtual antlrcpp::Any visit(Ref<const Call>);
    virtual antlrcpp::Any visit(Ref<const Var>);
    virtual antlrcpp::Any visit(Ref<const Cast>);
    virtual antlrcpp::Any visit(Ref<const Ramp>);
    virtual antlrcpp::Any visit(Ref<const Index>);
    virtual antlrcpp::Any visit(Ref<const Dom>);
    virtual antlrcpp::Any visit(Ref<const LoopNest>);
    virtual antlrcpp::Any visit(Ref<const IfThenElse>);
    virtual antlrcpp::Any visit(Ref<const IfThen>);
    virtual antlrcpp::Any visit(Ref<const Move>);
    virtual antlrcpp::Any visit(Ref<const Kernel>);

    bool inFactor, isLeft, inIndex;
    map<string, pair<int, int> > boundTable;
    map<string, Expr> leftIDTable, currentIDTable;
    set<string> isLeftID;
    Expr temp;
    vector<pair<Expr, int> > currentExprBound;
    Type index_type = Type::int_scalar(32);
    Type data_type = Type::float_scalar(32);
    BinaryOpType type;
 private:
};

}  // namespace Internal

}  // namespace Boost


#endif  // BOOST_IRMUTATOR_H