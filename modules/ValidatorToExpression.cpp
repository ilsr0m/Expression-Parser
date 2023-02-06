#include "ValidatorToExpression.h"

bool ValidatorToExpression::isValid(std::basic_string<char> t) {
    std::regex pattern(R"(^[\d\+\-\*\^\/\(\)\.]+$)");
    return std::regex_match(t, pattern);
}