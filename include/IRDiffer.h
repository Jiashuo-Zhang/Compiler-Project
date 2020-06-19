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

#ifndef BOOST_IRDIFFER_H
#define BOOST_IRDIFFER_H

#include <string>
#include <sstream>

#include "IRMutator.h"


namespace Boost {

namespace Internal {

class IRDiffer : public IRMutator {
 public:
    IRDiffer() : IRMutator() {}

    antlrcpp::Any mutate(const Expr&);
    antlrcpp::Any mutate(const Stmt&);
    antlrcpp::Any mutate(const Group&);

    antlrcpp::Any visit(Ref<const IntImm>) override;
    antlrcpp::Any visit(Ref<const UIntImm>) override;
    antlrcpp::Any visit(Ref<const FloatImm>) override;
    antlrcpp::Any visit(Ref<const StringImm>) override;
    antlrcpp::Any visit(Ref<const Unary>) override;
    antlrcpp::Any visit(Ref<const Binary>) override;
    antlrcpp::Any visit(Ref<const Select>) override;
    antlrcpp::Any visit(Ref<const Compare>) override;
    antlrcpp::Any visit(Ref<const Call>) override;
    antlrcpp::Any visit(Ref<const Var>) override;
    antlrcpp::Any visit(Ref<const Cast>) override;
    antlrcpp::Any visit(Ref<const Ramp>) override;
    antlrcpp::Any visit(Ref<const Index>) override;
    antlrcpp::Any visit(Ref<const Dom>) override;
    antlrcpp::Any visit(Ref<const LoopNest>) override;
    antlrcpp::Any visit(Ref<const IfThenElse>) override;
    antlrcpp::Any visit(Ref<const IfThen>) override;
    antlrcpp::Any visit(Ref<const Move>) override;
    antlrcpp::Any visit(Ref<const Kernel>) override;

    string grad_to;
    Expr dOutput, dInput;
};

}  // namespace Internal

}  // namespace Boost


#endif  // BOOST_IRPRINTER_H