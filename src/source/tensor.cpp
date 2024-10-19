//
// Created by yuyuan on 2024/10/17.
//

#include "../include/tensor.h"

void tensor::tensorCreator::_make_tensor_()
{
    for(int i = 0; i < size_of_tensor_[0]; i++)
    {
        auto tmp_node = std::make_shared<Node>(initial_value_);
        nodes_.push_back(tmp_node);
    }
}

void tensor::tensorCreator2D::_make_tensor_()
{
    for(int i = 0; i < size_of_tensor_[0]; i++)
    {
        std::vector<std::shared_ptr<Node>> tmp_vec;
        for(int j = 0; j < size_of_tensor_[1]; j++)
        {
            auto tmp_node = std::make_shared<Node>(initial_value_);
            tmp_vec.push_back(tmp_node);
        }
        nodes_.push_back(tmp_vec);
    }
}
