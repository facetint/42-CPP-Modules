#include "PmergeMe.hpp"

int main(int ac, char** av)
{ 
    try
    {
        FordJohnson<std::vector<int>, std::vector<std::pair<int, int > > > vector = Vector(ac, av);
        vector.fordJohnson();
        
        FordJohnson<std::deque<int>, std::deque<std::pair<int, int > > > deque = Deque(ac, av);
        deque.fordJohnson();

        vector.printBefore();
        vector.printAfter();
        vector.printTime(ac - 1);
        deque.printTime(ac - 1);

    } catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
