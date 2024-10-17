//
// Created by yuyuan on 2024/10/13.
//

#include "../include/node.h"

void Node::forward() {
    if (op_) {
        std::vector<double> input_values;
        for (const auto& input : inputs_) {
            input->forward();
            input_values.push_back(input->value_);
        }
        // 计算value
        value_ = op_->forward(input_values);

    }
}

void Node::backward() {
    if (op_) {
        std::vector<double> input_values;
        std::vector<double> grad_inputs(inputs_.size(), 0.0);
        for (const auto& input : inputs_) {
            input_values.push_back(input->value_);
        }
        op_->backward(input_values, {grad_}, grad_inputs);

        for (size_t i = 0; i < inputs_.size(); ++i) {
            inputs_[i]->grad_ += grad_inputs[i];
        }
    }
}

void Node::resetGradients()
{
    grad_ = 0.0;
    for(const auto& input : inputs_)
    {
        input->resetGradients();
    }
}


void computeGradients(const std::shared_ptr<Node>& node) {

    node->grad_ = 1.0;

    std::vector<std::shared_ptr<Node>> stack{node};
    while (!stack.empty()) {
        const auto current = stack.back();
        stack.pop_back();
        current->backward();
        for (const auto& input : current->inputs_) {
            stack.push_back(input);
        }
    }
}