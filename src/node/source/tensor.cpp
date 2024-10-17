//
// Created by yuyuan on 2024/10/17.
//

#include "../include/tensor.h"

void tensor::tensorCreator::make_tensor()
{
    // std::cout << "---" << std::endl;
    int length = 1;
    for(const int size : size_of_tensor_)
    {
        length *= size;
    }

    for(int i = 0; i < length; i++)
    {
        auto tmp_node = std::make_shared<Node>(initial_value_);
        nodes_.push_back(tmp_node);
    }

}
