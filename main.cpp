#include "autoGradient.h"

int main() {
    // 创建两个向量：[1, 2, 3] 和 [4, 5, 6]
    std::vector<std::shared_ptr<Node>> vec1 = {
        std::make_shared<Node>(1.0),
        std::make_shared<Node>(2.0),
        std::make_shared<Node>(3.0)
    };

    std::vector<std::shared_ptr<Node>> vec2 = {
        std::make_shared<Node>(4.0),
        std::make_shared<Node>(5.0),
        std::make_shared<Node>(6.0)
    };

    // 计算点积
    auto dot_product = dot(vec1, vec2);

    // 前向传播
    dot_product->forward();
    std::cout << "Dot product: " << dot_product->value << std::endl;

    // 反向传播
    computeGradients(dot_product);

    // 输出每个输入的梯度
    std::cout << "Gradients for vec1:" << std::endl;
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << "d(dot)/d(vec1[" << i << "]) = " << vec1[i]->grad << std::endl;
    }

    std::cout << "Gradients for vec2:" << std::endl;
    for (size_t i = 0; i < vec2.size(); ++i) {
        std::cout << "d(dot)/d(vec2[" << i << "]) = " << vec2[i]->grad << std::endl;
    }

    return 0;
}

// int main() {
//
//     std::vector<double> x = {1, 2, 3, 4, 5};
//     std::vector<double> y = {1, 2, 3, 4, 5};
//     std::shared_ptr<Node> z;
//     for (int i = 0; i < x.size(); i++)
//     {
//         auto x1 = std::make_shared<Node>(x[i]);
//         auto y1 = std::make_shared<Node>(y[i]);
//         tmp(z, x1, y1);
//     }
//     z->forward();
//     computeGradients(z);
//     std::cout << z->value <<std::endl;
//
//
//     // auto z = std::make_shared<Node>(1.5);  // x = 1.5
//     // auto y = std::make_shared<Node>(2);  // e^x
//     // auto z = x^y;  // e^x * x
//     //
//     // z->forward();
//     // computeGradients(z);
//     // std::cout << z->value << std::endl;
//     // std::cout << x->grad << std::endl;
//     // std::cout << y->grad << std::endl;
//     // z->resetGradients();
//     // std::cout << z->value << std::endl;
//     // std::cout << x->grad << std::endl;
//     // std::cout << y->grad << std::endl;
//     // z->forward();
//     // computeGradients(z);
//     // std::cout << z->value << std::endl;
//     // std::cout << x->grad << std::endl;
//     // std::cout << y->grad << std::endl;
//     return 0;
// }