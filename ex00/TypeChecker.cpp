#include "ScalarConverter.hpp"

static bool checkChar(const std::string& input)
{
    if (input.size() == 1 && isprint(input[0]) && !isdigit(input[0]))
        return true;
    return false;
}

static bool checkInt(const std::string& input)
{
    size_t start = 0;
    if (input.size() == 1 && (input[0] == '+' || input[0] == '-'))
    {
        std::cerr << "Error: Invalid float format!" << std::endl;
        return false;
    }
    start = 1;
    for (size_t i = start; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
        {
            std::cerr << "Error: Invalid characters in integer!" << std::endl;
            return false;
        }
    }
    long n = 0;
    bool isNegative = (input[0] == '-');
    for (size_t i = start; i < input.size(); i++)
    {
        n = n * 10 + (input[i] - '0');
        if ((!isNegative && n > INT_MAX) || (isNegative && -n < INT_MIN))
        {
            std::cerr << "Error: Integer out of range!" << std::endl;
            return false;
        }
    }
    return true;
}

static bool checkFloat(const std::string& input)
{
    size_t start = 0;
    if (input[0] == '-' || input[0] == '+')
        start = 1;

    bool pointFound = false;
    bool hasDigits = false;

    for (size_t i = start; i < input.size(); i++)
    {
        if (isdigit(input[i]))
            hasDigits = true;
        else if (input[i] == '.' && !pointFound)
            pointFound = true;
        else if (input[i] == 'f' && i == input.size() - 1)
            continue;
        else
        {
            std::cerr << "Error: Invalid characters in float!" << std::endl;
            return false;
        }
    }
    return true;
}

static bool checkDouble(const std::string &input)
{
    bool pointFound = false;
    int digitCount = 0;
    size_t i = 0;

    if (input[0] == '+' || input[0] == '-')
        i++;

    for (; i < input.length(); i++)
    {
        if (isdigit(input[i]))
            digitCount++;
        else if (input[i] == '.' && !pointFound)
            pointFound = true;
        else
            return false;
    }
    return pointFound && digitCount > 0;
}

static bool checkPseudoLiterals(const std::string& input)
{
    if (input == "nan" || input == "nanf" || input == "-inf" || input == "+inf" ||
        input == "-inff" || input == "+inff") {
        return true;
    }
    else
        std::cerr << "Error: Invalid pseudo-literal!" << std::endl;
    return false;
}

ScalarType ScalarConverter::checkType(const std::string& input)
{
    if (checkChar(input))
        return CHAR;
    if (checkFloat(input))
        return FLOAT;
    if (checkDouble(input))
        return DOUBLE;
    if (checkInt(input))
        return INT;
    if (checkPseudoLiterals(input))
        return PSEUDO_LITERAL;
    return UNKNOWN;
}
