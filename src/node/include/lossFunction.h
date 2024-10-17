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
    class basicFunction
    {
    public:
        [[nodiscard]] virtual std::shared_ptr<Node> forward(const std::vector<std::shared_ptr<Node>>& data, const std::vector<std::shared_ptr<Node>>& labels) const = 0;
        virtual ~basicFunction() = default;
    };

    class perceptronLoss : public basicFunction
    {
        public:
        [[nodiscard]] std::shared_ptr<Node> forward(const std::vector<std::shared_ptr<Node>>& data, const std::vector<std::shared_ptr<Node>>& labels) const override;
    };
};

#endif //LOSSFUNCTION_H
