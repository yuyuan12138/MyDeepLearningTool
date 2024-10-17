#include "include/autoGradient.h"


int main() {

    auto x = std::make_shared<Node>(1.5);  // x = 1.5
    auto y = std::make_shared<Node>(2);  // e^x
    auto z = x^y;  // e^x * x

    z->forward();
    computeGradients(z);
    std::cout << z->value << std::endl;
    std::cout << x->grad << std::endl;
    std::cout << y->grad << std::endl;
    z->resetGradients();
    std::cout << z->value << std::endl;
    std::cout << x->grad << std::endl;
    std::cout << y->grad << std::endl;
    z->forward();
    computeGradients(z);
    std::cout << z->value << std::endl;
    std::cout << x->grad << std::endl;
    std::cout << y->grad << std::endl;
    return 0;
}