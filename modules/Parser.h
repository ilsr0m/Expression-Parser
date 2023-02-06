#pragma once
#include <iostream>
#include "FormatterToExpression.h"
#include "ShuntingYardAlgorithm.h"
#include "ValidatorToExpression.h"

class Parser {
private:
    double result;
    IComputerExpression* algorithm;
    IFormatter* formatter;
    IValidator<std::string> *validator = new ValidatorToExpression();
    std::string expression; // a string of expression
public:
    Parser(std::string expression, IFormatter* formatter, IComputerExpression* algorithm);
    ~Parser();
    void setExpression(std::string expr);
    void setFormatter(IFormatter* formatter);
    void setAlgorithm(IComputerExpression* algorithm);

    double gerResult();
    void parse();
};


#pragma once
