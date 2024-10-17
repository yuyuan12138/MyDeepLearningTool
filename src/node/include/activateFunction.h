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
    class basicFunction
    {
        public:
        void virtual forward(const std::shared_ptr<Node>& node) const = 0;
        virtual ~basicFunction() = default;
    };

    class signActivation : public basicFunction
    {
        public:
        void forward(const std::shared_ptr<Node>& node) const override;
    };


};

#endif //ACTIVATEFUNCTION_H
