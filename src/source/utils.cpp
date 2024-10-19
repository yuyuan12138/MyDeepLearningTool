//
// Created by yuyuan on 2024/10/17.
//

#include "../include/utils.h"

std::vector<std::vector<std::shared_ptr<Node>>> transpose_matrix(const std::vector<std::vector<std::shared_ptr<Node>>>& mat)
{

    const size_t rows = mat[0].size();
    const size_t cols = mat.size();
    std::vector<std::vector<std::shared_ptr<Node>>> transposed_mat;
    for (size_t i = 0; i < rows; i++)
    {
        std::vector<std::shared_ptr<Node>> tmp;
        for (size_t j = 0; j < cols; j++)
        {
            tmp.push_back(mat[i][j]);
        }
        transposed_mat.push_back(tmp);
    }
    return transposed_mat;
}