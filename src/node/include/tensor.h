//
// Created by yuyuan on 2024/10/17.
//

#ifndef TENSOR_H
#define TENSOR_H

#include <vector>
#include "node.h"
#include <memory>
#include <iostream>

class tensor
{
    public:

    class tensorCreator
    {
        public:
        std::vector<int> size_of_tensor_;
        double initial_value_;
        std::vector<std::shared_ptr<Node>> nodes_;

        explicit tensorCreator(const std::vector<int>& size_of_tensor) : size_of_tensor_(size_of_tensor), initial_value_(0){};
        tensorCreator(const std::vector<int>& size_of_tensor, const double initial_value) : size_of_tensor_(size_of_tensor), initial_value_(initial_value) {};

        void make_tensor();
    };

};

#endif //TENSOR_H
