//
// Created by yuyuan on 2024/10/16.
//

#include "../include/lossFunction.h"

std::shared_ptr<Node> lossFunction::perceptronLoss::forward(const std::vector<std::shared_ptr<Node>>& data, const std::vector<std::shared_ptr<Node>>& labels) const
{
    if (labels.size() != data.size())
    {
        throw std::invalid_argument("labels size does not match data size");
    }

    const size_t n = data.size();
    auto tmp = std::make_shared<Node>(0);
    for(size_t i = 0; i < n; i++)
    {
        if(data[i]->value_ != labels[i]->value_)
        {
            tmp = tmp - labels[i] * data[i];
        }
    }
    return tmp;
}

