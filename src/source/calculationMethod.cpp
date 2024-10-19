//
// Created by yuyuan on 2024/10/13.
//

#include "../include/calculationMethod.h"

std::shared_ptr<Node> makeNode(const std::shared_ptr<TwoParameterOperation::BasicOperation>& op, const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    return std::make_shared<Node>(op, std::vector<std::shared_ptr<Node>>{a, b});
}

std::shared_ptr<Node> operator+(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    return makeNode(std::make_shared<TwoParameterOperation::AddOperation>(), a, b);
}
std::vector<std::shared_ptr<Node>> operator+(const std::vector<std::shared_ptr<Node>>& a, const std::vector<std::shared_ptr<Node>>& b)
{
    if(a.size() != b.size())
    {
        throw std::invalid_argument("operator+");
    }
    std::vector<std::shared_ptr<Node>> result;
    for(size_t i = 0; i < a.size(); i++)
    {
        std::vector<std::shared_ptr<Node>> tmp;
        tmp.push_back(a[i]);
        tmp.push_back(b[i]);
        result.push_back(std::make_shared<Node>(std::make_shared<TwoParameterOperation::AddOperation>(), tmp));
    }
    return result;
}
std::vector<std::vector<std::shared_ptr<Node>>> operator+(const std::vector<std::vector<std::shared_ptr<Node>>>& a, const std::vector<std::vector<std::shared_ptr<Node>>>& b)
{
    if(a.size() != b.size() || a[0].size() != b[0].size())
    {
        throw std::invalid_argument("operator+");
    }
    std::vector<std::vector<std::shared_ptr<Node>>> result;
    for(size_t i = 0; i < a.size(); i++)
    {
        std::vector<std::shared_ptr<Node>> tmp_nodes;
        for(size_t j = 0; j < a[0].size(); j++)
        {
            std::vector<std::shared_ptr<Node>> tmp;
            tmp.push_back(a[i][j]);
            tmp.push_back(b[i][j]);
            tmp_nodes.push_back(std::make_shared<Node>(std::make_shared<TwoParameterOperation::AddOperation>(), tmp));
        }
        result.push_back(tmp_nodes);
    }
    return result;
}

std::shared_ptr<Node> operator*(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    return makeNode(std::make_shared<TwoParameterOperation::MultiplyOperation>(), a, b);
}

std::shared_ptr<Node> operator/(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    return makeNode(std::make_shared<TwoParameterOperation::DivideOperation>(), a, b);
}

std::shared_ptr<Node> operator-(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    return makeNode(std::make_shared<TwoParameterOperation::DeleteOperation>(), a, b);
}
std::vector<std::shared_ptr<Node>> operator-(const std::vector<std::shared_ptr<Node>>& a, const std::vector<std::shared_ptr<Node>>& b)
{
    if(a.size() != b.size())
    {
        throw std::invalid_argument("operator-");
    }
    std::vector<std::shared_ptr<Node>> result;
    for(size_t i = 0; i < a.size(); i++)
    {
        std::vector<std::shared_ptr<Node>> tmp;
        tmp.push_back(a[i]);
        tmp.push_back(b[i]);
        result.push_back(std::make_shared<Node>(std::make_shared<TwoParameterOperation::DeleteOperation>(), tmp));
    }
    return result;
}
std::vector<std::vector<std::shared_ptr<Node>>> operator-(const std::vector<std::vector<std::shared_ptr<Node>>>& a, const std::vector<std::vector<std::shared_ptr<Node>>>& b)
{
    if(a.size() != b.size() || a[0].size() != b[0].size())
    {
        throw std::invalid_argument("operator-");
    }
    std::vector<std::vector<std::shared_ptr<Node>>> result;
    for(size_t i = 0; i < a.size(); i++)
    {
        std::vector<std::shared_ptr<Node>> tmp_nodes;
        for(size_t j = 0; j < a[0].size(); j++)
        {
            std::vector<std::shared_ptr<Node>> tmp;
            tmp.push_back(a[i][j]);
            tmp.push_back(b[i][j]);
            tmp_nodes.push_back(std::make_shared<Node>(std::make_shared<TwoParameterOperation::DeleteOperation>(), tmp));
        }
        result.push_back(tmp_nodes);
    }
    return result;
}

std::shared_ptr<Node> operator^(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b)
{
    if(a->value_ == 0.0 && b->value_ == 0.0)
    {
        std::cout << "Error: a and b can not be zero at the same time in pow(a, b)." << std::endl;
        exit(1);
    }
    return makeNode(std::make_shared<TwoParameterOperation::PowOperation>(), a, b);
}

std::shared_ptr<Node> dot(const std::vector<std::shared_ptr<Node>>& vec1, const std::vector<std::shared_ptr<Node>>& vec2) {
    if (vec1.size() != vec2.size()) {
        std::cout << vec1.size() << "  "  << vec2.size() <<std::endl;
        throw std::invalid_argument("Vectors must have the same size for dot product");
    }

    std::vector<std::shared_ptr<Node>> inputs;
    inputs.insert(inputs.end(), vec1.begin(), vec1.end());
    inputs.insert(inputs.end(), vec2.begin(), vec2.end());

    auto dot_op = std::make_shared<TwoParameterOperation::DotProductOperation>();

    return std::make_shared<Node>(dot_op, inputs);
}

std::shared_ptr<Node> sum(const std::vector<std::shared_ptr<Node>>& vec)
{
    if (vec.empty())
    {
        throw std::invalid_argument("Vectors must have at least one element.");
    }
    return std::make_shared<Node>(std::make_shared<TwoParameterOperation::SumOperation>(), vec);
}


std::vector<std::shared_ptr<Node>> mm(const std::vector<std::vector<std::shared_ptr<Node>>>& mat, const std::vector<std::shared_ptr<Node>>& vec)
{
    if (mat.size() != vec.size())
    {
        throw std::invalid_argument("Vectors must have the same size for mm.");
    }

    const size_t col = mat.size();
    std::vector<std::shared_ptr<Node>> result;
    std::vector<std::vector<std::shared_ptr<Node>>> mat_T = transpose_matrix(mat);
    for(size_t i = 0; i < col; i++)
    {

        result.push_back(dot(mat_T[i], vec));
    }
    return result;
}

std::vector<std::vector<std::shared_ptr<Node>>> mm(const std::vector<std::vector<std::shared_ptr<Node>>>& mat1, const std::vector<std::vector<std::shared_ptr<Node>>>& mat2)
{
    if (mat1.size() != mat2[0].size())
    {
        throw std::invalid_argument("cols of mat1 should match rows of mat2.");
    }
    std::vector<std::vector<std::shared_ptr<Node>>> result;
    std::vector<std::vector<std::shared_ptr<Node>>> mat1_T = transpose_matrix(mat1);
    const size_t col = mat1.size();
    const size_t row = mat1_T.size();
    for(size_t i = 0; i < col; i++)
    {
        std::vector<std::shared_ptr<Node>> tmp_vec;
        for(size_t j = 0; j < row; j++)
        {
            tmp_vec.push_back(dot(mat1_T[j], mat2[i]));
        }
        result.push_back(tmp_vec);
    }
    return result;
}

