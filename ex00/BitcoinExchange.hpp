#pragma once

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <exception>

# define RED "\x1b[31;01m"
# define RESET "\x1b[0m"

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
    
        class InvalidDateException : public std::exception 
        {
        public:
            const char* what() const throw() { return RED "Error: Invalid date format." RESET; }
        };

        class InvalidValueException : public std::exception 
        {
        public:
            const char* what() const throw() { return RED "Error: Value must be between 0 and 1000." RESET; }
        };

        class FileOpenException : public std::exception
        {
        public:
            const char* what() const throw() { return RED "Error: Could not open file." RESET; }
        };

        class BadInputFormatException : public std::exception
        {
        public:
            const char* what() const throw() { return RED "Error: Bad input format." RESET; }
        };

};
