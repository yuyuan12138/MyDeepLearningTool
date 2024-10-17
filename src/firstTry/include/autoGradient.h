//
// Created by yuyuan on 2024/10/12.
//

#ifndef AUTOGRADIENT_H
#define AUTOGRADIENT_H
#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>
#include <cmath>

// Operation calculate x * y. Number * number.
class BasicOperation
{
    public:
    [[nodiscard]] virtual double forward(const std::vector<double>& inputs) const = 0;
    virtual void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const = 0;
    virtual ~BasicOperation() = default;
};

class Node {
public:
    double value;   // Value of Node
    double grad;    // gradient of Node
    std::vector<std::shared_ptr<Node>> inputs; // vector of input nodes.
    std::shared_ptr<BasicOperation> op;

    explicit Node(const double val) : value(val), grad(0.0) {}
    Node(std::shared_ptr<BasicOperation> operation, const std::vector<std::shared_ptr<Node>>& input_nodes)
        : value(0.0), grad(0.0), inputs(input_nodes), op(std::move(operation)) {}

    void forward();

    void backward();

    void resetGradients();
};

class AddOperation : public BasicOperation {
public:
    [[nodiscard]] double forward(const std::vector<double>& inputs) const override ;

    void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const override ;
};

class MultiplyOperation : public BasicOperation {
public:
    [[nodiscard]] double forward(const std::vector<double>& inputs) const override  ;

    void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const override  ;
};

class DivideOperation : public BasicOperation
{
  public:
    [[nodiscard]] double forward(const std::vector<double>& inputs) const override;
    void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const override;
};

class DeleteOperation : public BasicOperation
{
public:
    [[nodiscard]] double forward(const std::vector<double>& inputs) const override;
    void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const override;
};

class PowOperation : public BasicOperation
{
    public:
    [[nodiscard]] double forward(const std::vector<double>& inputs) const override;
    void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const override;
};

class DotProductOperation : public BasicOperation
{
    public:
    [[nodiscard]] double forward(const std::vector<double>& inputs) const override;
    void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const override;
};


std::shared_ptr<Node> makeNode(const std::shared_ptr<BasicOperation>& op, const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b);

std::shared_ptr<Node> operator+(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b);

std::shared_ptr<Node> operator*(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b);

std::shared_ptr<Node> operator/(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b);

std::shared_ptr<Node> operator-(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b);

std::shared_ptr<Node> operator^(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b);

std::shared_ptr<Node> dot(const std::vector<std::shared_ptr<Node>>& vec1, const std::vector<std::shared_ptr<Node>>& vec2);

std::vector<std::shared_ptr<Node>> matmul(const std::vector<std::vector<std::shared_ptr<Node>>>& mat1, const std::vector<std::shared_ptr<Node>>& vec);

void computeGradients(const std::shared_ptr<Node>& node);


#endif //AUTOGRADIENT_H
