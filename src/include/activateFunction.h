//
// Created by yuyuan on 2024/10/16.
//

#ifndef ACTIVATEFUNCTION_H
#define ACTIVATEFUNCTION_H

#include <memory>
#include <vector>
#include "node.h"

class basicActivateFunction
{
public:

    // static void signActivation(const std::shared_ptr<Node>& node);
    // static void signActivation(const std::vector<std::shared_ptr<Node>>& nodes);
    static std::shared_ptr<Node> signActivation(const std::shared_ptr<Node>& node);
    static std::shared_ptr<Node> signActivation(const std::vector<std::shared_ptr<Node>>& nodes);

    static std::shared_ptr<Node> ReluActivation(const std::shared_ptr<Node>& node);
    static std::shared_ptr<Node> ReluActivation(const std::vector<std::shared_ptr<Node>>& nodes);

    static std::shared_ptr<Node> SigmoidActivation(const std::shared_ptr<Node>& node);
    static std::shared_ptr<Node> SigmoidActivation(const std::vector<std::shared_ptr<Node>>& nodes);

    static std::shared_ptr<Node> SoftmaxActivation(const std::shared_ptr<Node>& node);
    static std::shared_ptr<Node> SoftmaxActivation(const std::vector<std::shared_ptr<Node>>& nodes);

    static std::shared_ptr<Node> TanhActivation(const std::shared_ptr<Node>& node);
    static std::shared_ptr<Node> TanhActivation(const std::vector<std::shared_ptr<Node>>& nodes);

};

#endif //ACTIVATEFUNCTION_H
