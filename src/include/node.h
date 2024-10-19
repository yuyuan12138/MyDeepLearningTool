//
// Created by yuyuan on 2024/10/13.
//

#ifndef NODE_H
#define NODE_H

#include <vector>
#include <memory>

#include "twoParameterOperation.h"

class Node {
public:
    double value_;   // Value of Node
    double grad_;    // gradient of Node
    std::vector<std::shared_ptr<Node>> inputs_; // vector of input nodes.
    std::shared_ptr<TwoParameterOperation::BasicOperation> op_;

    explicit Node(const double val) : value_(val), grad_(0.0) {}
    Node(std::shared_ptr<TwoParameterOperation::BasicOperation> operation, const std::vector<std::shared_ptr<Node>>& input_nodes)
        : value_(0.0), grad_(0.0),  inputs_(input_nodes), op_(std::move(operation))
    {
    }

    void forward();

    void backward();

    void resetGradients();


};

void computeGradients(const std::shared_ptr<Node>& node);

#endif //NODE_H
