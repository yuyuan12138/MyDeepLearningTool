//
// Created by yuyuan on 2024/10/17.
//

#ifndef UTILS_H
#define UTILS_H

// define helper function
#include <memory>
#include <vector>
#include "node.h"

std::vector<std::vector<std::shared_ptr<Node>>> transpose_matrix(const std::vector<std::vector<std::shared_ptr<Node>>>& mat);

#endif //UTILS_H
