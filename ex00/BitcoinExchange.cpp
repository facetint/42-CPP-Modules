#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    priceData = other.priceData;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        priceData = other.priceData;
    }
    return *this;
}
void BitcoinExchange::processArgsAndFiles(int ac, char **av)
{
    if (ac != 2) {
        throw FileOpenException();
    }
    loadDatabase("data.csv");
    processInputFile(av[1]);
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw FileOpenException();
    }

    std::string line;
    getline(file, line); 

    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, priceStr;
        
        if (!getline(ss, date, ',') || !getline(ss, priceStr)) {
            continue;
        }

        trim(date);
        trim(priceStr);

        if (!isValidDate(date)) {
            throw InvalidDateException();
        }

        double price;
        std::stringstream priceStream(priceStr);
        priceStream >> price;

        if (priceStream.fail()) {
            throw std::runtime_error("Error: Invalid price in database.");
        }
        priceData[date] = price;
    }

    file.close();
    return true;
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw FileOpenException();

    std::string line;
    getline(file, line);

    while (getline(file, line))
    {
        if (!isValidFormat(line))
        {
            std::cerr << "Error: Bad input => " << line << std::endl;
            continue;
        }

        std::stringstream ss(line);
        std::string date, valueStr;
        getline(ss, date, '|');
        getline(ss, valueStr);

        trim(date);
        trim(valueStr);

        try {
            if (!isValidDate(date))
                throw InvalidDateException();

            if (!isValidValue(valueStr))
                throw InvalidValueException();

            double value;
            std::stringstream valueStream(valueStr);
            valueStream >> value;

            double rate = findClosestPrice(date);
            double result = value * rate;

            std::cout << date << " => " << value << " = " << result << std::endl;
        }   catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
        }
    }
    file.close();
}

double BitcoinExchange::findClosestPrice(const std::string& date)
{
    std::map<std::string, double>::iterator it = priceData.lower_bound(date);

    if (it == priceData.end() || it->first != date)
    {
        if (it == priceData.begin())
            throw std::runtime_error("Error: No earlier data available.");
        --it;
    }
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    char dash1, dash2;
    std::stringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (ss.fail() || dash1 != '-' || dash2 != '-') {
        return false;
    }

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    if (month == 2)
    {
        if (isLeapYear(year) && day > 29)
            return false;
        if (!isLeapYear(year) && day > 28)
            return false;
    }
    return true;
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidValue(const std::string& value)
{
    double val;
    std::stringstream ss(value);
    ss >> val;

    if (ss.fail() || val < 0 || val > 1000) {
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidFormat(const std::string& line)
{
    size_t pos = line.find('|');
    if (pos == std::string::npos)
        return false;

    std::string date = line.substr(0, pos);
    std::string value = line.substr(pos + 1);

    trim(date);
    trim(value);

    if (date.empty() || value.empty())
        return false;
    return true;
}

void BitcoinExchange::trim(std::string& str)
{
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");

    if (first == std::string::npos || last == std::string::npos)
        str = "";
    else
        str = str.substr(first, last - first + 1);
}

bool BitcoinExchange::isDigitsOnly(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}
