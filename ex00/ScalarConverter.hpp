#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cfloat>
#include <limits.h>
#include <iomanip>

enum ScalarType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_LITERAL,
    UNKNOWN
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &src);
        ~ScalarConverter();
        ScalarConverter & operator=(ScalarConverter const &other);
        static ScalarType checkType(const std::string& input);

    public:
        static void convert(std::string input);
};
