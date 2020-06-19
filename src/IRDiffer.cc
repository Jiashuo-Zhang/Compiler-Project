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

#include "IRDiffer.h"

using namespace antlr4;

namespace Boost {

namespace Internal {

antlrcpp::Any IRDiffer::mutate(const Expr &expr) {
    return expr.mutate_expr(this);
}


antlrcpp::Any IRDiffer::mutate(const Stmt &stmt) {
    return stmt.mutate_stmt(this);
}


antlrcpp::Any IRDiffer::mutate(const Group &group) {
    return group.mutate_group(this);
}


antlrcpp::Any IRDiffer::visit(Ref<const IntImm> op) {
    if (inIndex) {
        return Expr(op->value());
    } else {
        return make_pair(Expr(0), false);
    }
}


antlrcpp::Any IRDiffer::visit(Ref<const UIntImm> op) {
    if (inIndex) {
        return Expr(op->value());
    } else {
        return make_pair(Expr(0), false);
    }
}


antlrcpp::Any IRDiffer::visit(Ref<const FloatImm> op) {
    if (inIndex) {
        return Expr(op->value());
    } else {
        return make_pair(Expr(0), false);
    }
}


antlrcpp::Any IRDiffer::visit(Ref<const StringImm> op) {
    return op;
}


antlrcpp::Any IRDiffer::visit(Ref<const Unary> op) {
    pair<Expr, bool> new_a = mutate(op->a).as<pair<Expr, bool> >();
    if (new_a.second) {
        return make_pair(new_a.first, true);
    } else {
        return make_pair(Expr(0), false);
    }
}


antlrcpp::Any IRDiffer::visit(Ref<const Binary> op) {
    if (!inIndex) {
        if (op->op_type == BinaryOpType::Add || op->op_type == BinaryOpType::Sub) {
            pair<Expr, bool> new_a = mutate(op->a).as<pair<Expr, bool> >();
            pair<Expr, bool> new_b = mutate(op->b).as<pair<Expr, bool> >();
            if (new_a.second && new_b.second) {
                return make_pair(Binary::make(op->type(), op->op_type, new_a.first, new_b.first), true);
            } else if (new_a.second) {
                return make_pair(new_a.first, true);
            } else if (new_b.second) {
                return make_pair(new_b.first, true);
            } else {
                return make_pair(Expr(0), false);
            }
        } else if (op->op_type == BinaryOpType::Mul) {
            pair<Expr, bool> new_a = mutate(op->a).as<pair<Expr, bool> >();
            pair<Expr, bool> new_b = mutate(op->b).as<pair<Expr, bool> >();

            if (new_a.second && new_b.second) {
                Expr exp1 = Binary::make(op->type(), op->op_type, new_a.first, op->b);
                Expr exp2 = Binary::make(op->type(), op->op_type, op->a, new_b.first);
                return make_pair(Binary::make(op->type(), BinaryOpType::Add, exp1, exp2), true);
            } else if (new_a.second) {
                return make_pair(Binary::make(op->type(), op->op_type, new_a.first, op->b), true);
            } else if (new_b.second) {
                return make_pair(Binary::make(op->type(), op->op_type, op->a, new_b.first), true);
            } else {
                return make_pair(Expr(0), false);
            }
        } else if (op->op_type == BinaryOpType::Div) {
            pair<Expr, bool> new_a = mutate(op->a).as<pair<Expr, bool> >();
            if (new_a.second) {
                return make_pair(Binary::make(op->type(), op->op_type, new_a.first, op->b), true);
            } else {
                return make_pair(Expr(0), false);
            }
        } else {
            // do nothing
        }
    } else {
        Expr new_a = mutate(op->a).as<Expr>();
        Expr new_b = mutate(op->b).as<Expr>();
        return Binary::make(op->type(), op->op_type, new_a, new_b);
    }
}


antlrcpp::Any IRDiffer::visit(Ref<const Compare> op) {
    Expr new_a = mutate(op->a);
    Expr new_b = mutate(op->b);
    return Compare::make(op->type(), op->op_type, new_a, new_b);
}


antlrcpp::Any IRDiffer::visit(Ref<const Select> op) {
    Expr new_cond = mutate(op->cond);
    Expr new_true_value = mutate(op->true_value);
    Expr new_false_value = mutate(op->false_value);
    return Select::make(op->type(), new_cond, new_true_value, new_false_value);
}


antlrcpp::Any IRDiffer::visit(Ref<const Call> op) {
    std::vector<Expr> new_args;
    for (auto arg : op->args) {
        new_args.push_back(mutate(arg));
    }
    return Call::make(op->type(), new_args, op->func_name, op->call_type);

}


antlrcpp::Any IRDiffer::visit(Ref<const Cast> op) {
    Expr new_val = mutate(op->val);
    return Cast::make(op->type(), op->new_type, new_val);
}


antlrcpp::Any IRDiffer::visit(Ref<const Ramp> op) {
    Expr new_base = mutate(op->base);
    return Ramp::make(op->type(), new_base, op->stride, op->lanes);
}


antlrcpp::Any IRDiffer::visit(Ref<const Var> op) {
    std::vector<Expr> new_args;
    for (auto arg : op->args) {
        inIndex = true;
        Expr tmp = mutate(arg).as<Expr>();
        inIndex = false;
        new_args.push_back(tmp);
    }
    if (isLeft) {
        return Var::make(op->type(), "d" + op->name, new_args, op->shape);
    } else {
        if (op->name == grad_to) {
            dInput = Var::make(op->type(), "d" + op->name, new_args, op->shape);
            return make_pair(dOutput, true);
        } else {
            return make_pair(Expr(0), false);
        }
    }
}


antlrcpp::Any IRDiffer::visit(Ref<const Dom> op) {
    Expr new_begin = mutate(op->begin);
    Expr new_extent = mutate(op->extent);
    return Dom::make(op->type(), new_begin, new_extent);
}


antlrcpp::Any IRDiffer::visit(Ref<const Index> op) {
    Expr new_dom = mutate(op->dom);
    return Index::make(op->type(), op->name, new_dom, op->index_type);
}


antlrcpp::Any IRDiffer::visit(Ref<const LoopNest> op) {
    std::vector<Expr> new_index_list;
    std::vector<Stmt> new_body_list;
    for (auto index : op->index_list) {
        new_index_list.push_back(mutate(index));
    }
    for (auto body : op->body_list) {
        new_body_list.push_back(mutate(body));
    }
    return LoopNest::make(new_index_list, new_body_list);
}


antlrcpp::Any IRDiffer::visit(Ref<const IfThenElse> op) {
    Expr new_cond = mutate(op->cond);
    Stmt new_true_case = mutate(op->true_case);
    Stmt new_false_case = mutate(op->false_case);
    return IfThenElse::make(new_cond, new_true_case, new_false_case);
}

antlrcpp::Any IRDiffer::visit(Ref<const IfThen> op) {
    return op;
}

antlrcpp::Any IRDiffer::visit(Ref<const Move> op) {
    inIndex = false;
    isLeft = true;
    dOutput = mutate(op->dst).as<Expr>();
    isLeft = false;
    pair<Expr, bool> rightExp = mutate(op->src).as<pair<Expr, bool> >();
    Expr new_src;
    if (rightExp.second)
        new_src = rightExp.first;
    else
        new_src = Expr(0);
    return Move::make(dInput, new_src, op->move_type);
}


antlrcpp::Any IRDiffer::visit(Ref<const Kernel> op) {
    std::vector<Expr> new_inputs;
    for (auto expr : op->inputs) {
        new_inputs.push_back(mutate(expr));
    }
    std::vector<Expr> new_outputs;
    for (auto expr : op->outputs) {
        new_outputs.push_back(mutate(expr));
    }
    std::vector<Stmt> new_stmt_list;
    for (auto stmt : op->stmt_list) {
        new_stmt_list.push_back(mutate(stmt));
    }
    return Kernel::make(op->name, new_inputs, new_outputs, new_stmt_list, op->kernel_type);
}


}  // namespace Internal

}  // namespace Boost
