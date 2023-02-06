#pragma once
#include "IFormatter.h"
class FormatterToExpression : public IFormatter {
    void format(std::string &format_str) override;
};