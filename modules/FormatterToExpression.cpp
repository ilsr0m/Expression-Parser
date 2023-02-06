#include "FormatterToExpression.h"
#include <string>
#include <regex>

void FormatterToExpression::format(std::string &format_str) {
    format_str.erase(std::remove(format_str.begin(), format_str.end(), ' '), format_str.end()); // remove all spaces
    for (int i = 0; i < format_str.size(); i++)
    {
        // sets 0 where '-' defines negative number for better algorithm work
        if (format_str[i] == format_str[0] && format_str[i] == '-') format_str.insert(i, 1, '0');
        if (format_str[i] == '(' && format_str[i + 1] == '-') format_str.insert(i + 1, 1, '0');
    }
}
