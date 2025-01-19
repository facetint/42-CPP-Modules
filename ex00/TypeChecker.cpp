#include "ScalarConverter.hpp"

static bool checkChar(const std::string& input)
{
    if (input[0] != '\'' || input[2] != '\'' || !isprint(input[1]))
        return false;
    return true;
}

static bool checkInt(const std::string& input)
{
    size_t start = 0;
    if (input[0] == '-' || input[0] == '+')
        start = 1;
    for (size_t i = start; i < input.size(); i++)
    {
        if (!isdigit(input[i])) {
            std::cerr << "Error: Invalid characters in integer!" << std::endl;
            return false;
        }
    }

    try {
        std::stoi(input);
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
    for (size_t i = start; i < input.size(); i++)
    {
        if (!isdigit(input[i]) && input[i] != '.') {
            std::cerr << "Error: Invalid characters in float!" << std::endl;
            return false;
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
    for (size_t i = start; i < input.size(); i++)
    {
        if (!isdigit(input[i]) && input[i] != '.') {
            std::cerr << "Error: Invalid characters in double!" << std::endl;
            return false;
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

    std::cerr << "Error: Invalid pseudo-literal!" << std::endl;
    return false;
}

ScalarType ScalarConverter::checkType(const std::string& input)
{
    if (checkChar(input))
        return CHAR;
    if (checkInt(input))
        return INT;
    if (checkFloat(input))
        return FLOAT;
    if (checkDouble(input))
        return DOUBLE;
    if (checkPseudoLiterals(input))
        return PSEUDO_LITERAL;
    return UNKNOWN;
}
