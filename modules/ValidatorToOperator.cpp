#include "ValidatorToOperator.h"
bool ValidatorToOperator::isValid(char t) {
    std::regex pattern(R"([-*\/+^])");
    return std::regex_match(std::string(1, t), pattern);
}
