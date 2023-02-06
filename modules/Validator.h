#pragma once
#include <iostream>
#include <regex>

template<typename T>
class IValidator {
public:
    virtual bool isValid(T t) {
        return false;
    }
};


