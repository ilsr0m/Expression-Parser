//
// Created by 1 on 06.02.2023.
//

#ifndef FACTORY_VALIDATORTOOPERATOR_H
#define FACTORY_VALIDATORTOOPERATOR_H
#include "Validator.h"

class ValidatorToOperator : public IValidator<char> {
public:
    bool isValid(char t) override;
};



#endif //FACTORY_VALIDATORTOOPERATOR_H
