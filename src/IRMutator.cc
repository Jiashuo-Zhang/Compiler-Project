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

#include "IRMutator.h"

using namespace antlr4;

namespace Boost {

namespace Internal {

antlrcpp::Any IRMutator::mutate(const Expr &expr) {
    return expr.mutate_expr(this);
}


antlrcpp::Any IRMutator::mutate(const Stmt &stmt) {
    return stmt.mutate_stmt(this);
}


antlrcpp::Any IRMutator::mutate(const Group &group) {
    return group.mutate_group(this);
}


antlrcpp::Any IRMutator::visit(Ref<const IntImm> op) {
    return Expr(op->value());
}


antlrcpp::Any IRMutator::visit(Ref<const UIntImm> op) {
    return Expr(op->value());
}


antlrcpp::Any IRMutator::visit(Ref<const FloatImm> op) {
    return Expr(op->value());
}


antlrcpp::Any IRMutator::visit(Ref<const StringImm> op) {
    return op;
}


antlrcpp::Any IRMutator::visit(Ref<const Unary> op) {
    if (op->op_type != UnaryOpType::Id) {
        Expr new_a = mutate(op->a);
        return Unary::make(op->type(), op->op_type, new_a);
    }
    if (!inIndex) {
        if (!inFactor) {
            currentIDTable.clear();
            currentExprBound.clear();
            inFactor = true;
            Expr new_a = mutate(op->a).as<Expr>();
            inFactor = false;
                
            vector<Expr> currentID;
            for (auto p : currentIDTable)
                if (isLeftID.find(p.first) == isLeftID.end())
                    currentID.push_back(p.second);

            Stmt body = Move::make(temp, Binary::make(data_type, type, temp, new_a), MoveType::MemToMem);

            size_t len = currentExprBound.size();
            for (size_t i = 0; i < len; ++i) {
                Expr tmp1 = Compare::make(index_type, CompareOpType::GE, currentExprBound[i].first, Expr(0));
                Expr tmp2 = Compare::make(index_type, CompareOpType::LT, currentExprBound[i].first, Expr(currentExprBound[i].second));
                Expr tmp = Binary::make(index_type, BinaryOpType::And, tmp1, tmp2);
                body = IfThen::make(tmp, {body});
            }

            if (currentID.size() > 0)
                body = LoopNest::make(currentID, {body});

            currentIDTable.clear();
            currentExprBound.clear();
                
            vector<Stmt> res;
            res.push_back(body);
            return res;
        } else {
            Expr new_a = mutate(op->a);
            return Unary::make(op->type(), op->op_type, new_a);
        }
    } else {
        Expr new_a = mutate(op->a);
        return Unary::make(op->type(), op->op_type, new_a);
    }
}


antlrcpp::Any IRMutator::visit(Ref<const Binary> op) { /**/
    /*std::cout << (int)op->op_type << "op {";
    for (auto s : *(op->usedIndex))
        std::cout << s << ", ";
    std::cout << "$}" << std::endl;*/
    if (!inIndex) {
        if (!inFactor) {
            if (op->op_type == BinaryOpType::Add || op->op_type == BinaryOpType::Sub) {
                currentIDTable.clear();
                currentExprBound.clear();
                vector<Stmt> new_a = mutate(op->a).as<vector<Stmt> >();
                currentIDTable.clear();
                currentExprBound.clear();
                type = op->op_type;
                vector<Stmt> new_b = mutate(op->b).as<vector<Stmt> >();
                currentIDTable.clear();
                currentExprBound.clear();
                vector<Stmt> res;
                for (Stmt s : new_a)
                    res.push_back(s);
                for (Stmt s : new_b)
                    res.push_back(s);
                return res;
            } else {
                currentIDTable.clear();
                currentExprBound.clear();
                inFactor = true;
                Expr new_a = mutate(op->a).as<Expr>();
                Expr new_b = mutate(op->b).as<Expr>();
                inFactor = false;
                
                vector<Expr> currentID;
                for (auto p : currentIDTable)
                    if (isLeftID.find(p.first) == isLeftID.end())
                        currentID.push_back(p.second);
                
                Expr bin = Binary::make(op->type(), op->op_type, new_a, new_b);
                Stmt body = Move::make(temp, Binary::make(data_type, type, temp, bin), MoveType::MemToMem);

                size_t len = currentExprBound.size();
                for (size_t i = 0; i < len; ++i) {
                    Expr tmp1 = Compare::make(index_type, CompareOpType::GE, currentExprBound[i].first, Expr(0));
                    Expr tmp2 = Compare::make(index_type, CompareOpType::LT, currentExprBound[i].first, Expr(currentExprBound[i].second));
                    Expr tmp = Binary::make(index_type, BinaryOpType::And, tmp1, tmp2);
                    body = IfThen::make(tmp, {body});
                }

                if (currentID.size() > 0)
                    body = LoopNest::make(currentID, {body});

                currentIDTable.clear();
                currentExprBound.clear();
                
                vector<Stmt> res;
                res.push_back(body);
                return res;
            }
        } else {
            Expr new_a = mutate(op->a).as<Expr>();
            Expr new_b = mutate(op->b).as<Expr>();
            return Binary::make(op->type(), op->op_type, new_a, new_b);
        }
    } else {
        Expr new_a = mutate(op->a).as<Expr>();
        Expr new_b = mutate(op->b).as<Expr>();
        return Binary::make(op->type(), op->op_type, new_a, new_b);
    }
}


antlrcpp::Any IRMutator::visit(Ref<const Compare> op) {
    Expr new_a = mutate(op->a);
    Expr new_b = mutate(op->b);
    return Compare::make(op->type(), op->op_type, new_a, new_b);
}


antlrcpp::Any IRMutator::visit(Ref<const Select> op) {
    Expr new_cond = mutate(op->cond);
    Expr new_true_value = mutate(op->true_value);
    Expr new_false_value = mutate(op->false_value);
    return Select::make(op->type(), new_cond, new_true_value, new_false_value);
}


antlrcpp::Any IRMutator::visit(Ref<const Call> op) {
    std::vector<Expr> new_args;
    for (auto arg : op->args) {
        new_args.push_back(mutate(arg));
    }
    return Call::make(op->type(), new_args, op->func_name, op->call_type);

}


antlrcpp::Any IRMutator::visit(Ref<const Cast> op) {
    Expr new_val = mutate(op->val);
    return Cast::make(op->type(), op->new_type, new_val);
}


antlrcpp::Any IRMutator::visit(Ref<const Ramp> op) {
    Expr new_base = mutate(op->base);
    return Ramp::make(op->type(), new_base, op->stride, op->lanes);
}


antlrcpp::Any IRMutator::visit(Ref<const Var> op) { /**/
    /*std::cout << *(op->id) << " {";
    for (auto s : *(op->usedIndex))
        std::cout << s << ", ";
    std::cout << "$}" << std::endl;*/
    std::vector<Expr> new_args;
    for (size_t i = 0; i < op->args.size(); ++i) {
        inIndex = true;
        Expr tmp = mutate(op->args[i]).as<Expr>();
        inIndex = false;
        new_args.push_back(tmp);
        currentExprBound.push_back(make_pair(tmp, op->shape[i]));
    }
    if (isLeft) {
        temp = Var::make(op->type(), "temp", new_args, op->shape);
        return Var::make(op->type(), op->name, new_args, op->shape);
    } else {
        if (!inFactor) {
            Expr var = Var::make(op->type(), op->name, new_args, op->shape);
            Expr bin = Binary::make(data_type, type, temp, var);
            Stmt body = Move::make(temp, bin, MoveType::MemToMem);
            size_t len = currentExprBound.size();
            for (size_t i = 0; i < len; ++i) {
                Expr tmp1 = Compare::make(index_type, CompareOpType::GE, currentExprBound[i].first, Expr(0));
                Expr tmp2 = Compare::make(index_type, CompareOpType::LT, currentExprBound[i].first, Expr(currentExprBound[i].second));
                Expr tmp = Binary::make(index_type, BinaryOpType::And, tmp1, tmp2);
                body = IfThen::make(tmp, {body});
            }
            vector<Expr> currentID;
            for (auto p : currentIDTable)
                if (isLeftID.find(p.first) == isLeftID.end())
                    currentID.push_back(p.second);
            if (currentID.size() > 0)
                body = LoopNest::make(currentID, {body});
            currentIDTable.clear();
            currentExprBound.clear();
            vector<Stmt> vec;
            vec.push_back(body);
            return vec;
        }
        return Var::make(op->type(), op->name, new_args, op->shape);
    }
}


antlrcpp::Any IRMutator::visit(Ref<const Dom> op) {
    Expr new_begin = mutate(op->begin);
    Expr new_extent = mutate(op->extent);
    return Dom::make(op->type(), new_begin, new_extent);
}


antlrcpp::Any IRMutator::visit(Ref<const Index> op) { /**/
    pair<int, int> pii = boundTable[op->name];
    Expr new_dom = Dom::make(op->dom->type(), Expr(pii.first), Expr(pii.second - pii.first));
    Expr res = Index::make(op->type(), op->name, new_dom, op->index_type);
    if (isLeft)
        leftIDTable.insert(make_pair(op->name, res));
    else
        currentIDTable.insert(make_pair(op->name, res));
    return res;
}


antlrcpp::Any IRMutator::visit(Ref<const LoopNest> op) {
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


antlrcpp::Any IRMutator::visit(Ref<const IfThenElse> op) {
    Expr new_cond = mutate(op->cond);
    Stmt new_true_case = mutate(op->true_case);
    Stmt new_false_case = mutate(op->false_case);
    return IfThenElse::make(new_cond, new_true_case, new_false_case);
}

antlrcpp::Any IRMutator::visit(Ref<const IfThen> op) { /**/
    return op;
}

antlrcpp::Any IRMutator::visit(Ref<const Move> op) { /**/
    inIndex = false;
    isLeft = true;
    type = BinaryOpType::Add;
    currentExprBound.clear();
    Expr new_dst = mutate(op->dst).as<Expr>();
    isLeft = false;
    vector<Expr> leftID;
    for (auto p : leftIDTable) {
        leftID.push_back(p.second);
        isLeftID.insert(p.first);
    }
    vector<pair<Expr, int> > vec;
    vec.assign(currentExprBound.begin(), currentExprBound.end());
    currentExprBound.clear();
    Stmt init = Move::make(temp, Expr(0), op->move_type);

    inFactor = false;
    vector<Stmt> bodyList = mutate(op->src).as<vector<Stmt> >();
    bodyList.insert(bodyList.begin(), init);
    Stmt loadAtIndex = Move::make(new_dst, temp, op->move_type);

    size_t len = vec.size();
    Expr cond1 = Compare::make(index_type, CompareOpType::GE, vec[0].first, Expr(0));
    Expr cond2 = Compare::make(index_type, CompareOpType::LT, vec[0].first, Expr(vec[0].second));
    Expr cond = Binary::make(index_type, BinaryOpType::And, cond1, cond2);
    Stmt boundedBody = IfThen::make(cond, bodyList);
    loadAtIndex = IfThen::make(cond, {loadAtIndex});

    for (size_t i = 1; i < len; ++i) {
        Expr tmp1 = Compare::make(index_type, CompareOpType::GE, vec[i].first, Expr(0));
        Expr tmp2 = Compare::make(index_type, CompareOpType::LT, vec[i].first, Expr(vec[i].second));
        Expr tmp = Binary::make(index_type, BinaryOpType::And, tmp1, tmp2);
        boundedBody = IfThen::make(tmp, {boundedBody});
        loadAtIndex = IfThen::make(tmp, {loadAtIndex});
    }

    Stmt store = LoopNest::make(leftID, {boundedBody});
    Stmt load = LoopNest::make(leftID, {loadAtIndex});

    vector<Stmt> stmtList;
    stmtList.push_back(store);
    stmtList.push_back(load);
    return stmtList;
}


antlrcpp::Any IRMutator::visit(Ref<const Kernel> op) {
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
