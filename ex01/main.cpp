#include "Span.hpp"

int main()
{
    try {
        Span sp = Span(10);

        sp.addNumber(5);
        sp.addNumber(10);
        sp.addNumber(15);

        std::vector<int> numbers;
        numbers.push_back(20);
        numbers.push_back(25);
        numbers.push_back(30);
        numbers.push_back(35);
        numbers.push_back(40);
        sp.addNumbersRange(numbers.begin(), numbers.end());

        std::cout << PURPLE "\n----- Span Results ----- " RESET << std::endl;
        std::cout << WHITE "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        std::cout << "-------------------------" RESET << std::endl;

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
