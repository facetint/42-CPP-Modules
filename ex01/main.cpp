#include "RPN.hpp"

int main(int ac, char** av)
{
    if (ac != 2) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return 1;
    }
    try {
        std::string expression = av[1];
        int result = RPN::evaluate(expression);        
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
