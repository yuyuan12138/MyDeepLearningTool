//
// Created by yuyuan on 2024/10/16.
//

#include "../include/activateFunction.h"


std::shared_ptr<Node> basicActivateFunction::signActivation(const std::shared_ptr<Node>& node)
{
    std::vector<std::shared_ptr<Node>> tmp = {node};
    return std::make_shared<Node>(std::make_shared<TwoParameterOperation::SignOperation>(), tmp);
}

std::shared_ptr<Node> basicActivateFunction::signActivation(const std::vector<std::shared_ptr<Node>>& nodes)
{
    return std::make_shared<Node>(std::make_shared<TwoParameterOperation::SignOperation>(), nodes);
}

std::shared_ptr<Node> basicActivateFunction::ReluActivation(const std::shared_ptr<Node>& node)
{
    std::vector<std::shared_ptr<Node>> tmp = {node};
    return std::make_shared<Node>(std::make_shared<TwoParameterOperation::ReluOperation>(), tmp);
}

std::shared_ptr<Node> basicActivateFunction::ReluActivation(const std::vector<std::shared_ptr<Node>>& nodes)
{
    return std::make_shared<Node>(std::make_shared<TwoParameterOperation::ReluOperation>(), nodes);
}

std::shared_ptr<Node> basicActivateFunction::SigmoidActivation(const std::shared_ptr<Node>& node)
{
    std::vector<std::shared_ptr<Node>> tmp = {node};
    return std::make_shared<Node>(std::make_shared<TwoParameterOperation::SigmoidOperation>(), tmp);
}
std::shared_ptr<Node> basicActivateFunction::SigmoidActivation(const std::vector<std::shared_ptr<Node>>& nodes)
{
    return std::make_shared<Node>(std::make_shared<TwoParameterOperation::SigmoidOperation>(), nodes);
}

std::shared_ptr<Node> basicActivateFunction::TanhActivation(const std::shared_ptr<Node>& node)
{
    std::vector<std::shared_ptr<Node>> tmp = {node};
    return std::make_shared<Node>(std::make_shared<TwoParameterOperation::TanhOperation>(), tmp);
}

std::shared_ptr<Node> basicActivateFunction::TanhActivation(const std::vector<std::shared_ptr<Node>>& nodes)
{
    return std::make_shared<Node>(std::make_shared<TwoParameterOperation::TanhOperation>(), nodes);
}









