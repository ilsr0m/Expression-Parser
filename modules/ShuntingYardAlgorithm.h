#pragma once
#include <iostream>
#include <stack>
#include "IComputerExpression.h"
#include "Token.h"

class ShuntingYardAlgorithm : public IComputerExpression {
private:
    std::stack<double> *nums = new std::stack<double>(); // stack of doubles
    std::stack <Token> *ops = new std::stack<Token>(); // stack of operators
    void get_operation();
public:
    ShuntingYardAlgorithm();
    ~ShuntingYardAlgorithm();
    double compute(std::string expression) override;
};

