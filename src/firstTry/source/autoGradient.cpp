//
// Created by yuyuan on 2024/10/12.
//

#include "../include/autoGradient.h"


void Node::forward() {
    if (op) {
        std::vector<double> input_values;
        for (const auto& input : inputs) {
            input->forward();
            input_values.push_back(input->value);
        }
        value = op->forward(input_values);
    }
}

void Node::backward() {
    if (op) {
        std::vector<double> input_values;
        std::vector<double> grad_inputs(inputs.size(), 0.0);
        for (const auto& input : inputs) {
            input_values.push_back(input->value);
        }
        op->backward(input_values, {grad}, grad_inputs);
        for (size_t i = 0; i < inputs.size(); ++i) {
            inputs[i]->grad += grad_inputs[i];
        }
    }
}

void Node::resetGradients()
{
    grad = 0.0;
    for(const auto& input : inputs)
    {
        input->resetGradients();
    }
}



[[nodiscard]] double AddOperation::forward(const std::vector<double>& inputs) const  {
    return inputs[0] + inputs[1];
}

void AddOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const  {
    grad_inputs[0] = grad_output[0];
    grad_inputs[1] = grad_output[0];
}



[[nodiscard]] double MultiplyOperation::forward(const std::vector<double>& inputs) const  {
    return inputs[0] * inputs[1];
}

void MultiplyOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const  {
    grad_inputs[0] = grad_output[0] * inputs[1];
    grad_inputs[1] = grad_output[0] * inputs[0];
}


[[nodiscard]] double DivideOperation::forward(const std::vector<double>& inputs) const
{
    return inputs[0] / inputs[1];
}
void DivideOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    grad_inputs[0] = grad_output[0] / inputs[1];
    grad_inputs[1] = - grad_output[0] / (inputs[0] * inputs[1]) * inputs[0];
}


[[nodiscard]] double DeleteOperation::forward(const std::vector<double>& inputs) const
{
    return inputs[0] - inputs[1];
}
void DeleteOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    grad_inputs[0] = grad_output[0];
    grad_inputs[1] = -grad_output[0];
}


[[nodiscard]] double PowOperation::forward(const std::vector<double>& inputs) const
{
    return std::pow(inputs[0], inputs[1]);
}
void PowOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    grad_inputs[0] = grad_output[0] * inputs[1] * (pow(inputs[0], inputs[1])) / inputs[0];
    grad_inputs[1] = grad_output[0] * pow(inputs[0], inputs[1]) * log(inputs[0]);
}

double DotProductOperation::forward(const std::vector<double>& inputs) const
{
    const size_t n = inputs.size() / 2;
    double result = 0.0;
    for (size_t i = 0; i < n; ++i)
    {
        result += inputs[i] * inputs[i + n];
    }
    return result;
}
void DotProductOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    const size_t n = inputs.size() / 2;
    for (size_t i = 0; i < n; ++i)
    {
        grad_inputs[i] = grad_output[0] * inputs[i + n];
        grad_inputs[i + n] = grad_output[0] * inputs[i];
    }
}




std::shared_ptr<Node> makeNode(const std::shared_ptr<BasicOperation>& op, const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    return std::make_shared<Node>(op, std::vector<std::shared_ptr<Node>>{a, b});
}

std::shared_ptr<Node> operator+(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    return makeNode(std::make_shared<AddOperation>(), a, b);
}

std::shared_ptr<Node> operator*(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    return makeNode(std::make_shared<MultiplyOperation>(), a, b);
}

std::shared_ptr<Node> operator/(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    return makeNode(std::make_shared<DivideOperation>(), a, b);
}

std::shared_ptr<Node> operator-(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    return makeNode(std::make_shared<DeleteOperation>(), a, b);
}

std::shared_ptr<Node> operator^(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b)
{
    if(a->value == 0.0 && b->value == 0.0)
    {
        std::cout << "Error: a and b can not be zero at the same time in pow(a, b)." << std::endl;
        exit(1);
    }
    return makeNode(std::make_shared<PowOperation>(), a, b);
}

std::shared_ptr<Node> dot(const std::vector<std::shared_ptr<Node>>& vec1, const std::vector<std::shared_ptr<Node>>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::invalid_argument("Vectors must have the same size for dot product");
    }

    std::vector<std::shared_ptr<Node>> inputs;
    inputs.insert(inputs.end(), vec1.begin(), vec1.end());
    inputs.insert(inputs.end(), vec2.begin(), vec2.end());

    auto dot_op = std::make_shared<DotProductOperation>();

    return std::make_shared<Node>(dot_op, inputs);
}

// std::vector<std::shared_ptr<Node>> matmul(const std::vector<std::vector<std::shared_ptr<Node>>>& mat1, const std::vector<std::shared_ptr<Node>>& vec)
// {
//
// }


void computeGradients(const std::shared_ptr<Node>& node) {

    node->grad = 1.0;

    std::vector<std::shared_ptr<Node>> stack{node};
    while (!stack.empty()) {
        const auto current = stack.back();
        stack.pop_back();
        current->backward();
        for (const auto& input : current->inputs) {
            stack.push_back(input);
        }
    }
}
