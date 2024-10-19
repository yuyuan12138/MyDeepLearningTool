//
// Created by yuyuan on 2024/10/13.
//

#include "../include/twoParameterOperation.h"

#include <iostream>

[[nodiscard]] double TwoParameterOperation::AddOperation::forward(const std::vector<double>& inputs) const  {
    return inputs[0] + inputs[1];
}

void TwoParameterOperation::AddOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const  {
    grad_inputs[0] = grad_output[0];
    grad_inputs[1] = grad_output[0];
}



[[nodiscard]] double TwoParameterOperation::MultiplyOperation::forward(const std::vector<double>& inputs) const  {
    return inputs[0] * inputs[1];
}

void TwoParameterOperation::MultiplyOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const  {
    grad_inputs[0] = grad_output[0] * inputs[1];
    grad_inputs[1] = grad_output[0] * inputs[0];
}


[[nodiscard]] double TwoParameterOperation::DivideOperation::forward(const std::vector<double>& inputs) const
{
    return inputs[0] / inputs[1];
}
void TwoParameterOperation::DivideOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    grad_inputs[0] = grad_output[0] / inputs[1];
    grad_inputs[1] = - grad_output[0] / (inputs[0] * inputs[1]) * inputs[0];
}


[[nodiscard]] double TwoParameterOperation::DeleteOperation::forward(const std::vector<double>& inputs) const
{
    return inputs[0] - inputs[1];
}
void TwoParameterOperation::DeleteOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    grad_inputs[0] = grad_output[0];
    grad_inputs[1] = -grad_output[0];
}


[[nodiscard]] double TwoParameterOperation::PowOperation::forward(const std::vector<double>& inputs) const
{
    return std::pow(inputs[0], inputs[1]);
}
void TwoParameterOperation::PowOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    grad_inputs[0] = grad_output[0] * inputs[1] * (pow(inputs[0], inputs[1])) / inputs[0];
    grad_inputs[1] = grad_output[0] * pow(inputs[0], inputs[1]) * log(inputs[0]);
}

double TwoParameterOperation::DotProductOperation::forward(const std::vector<double>& inputs) const
{
    const size_t n = inputs.size() / 2;
    double result = 0.0;
    for (size_t i = 0; i < n; ++i)
    {
        result += inputs[i] * inputs[i + n];
    }
    return result;
}
void TwoParameterOperation::DotProductOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    const size_t n = inputs.size() / 2;
    for (size_t i = 0; i < n; ++i)
    {
        grad_inputs[i] = grad_output[0] * inputs[i + n];
        grad_inputs[i + n] = grad_output[0] * inputs[i];
    }
}

double TwoParameterOperation::SumOperation::forward(const std::vector<double>& inputs) const
{
    const size_t n = inputs.size();
    double result = 0.0;
    for (size_t i = 0; i < n; ++i)
    {
        result += inputs[i];
    }
    return result;
}
void TwoParameterOperation::SumOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    const size_t n = inputs.size();
    for (size_t i = 0; i < n; ++i)
    {
        grad_inputs[i] = grad_output[0];
    }
}

double TwoParameterOperation::ReluOperation::forward(const std::vector<double>& inputs) const
{
    return inputs[0] >= 0 ? inputs[0] : 0;
}
void TwoParameterOperation::ReluOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    grad_inputs[0] = inputs[0] >= 0 ? grad_output[0] : 0;
}

double TwoParameterOperation::SignOperation::forward(const std::vector<double>& inputs) const
{
    if (inputs[0] > 0)
    {
        return 1;
    }

    if (inputs[0] < 0)
    {
        return -1;
    }

    return 0;
}

void TwoParameterOperation::SignOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    grad_inputs[0] = 0;
}

double TwoParameterOperation::SigmoidOperation::forward(const std::vector<double>& inputs) const
{
    return 1.0 / (1.0 + std::exp(-inputs[0]));
}

void TwoParameterOperation::SigmoidOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    grad_inputs[0] = grad_output[0] * std::exp(-inputs[0]) / std::pow(1.0 + std::exp(-inputs[0]), 2);
}

double TwoParameterOperation::TanhOperation::forward(const std::vector<double>& inputs) const
{
    return (std::exp(inputs[0]) - std::exp(-inputs[0])) / (std::exp(inputs[0]) + std::exp(-inputs[0]));
}
void TwoParameterOperation::TanhOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    grad_inputs[0] = grad_output[0] * 4 / (std::exp(2 * inputs[0]) + std::exp(-2 * inputs[0]) + 2);
}

// double TwoParameterOperation::SoftmaxOperation::forward(const std::vector<double>& inputs) const
// {
//     const size_t n = inputs.size();
//     double sum = 0;
//     for(size_t i = 0; i < n; i++)
//     {
//
//     }
// }
// void TwoParameterOperation::SoftmaxOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
// {
//
// }












