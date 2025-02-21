#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try {
        BitcoinExchange btcExchange;

        btcExchange.processArgsAndFiles(ac, av);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}