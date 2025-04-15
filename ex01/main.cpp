#include "RPN.hpp"

int main(int ac, char** av)
{
    if (ac < 2) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return 1;
    }
    std::string expression;
    for (int i = 1; i < ac; ++i)
    {
        expression += av[i];
        if (i < ac - 1)
            expression += " ";
    }
    try {
        int result = RPN::evaluate(expression);
        
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
