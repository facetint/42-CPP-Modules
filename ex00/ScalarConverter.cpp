#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor called" << std::endl;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & other)
{
    std::cout << "Assignation operator called" << std::endl;
    (void)other;
    return *this;
}

static void charConvert(std::string param)
{
        char c = param[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void intConvert(std::string param)
{
    int n = atoi(param.c_str());

    if (n < 0 || n > 127)
        std::cout << "char: impossible" << std::endl;
    else if (n < 32 || n == 127)
        std::cout << "char: non-displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;

    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

static void floatConvert(std::string param)
{
    float n = atof(param.c_str());

    if (n < 0 || n > 127)
        std::cout << "char: impossible" << std::endl;
    else if (n < 32 || n == 127)
        std::cout << "char: non-displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;

    std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << n << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(n) << std::endl;
}

static void doubleConvert(std::string param)
{
    double n = atof(param.c_str());

    if (n < 0 || n > 127)
        std::cout << "char: impossible" << std::endl;
    else if (n < 32 || n == 127)
        std::cout << "char: non-displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;

    std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(2) << n << std::endl;
}

static void infConvert(std::string param)
{
    if (param == "nan" || param == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (param == "-inf" || param == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << INT_MIN << std::endl;
        std::cout << "float: " << __FLT_MIN__ << std::endl;
        std::cout << "double: " << __DBL_MIN__ << std::endl;
    }
    else if (param == "+inf" || param == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << INT_MAX << std::endl;
        std::cout << "float: " << __FLT_MAX__ << std::endl;
        std::cout << "double: " << __DBL_MAX__ << std::endl;
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::convert(std::string input)
{
   ScalarType type = ScalarConverter::checkType(input);
    switch (type)
    {
         case CHAR:
              charConvert(input);
              break;
         case INT:
              intConvert(input);
              break;
         case FLOAT:
              floatConvert(input);
              break;
         case DOUBLE:
              doubleConvert(input);
              break;
         case PSEUDO_LITERAL:
              infConvert(input);
              break;
         case UNKNOWN:
              std::cout << "Unknown type" << std::endl;
              break;
    }
}