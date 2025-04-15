#include "PmergeMe.hpp"

int main(int ac, char** av)
{ 
    try
    {
        FordJhonson<std::vector<int>, std::vector<std::pair<int, int > > > vector;
        vector.process(ac, av);

        FordJhonson<std::deque<int>, std::deque<std::pair<int, int > > > deque;
        deque.process(ac, av);

        vector.printBefore();
        vector.printAfter();

    } catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
