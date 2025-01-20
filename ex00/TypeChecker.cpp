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
    for (size_t i = start; i < input.size(); i++) {
        if (!isdigit(input[i])) {
            std::cerr << "Error: Invalid characters in integer!" << std::endl;
            return false;
        }
    }

    try {
        long n = std::stol(input);
        if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max()) {
            std::cerr << "Error: Integer out of range!" << std::endl;
            return false;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid argument for integer conversion!" << std::endl;
        return false;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Integer out of range!" << std::endl;
        return false;
    }

    return true;
}


static bool checkFloat(const std::string& input)
{
    size_t start = 0;
    if (input[0] == '-' || input[0] == '+')
        start = 1;

    bool pointFound = false;
    for (size_t i = start; i < input.size(); i++) {
        if (!isdigit(input[i])) {
            if (input[i] == '.' && !pointFound)
                pointFound = true;
            else if (input[i] != 'f') {
                std::cerr << "Error: Invalid characters in float!" << std::endl;
                return false;
            }
        }
    }

    if (input.back() == 'f') {
        try {
            std::stof(input);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid argument for float!" << std::endl;
            return false;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Float out of range!" << std::endl;
            return false;
        }
    }
    return true;
}

static bool checkDouble(const std::string& input)
{
    size_t start = 0;
    if (input[0] == '-' || input[0] == '+')
        start = 1;

    bool pointFound = false;
    for (size_t i = start; i < input.size(); i++) {
        if (!isdigit(input[i])) {
            if (input[i] == '.' && !pointFound)
                pointFound = true;
            else {
                std::cerr << "Error: Invalid characters in double!" << std::endl;
                return false;
            }
        }
    }

    try {
        std::stod(input);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid argument for double conversion!" << std::endl;
        return false;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Double out of range!" << std::endl;
        return false;
    }
    return true;
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
