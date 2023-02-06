#pragma once
#include <iostream>
#include "ValidatorToOperator.h"

// simple type enum to define math expression tokens type
enum class Type {
    Uknown,
    Operator,
    LeftParenthese,
    RightParenthese
};

// token class to define operator of expression
class Token {
private:
    // precedence for +, -: 1; for *, /: 2; for ^: 3
    int precedence;
    char token;
    // operator's type
    Type type;

    IValidator<char> *validator = new ValidatorToOperator();

    Type get_type();

    int get_precedence();

public:
    Token(char token);

    ~Token();

    // precedence's getter
    int getPrecedence();

    // token's getter
    char getToken();

    // type's getter
    Type getType();
};


