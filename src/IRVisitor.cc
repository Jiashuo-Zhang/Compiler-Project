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

#include "IRVisitor.h"

namespace Boost {

namespace Internal {


void IRVisitor::visit(Ref<const IntImm> op) { /**/
    if (inIndex)
        imm = op->value();
    return;
}


void IRVisitor::visit(Ref<const UIntImm> op) {
    return;
}


void IRVisitor::visit(Ref<const FloatImm> op) {
    return;
}


void IRVisitor::visit(Ref<const StringImm> op) {
    return;
}


void IRVisitor::visit(Ref<const Unary> op) {
    (op->a).visit_expr(this);
    return;
}


void IRVisitor::visit(Ref<const Binary> op) { /**/
    if (inIndex) {
        bool isImm = false;
        //printf("%d %d\n", (op->a).node_type(), (op->b).node_type());
        //printf("%d\n",op->op_type);
        isImm = ((op->b).node_type() == IRNodeType::IntImm);
        if (isImm) {
            (op->b).visit_expr(this);
            if (op->op_type == BinaryOpType::Add) {
                pair<int,int> tmp = currentBound;
                currentBound.first -= imm;
                currentBound.second -= imm;
                (op->a).visit_expr(this);
                currentBound = tmp;
            } else if (op->op_type == BinaryOpType::Sub) {
                pair<int,int> tmp = currentBound;
                currentBound.first += imm;
                currentBound.second += imm;
                (op->a).visit_expr(this);
                currentBound = tmp;
            } else if (op->op_type == BinaryOpType::Mul) {
                pair<int,int> tmp = currentBound;
                if (imm < 0) {
                    imm = -imm;
                    int tmpa, tmpb;
                    tmpa = currentBound.second;
                    tmpb = currentBound.first;
                    currentBound.first = -tmpb + 1;
                    currentBound.second = -tmpa + 1;
                }
                currentBound.first /= imm;
                currentBound.second = (currentBound.second + imm - 1) / imm;
                (op->a).visit_expr(this);
                currentBound = tmp;
            } else if (op->op_type == BinaryOpType::Div) {
                pair<int,int> tmp = currentBound;
                if (imm < 0) {
                    imm = -imm;
                    int tmpa, tmpb;
                    tmpa = currentBound.second;
                    tmpb = currentBound.first;
                    currentBound.first = -tmpb + 1;
                    currentBound.second = -tmpa + 1;
                }
                if (currentBound.first >= 0)
                    currentBound.first *= imm;
                else
                    currentBound.first = currentBound.first * imm - imm + 1;
                if (currentBound.second > 0)
                    currentBound.second *= imm;
                else
                    currentBound.second = currentBound.second * imm - imm + 1;
                (op->a).visit_expr(this);
                currentBound = tmp;
            } else if (op->op_type == BinaryOpType::Mod) {
                isUpdate = false;
                (op->a).visit_expr(this);
                isUpdate = true;
            }
        } else {
            (op->a).visit_expr(this);
            (op->b).visit_expr(this);
        }
    } else {
        (op->a).visit_expr(this);
        (op->b).visit_expr(this);
    }
    return;
}


void IRVisitor::visit(Ref<const Compare> op) {
    (op->a).visit_expr(this);
    (op->b).visit_expr(this);
    return;
}


void IRVisitor::visit(Ref<const Select> op) {
    (op->cond).visit_expr(this);
    (op->true_value).visit_expr(this);
    (op->false_value).visit_expr(this);
    return;
}


void IRVisitor::visit(Ref<const Call> op) {
    for (auto arg : op->args) {
        arg.visit_expr(this);
    }
    return;
}


void IRVisitor::visit(Ref<const Cast> op) {
    (op->val).visit_expr(this);
    return;
}


void IRVisitor::visit(Ref<const Ramp> op) {
    (op->base).visit_expr(this);
    return;
}


void IRVisitor::visit(Ref<const Var> op) { /**/
    varShapeTable[op->name] = vector<size_t>(op->shape);
    for (size_t i = 0; i < op->args.size(); ++i) {
        currentBound = pair<int,int>(0, op->shape[i]);
        inIndex = true;
        isUpdate = true;
        op->args[i].visit_expr(this);
        isUpdate = true;
        inIndex = false;
    }
    if (isLeft) {
        out.insert(op->name);
    } else {
        in.insert(op->name);
    }
    return;
}


void IRVisitor::visit(Ref<const Dom> op) {
    (op->begin).visit_expr(this);
    (op->extent).visit_expr(this);
    return;
}


void IRVisitor::visit(Ref<const Index> op) { /**/
    if (isUpdate) {
        auto iter = boundTable.find(op->name);
        if (iter == boundTable.end())
            boundTable.insert(make_pair(op->name, currentBound));
        else {
            pair<int, int> tmp = iter->second;
            tmp.first = max(tmp.first, currentBound.first);
            tmp.second = min(tmp.second, currentBound.second);
            boundTable[op->name] = tmp;
        }
    }
    (op->dom).visit_expr(this);
    return;
}


void IRVisitor::visit(Ref<const LoopNest> op) {
    for (auto index : op->index_list) {
        index.visit_expr(this);
    }
    for (auto body : op->body_list) {
        body.visit_stmt(this);
    }
    return;
}


void IRVisitor::visit(Ref<const IfThenElse> op) {
    (op->cond).visit_expr(this);
    (op->true_case).visit_stmt(this);
    (op->false_case).visit_stmt(this);
    return;
}

void IRVisitor::visit(Ref<const IfThen> op) {
    return;
}


void IRVisitor::visit(Ref<const Move> op) { /**/
    inIndex = false;
    isLeft = true;
    (op->dst).visit_expr(this);
    isLeft = false;
    (op->src).visit_expr(this);
    return;
}


void IRVisitor::visit(Ref<const Kernel> op) {
    for (auto expr : op->inputs) {
        expr.visit_expr(this);
    }
    for (auto expr : op->outputs) {
        expr.visit_expr(this);
    }
    for (auto stmt : op->stmt_list) {
        stmt.visit_stmt(this);
    }
    return;
}



}  // namespace Internal

}  // namespace Boost
