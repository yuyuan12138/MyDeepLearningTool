//
// Created by yuyuan on 2024/10/13.
//

#include <iostream>
#include "include/node.h"
#include "include/twoParameterOperation.h"
#include "include/calculationMethod.h"
#include "include/basicUpdate.h"
#include "include/activateFunction.h"
#include "include/lossFunction.h"
#include "include/tensor.h"
#include <memory>

int main()
{
    auto optimizer = BasicUpdate::GradUpdate(1);
    auto activation = basicActivateFunction::signActivation();
    auto loss_fn = lossFunction::perceptronLoss();
    auto x = std::make_shared<Node>(2);
    auto y = std::make_shared<Node>(2);
    auto c = std::make_shared<Node>(10);
    // activation.forward(c);
    // auto z = (x^y) - c;

    auto b = std::make_shared<Node>(0);

    auto data_1_x1 = std::make_shared<Node>(1);
    auto data_1_x2 = std::make_shared<Node>(0);
    auto label_1 = std::make_shared<Node>(1);

    auto data_2_x1 = std::make_shared<Node>(0);
    auto data_2_x2 = std::make_shared<Node>(1);
    auto label_2 = std::make_shared<Node>(1);

    auto data_3_x1 = std::make_shared<Node>(0);
    auto data_3_x2 = std::make_shared<Node>(0);
    auto label_3 = std::make_shared<Node>(0);

    auto data_4_x1 = std::make_shared<Node>(1);
    auto data_4_x2 = std::make_shared<Node>(1);
    auto label_4 = std::make_shared<Node>(1);

    std::vector<int> w_size = {2};
    auto w = tensor::tensorCreator(w_size);
    w.make_tensor();

    // std::cout << "---" << std::endl;

    std::vector<std::shared_ptr<Node>> data_1 = {data_1_x1, data_1_x2};
    std::vector<std::shared_ptr<Node>> data_2 = {data_2_x1, data_2_x2};
    std::vector<std::shared_ptr<Node>> data_3 = {data_3_x1, data_3_x2};
    std::vector<std::shared_ptr<Node>> data_4 = {data_4_x1, data_4_x2};


    auto z1 = dot(data_1, w.nodes_) + b;
    auto z2 = dot(data_2, w.nodes_) + b;
    auto z3 = dot(data_3, w.nodes_) + b;
    auto z4 = dot(data_4, w.nodes_) + b;

    for (int _ = 0; _ < 10; _++)
    {
        activation.forward(z1);
        activation.forward(z2);
        activation.forward(z3);
        activation.forward(z4);
        // auto loss = tmp;
        std::vector<std::shared_ptr<Node>> lossVec = {
            z1, z2, z3, z4
        };
        std::vector<std::shared_ptr<Node>> labelsVec = {
            label_1, label_2, label_3, label_4
        };
        auto loss = loss_fn.forward(lossVec, labelsVec);

        loss->forward();

        computeGradients(loss);
        // optimizer.update(w1);
        // optimizer.update(w2);
        optimizer.update(w.nodes_);
        optimizer.update(b);

        std::cout << "loss: " << loss->value_ << std::endl;
        std::cout << "z1: " << z1->value_ << std::endl;
        std::cout << "z2: " << z2->value_ << std::endl;
        std::cout << "z3: " << z3->value_ << std::endl;
        std::cout << "z4: " << z4->value_ << std::endl;
        loss->resetGradients();

    }

    return 0;
}
