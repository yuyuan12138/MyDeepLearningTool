//
// Created by yuyuan on 2024/10/16.
//

#ifndef LOSSFUNCTION_H
#define LOSSFUNCTION_H

#include <vector>
#include "node.h"
#include "calculationMethod.h"


class lossFunction
{
    public:
    [[nodiscard]] static std::shared_ptr<Node> perceptronLoss(const std::vector<std::shared_ptr<Node>>& data, const std::vector<std::shared_ptr<Node>>& labels);
    [[nodiscard]] static std::shared_ptr<Node> MSE_Loss(const std::vector<std::shared_ptr<Node>>& data, const std::vector<std::shared_ptr<Node>>& labels);
};

#endif //LOSSFUNCTION_H
