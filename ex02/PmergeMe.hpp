#pragma once

#include <deque>
#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ctime>

# define RED "\x1b[31;01m"
# define RESET "\x1b[0m"
# define PURPLE "\x1b[38;2;178;58;238;01m"
# define WHITE "\x1b[37;01m"

template <class Container, class Pair>
class FordJohnson
{
    private:
        Container numbers;
        Container toInsert;
        Container sortedSequence;
        Container positions;
        Pair pairs;

    public:
        FordJohnson();
        ~FordJohnson();
        FordJohnson(const FordJohnson &other);
        FordJohnson &operator=(const FordJohnson &other);
        double time;

        void printBefore();
        void printAfter();
        void parseInputArguments(int ac, char **av);
        void fordJohnson();
        void groupPairs(Pair &pairs);
        void sortPairs(Pair &pairs);
        Container const &getSequence() const;
        void mergeSort(typename Pair::iterator begin, typename Pair::iterator end);
        void merge(typename Pair::iterator begin, typename Pair::iterator mid, typename Pair::iterator end);
        void insertionSort();
        Container generateJacobsthalPositions(unsigned int n);
        typename Container::iterator binarySearch(Container& numbers, int value);
        void printTime(size_t elementCount);

    class InvalidInputException : public std::exception {
        const char* what() const throw() {
            return RED "Error: Invalid input." RESET;
        }
    };
};

class Vector : public FordJohnson< std::vector<int>, std::vector<std::pair<int, int> > > 
{
    private:
        Vector();
        Vector(const Vector &other);
        Vector &operator=(const Vector &other);
    public:
        Vector(int ac, char **av);
        ~Vector();
           
};

class Deque : public FordJohnson< std::deque<int>, std::deque<std::pair<int, int> > > 
{
    private:
        Deque();
        Deque(const Deque &other);
        Deque &operator=(const Deque &other);
    public:
        Deque(int ac, char **av);
        ~Deque();

};

#include "PmergeMe.tpp"