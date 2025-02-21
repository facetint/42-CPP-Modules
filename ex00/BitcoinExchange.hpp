#pragma once

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <exception>

class BitcoinExchange
{
    private:
        std::map<std::string, double> priceData; 


    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);

        bool loadDatabase(const std::string& filename);
        void processInputFile(const std::string& filename);
        void processArgsAndFiles(int ac, char **av);
    
};
