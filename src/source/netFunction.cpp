//
// Created by yuyuan on 2024/10/18.
//

#include "../include/netFunction.h"

void nn::Linear::_create_linear_()
{
    if(shape_.size() != 2)
    {
        throw std::invalid_argument("nn::Linear::_create_linear_: shape must be 2");
    }

    const std::vector<int> shape = {shape_[0], shape_[1]};
    matrix_ = tensor::tensorCreator2D(shape).nodes_;
}