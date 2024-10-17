//
// Created by yuyuan on 2024/10/16.
//

#include "../include/activateFunction.h"

void basicActivateFunction::signActivation::forward(const std::shared_ptr<Node>& node) const
{
    node->value_ = node->value_ > 0 ? 1 : 0;
}
