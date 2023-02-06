#include "Token.h"

Type Token::get_type() {
    if (validator->isValid(token)) return Type::Operator;
    if (token == '(') return Type::LeftParenthese;
    if (token == ')') return Type::RightParenthese;
    return Type::Uknown;
}

// get tokens precedence
int Token::get_precedence() {
    if (token == '+' || token == '-') return 1;
    if (token == '*' || token == '/') return 2;
    if (token == '^') return 3;
    return -1;
}

Token::Token(char token) {
    this->token = token;
    type = get_type();
    precedence = get_precedence();
}

int Token::getPrecedence() {
    return precedence;
}

char Token::getToken() {
    return token;
}

Type Token::getType() {
    return type;
}

Token::~Token() {
    delete validator;
}
