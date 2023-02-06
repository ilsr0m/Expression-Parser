#include "ShuntingYardAlgorithm.h"
#include "error.h"
#include <cmath>
#include <exception>

// perform single operation
void ShuntingYardAlgorithm::get_operation() {
    if (nums->size() == 1 || nums->size() == 0)
        throw Lexical_error{"No digitals to perform operation"};
    const char op = ops->top().getToken(); // get operator
    double a, b; //c = a OP c
    double c = double();
    // take the last numbers from numeric stack and remove them
    a = nums->top();
    nums->pop();
    b = nums->top();
    nums->pop();
    switch (op) {
        case '+':
            c = b + a;
            break;
        case '-':
            c = b - a;
            break;
        case '*':
            c = b * a;
            break;
        case '/':
            if (a == 0) throw Runtime_error{"divide by zero"};
            c = b / a;
            break;
        case '^':
            c = pow(b, a);
            break;
        default:
            throw Syntax_error{"invalid primary expression"};
            break; // error
    }
    // push the result into numeric stack
    nums->push(c);
    // delete operator from stack
    ops->pop();
}

ShuntingYardAlgorithm::ShuntingYardAlgorithm() {

}

ShuntingYardAlgorithm::~ShuntingYardAlgorithm() {
    delete[] nums;
    delete[] ops;
}

//compute expression
double ShuntingYardAlgorithm::compute(std::string expression) {
    if (nums == nullptr || ops == nullptr) throw Runtime_error{"No stacks are initialized"};
    for (int i = 0; i < expression.size(); i++) {
        if (isdigit(expression[i])) {
            //extract tokens from string math expression;
            std::string digits; // string of double value
            while (isdigit(expression[i]) || expression[i] == '.') {
                digits.push_back(expression[i]);
                i++;
            }
            i--;
            if (digits[digits.size() - 1] == '.') throw Lexical_error("no digits after decimal point");
            // convert string digits into double value
            try{
                double x = atof(digits.c_str());
                nums->push(x);
            }
            catch (std::exception &e){
                std::cerr<<"Error: "<< e.what();
            }
            continue;
        }
        // allocate new token
        Token token = Token(expression[i]);
        if (ops->empty()) ops->push(token); // if stack is empty
        else {
            // look for right parenthese
            if (token.getType() == Type::RightParenthese) {
                //const char op = ops->top().getToken();
                while (ops->top().getType() != Type::LeftParenthese) {
                    if (ops->empty()) {
                        throw Lexical_error{"No left parenthese found"};
                    }
                    get_operation();
                }
                ops->pop(); // delete left parentheses
            } else if (token.getType() == Type::LeftParenthese) {
                ops->push(token);
            }
            // extract two double values to perform operation and put the result in stack
            else if (ops->top().getPrecedence() >= token.getPrecedence()) {
                get_operation();
                ops->push(token);
            } else ops->push(token);
        }
    }
    while (!ops->empty()) get_operation(); // get rid of the rest of operators and doubles in order to set only one double in nums stacks
    return nums->top();
}



