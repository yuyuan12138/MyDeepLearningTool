//
// Created by yuyuan on 2024/10/13.
//

#ifndef CALCULATIONMETHOD_H
#define CALCULATIONMETHOD_H

#include "node.h"
#include <iostream>
#include "twoParameterOperation.h"
#include "utils.h"

std::shared_ptr<Node> makeNode(const std::shared_ptr<TwoParameterOperation::BasicOperation>& op, const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b);

std::shared_ptr<Node> operator+(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b);
std::vector<std::shared_ptr<Node>> operator+(const std::vector<std::shared_ptr<Node>>& a, const std::vector<std::shared_ptr<Node>>& b);
std::vector<std::vector<std::shared_ptr<Node>>> operator+(const std::vector<std::vector<std::shared_ptr<Node>>>& a, const std::vector<std::vector<std::shared_ptr<Node>>>& b);


std::shared_ptr<Node> operator*(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b);

std::shared_ptr<Node> operator/(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b);

std::shared_ptr<Node> operator-(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b);
std::vector<std::shared_ptr<Node>> operator-(const std::vector<std::shared_ptr<Node>>& a, const std::vector<std::shared_ptr<Node>>& b);
std::vector<std::vector<std::shared_ptr<Node>>> operator-(const std::vector<std::vector<std::shared_ptr<Node>>>& a, const std::vector<std::vector<std::shared_ptr<Node>>>& b);

std::shared_ptr<Node> operator^(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b);

std::shared_ptr<Node> dot(const std::vector<std::shared_ptr<Node>>& vec1, const std::vector<std::shared_ptr<Node>>& vec2);

std::shared_ptr<Node> sum(const std::vector<std::shared_ptr<Node>>& vec);
std::shared_ptr<Node> sum(const std::vector<std::vector<std::shared_ptr<Node>>>& matrix);

std::vector<std::shared_ptr<Node>> mm(const std::vector<std::vector<std::shared_ptr<Node>>>& mat, const std::vector<std::shared_ptr<Node>>& vec);
std::vector<std::vector<std::shared_ptr<Node>>> mm(const std::vector<std::vector<std::shared_ptr<Node>>>& mat1, const std::vector<std::vector<std::shared_ptr<Node>>>& mat2);
#endif //CALCULATIONMETHOD_H
