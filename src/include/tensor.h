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

        explicit tensorCreator(const std::vector<int>& size_of_tensor) : size_of_tensor_(size_of_tensor), initial_value_(0.5)
        {
            _make_tensor_();
        };
        tensorCreator(const std::vector<int>& size_of_tensor, const double initial_value) : size_of_tensor_(size_of_tensor), initial_value_(initial_value)
        {
            _make_tensor_();
        };
        explicit tensorCreator(const int size_of_tensor) : size_of_tensor_({size_of_tensor}), initial_value_(0.5)
        {
            _make_tensor_();
        }

        private:
        void _make_tensor_();
    };
    class tensorCreator2D
    {
    public:
        std::vector<int> size_of_tensor_;
        double initial_value_;
        std::vector<std::vector<std::shared_ptr<Node>>> nodes_;

        explicit tensorCreator2D(const std::vector<int>& size_of_tensor) : size_of_tensor_(size_of_tensor), initial_value_(0)
        {
            _make_tensor_();
        }
        tensorCreator2D(const std::vector<int>& size_of_tensor, const double initial_value): size_of_tensor_(size_of_tensor), initial_value_(initial_value)
        {
            _make_tensor_();
        }
    private:
        void _make_tensor_();
    };
};

#endif //TENSOR_H
