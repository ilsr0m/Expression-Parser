#pragma once
#include <iostream>

class IComputerExpression {
public:
    virtual double compute(std::string expr) {
        return double();
    }
};
