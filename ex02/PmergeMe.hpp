#pragma once

#include <deque>
#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ctime>

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

        void printBefore();
        void printAfter();
        void parseInputArguments(int ac, char **av);
        void run(int ac, char **av);
        void fordJohnson();
        void groupPairs(Pair &pairs);
        void sortPairs(Pair &pairs);
        Container const &getSequence() const;
        void printContainer();
        void printPairs(Pair &pairs);
        void mergeSort(typename Pair::iterator begin, typename Pair::iterator end);
        void merge(typename Pair::iterator begin, typename Pair::iterator mid, typename Pair::iterator end);
        void insertionSort();
        Container generateJacobsthalPositions(unsigned int n);
        typename Container::iterator binarySearch(Container& numbers, int value);
        void printTime(size_t elementCount, clock_t end);

    class InvalidInputException : public std::exception {
        const char* what() const throw() {
            return "Error: Invalid input.";
        }
    };

    class EmptyContainerException : public std::exception {
        const char* what() const throw() {
            return "Error: No numbers provided.";
        }
    };
};

#include "PmergeMe.tpp"