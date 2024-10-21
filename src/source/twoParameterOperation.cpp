//
// Created by yuyuan on 2024/10/13.
//

#include "../include/twoParameterOperation.h"

#include <iostream>

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

double SumOperation::forward(const std::vector<double>& inputs) const
{
    const size_t n = inputs.size();
    double result = 0.0;
    for (size_t i = 0; i < n; ++i)
    {
        result += inputs[i];
    }
    return result;
}
void SumOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    const size_t n = inputs.size();
    for (size_t i = 0; i < n; ++i)
    {
        grad_inputs[i] = grad_output[0];
    }
}

double ReluOperation::forward(const std::vector<double>& inputs) const
{
    return inputs[0] >= 0 ? inputs[0] : 0;
}
void ReluOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    grad_inputs[0] = inputs[0] >= 0 ? grad_output[0] : 0;
}

double SignOperation::forward(const std::vector<double>& inputs) const
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

void SignOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    grad_inputs[0] = 0;
}

double SigmoidOperation::forward(const std::vector<double>& inputs) const
{
    return 1.0 / (1.0 + std::exp(-inputs[0]));
}

void SigmoidOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
{
    grad_inputs[0] = grad_output[0] * std::exp(-inputs[0]) / std::pow(1.0 + std::exp(-inputs[0]), 2);
}

double TanhOperation::forward(const std::vector<double>& inputs) const
{
    return (std::exp(inputs[0]) - std::exp(-inputs[0])) / (std::exp(inputs[0]) + std::exp(-inputs[0]));
}
void TanhOperation::backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const
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












