//
// Created by yuyuan on 2024/10/16.
//

#include "../include/basicUpdate.h"

void BasicUpdate::GradUpdate::update(const std::shared_ptr<Node>& node) const
{
    node->value_ = node->value_ - node->grad_ * learning_rate_;
}

void BasicUpdate::GradUpdate::update(const std::vector<std::shared_ptr<Node>>& nodes) const
{
    for (auto& node : nodes)
    {
        node->value_ = node->value_ - node->grad_ * learning_rate_;
    }
}







