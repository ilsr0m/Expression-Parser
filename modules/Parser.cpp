#include "Parser.h"
#include <cmath>
#include "error.h"
#include "Validator.h"

Parser::Parser(std::string expression, IFormatter *formatter, IComputerExpression *algorithm) {
    this->expression = expression;
    this->formatter = formatter;
    this->algorithm = algorithm;
    result = NAN;
}

Parser::~Parser() {
    delete formatter;
    delete algorithm;
    delete validator;
}

double Parser::gerResult() {
    return result;
}

void Parser::setExpression(std::string expr) {
    expression = expr;
}

void Parser::setFormatter(IFormatter *formatter) {
    delete this->formatter;
    this->formatter = formatter;
}

void Parser::setAlgorithm(IComputerExpression *algorithm) {
    delete this->algorithm;
    this->algorithm = algorithm;
}

void Parser::parse() {
    if (expression.empty())
        throw Lexical_error{"expression is empty"};
    if (!validator->isValid(expression))
        throw Lexical_error{"wrong symbol for expression"};
    formatter->format(expression);
    result = algorithm->compute(expression);
}
