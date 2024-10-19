//
// Created by yuyuan on 2024/10/18.
//

#ifndef NETFUNCTION_H
#define NETFUNCTION_H
#include <memory>
#include <vector>

#include "node.h"
#include "tensor.h"

class nn
{
    public:
    class Linear
    {
        public:
        std::vector<std::vector<std::shared_ptr<Node>>> matrix_;
        std::vector<int> shape_;

        explicit Linear(const std::vector<int>& shape): shape_(shape)
        {
            _create_linear_();
        };

        private:
        void _create_linear_();
    };
};


#endif //NETFUNCTION_H
