//
// Created by yuyuan on 2024/10/16.
//

#include "../include/lossFunction.h"

std::shared_ptr<Node> lossFunction::perceptronLoss(const std::vector<std::shared_ptr<Node>>& data, const std::vector<std::shared_ptr<Node>>& labels)
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

std::shared_ptr<Node> lossFunction::MSE_Loss(const std::vector<std::shared_ptr<Node>>& data, const std::vector<std::shared_ptr<Node>>& labels)
{
    if (labels.size() != data.size())
    {
        throw std::invalid_argument("labels size does not match data size");
    }
    const size_t n = data.size();
    const auto tmp_1 = std::make_shared<Node>(2);
    const auto tmp_2 = std::make_shared<Node>(n);
    auto loss = std::make_shared<Node>(0);
    for(size_t i = 0; i < n; i++)
    {
        loss = loss + (labels[i] - data[i]) ^ tmp_1;
    }
    loss = loss / tmp_2;
    return loss;
}



