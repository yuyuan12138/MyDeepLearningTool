//
// Created by yuyuan on 2024/10/13.
//

#ifndef TWOPARAMETEROPERATION_H
#define TWOPARAMETEROPERATION_H

#include <vector>
#include <cmath>

class BasicOperation
{
public:
    [[nodiscard]] virtual double forward(const std::vector<double>& inputs) const = 0;
    virtual void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const = 0;
    virtual ~BasicOperation() = default;
};
// Multiple operation
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
class SumOperation : public BasicOperation
{
    public:
    [[nodiscard]] double forward(const std::vector<double>& inputs) const override;
    void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const override;
};

class ReluOperation : public BasicOperation
{
public:
    [[nodiscard]] double forward(const std::vector<double>& inputs) const override;
    void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const override;
};

class SignOperation : public BasicOperation
{
    public:
    [[nodiscard]] double forward(const std::vector<double>& inputs) const override;
    void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const override;
};

class SigmoidOperation : public BasicOperation
{
    public:
    [[nodiscard]] double forward(const std::vector<double>& inputs) const override;
    void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const override;
};

class TanhOperation : public BasicOperation
{
    public:
    [[nodiscard]] double forward(const std::vector<double>& inputs) const override;
    void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const override;
};

class SoftmaxOperation : public BasicOperation
{
    public:
    [[nodiscard]] double forward(const std::vector<double>& inputs) const override;
    void backward(const std::vector<double>& inputs, const std::vector<double>& grad_output, std::vector<double>& grad_inputs) const override;
};





#endif //BASICOPERATION_H
