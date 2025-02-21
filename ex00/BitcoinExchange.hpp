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

        bool isValidDate(const std::string& date);
        bool isValidValue(const std::string& value);
        bool isValidFormat(const std::string& line);
        bool isLeapYear(int year);
        double findClosestPrice(const std::string& date);
        void trim(std::string& str);
        bool isDigitsOnly(const std::string& str);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);

        bool loadDatabase(const std::string& filename);
        void processInputFile(const std::string& filename);
        void processArgsAndFiles(int ac, char **av);

};
