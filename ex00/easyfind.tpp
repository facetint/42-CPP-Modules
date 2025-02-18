#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>

const char *NotFoundException::what() const throw()
{
    return RED "Value not found" RESET;
}

template <typename T>
int easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        return *it;
    throw NotFoundException();
}

template <typename T>
void testEasyFind(T &container, int value)
{
    std::cout << WHITE "Searching for: " << value << " ..." RESET << std::endl;
    try {
        int result = easyfind(container, value);
        std::cout << GREEN "✅ Found " << value << " in container: " << result << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cout << RED "❌ " << e.what() << " (Value: " << value << ")" RESET << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
}
