#ifndef FACTORY_VALIDATORTOEXPRESSION_H
#define FACTORY_VALIDATORTOEXPRESSION_H
#include "Validator.h"

class ValidatorToExpression : public IValidator<std::string> {
public:
    bool isValid(std::string t) override;
};
#endif //FACTORY_VALIDATORTOEXPRESSION_H
