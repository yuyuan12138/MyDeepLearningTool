//
// Created by yuyuan on 2024/10/16.
//

#ifndef BASICUPDATE_H
#define BASICUPDATE_H

#include <memory>
#include "node.h"
#include "tensor.h"

class BasicUpdate
{
public:
    class Update
    {
    public:
        virtual void update(const std::shared_ptr<Node>& node) const = 0;
        virtual void update(const std::vector<std::shared_ptr<Node>>& nodes) const = 0;
        virtual ~Update()= default;
    };

    class GradUpdate : public Update
    {
    public:
        double learning_rate_;

        GradUpdate() : learning_rate_(0.0) {}
        explicit GradUpdate(const double learning_rate) : learning_rate_(learning_rate) {}

        void update(const std::shared_ptr<Node>& node) const override;

        void update(const std::vector<std::shared_ptr<Node>>& nodes) const override;


    };
};

#endif //BASICUPDATE_H
