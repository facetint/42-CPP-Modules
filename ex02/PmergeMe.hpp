#pragma once

#include <deque>
#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ctime>

template <class NumberContainer, class Pair>
class FordJhonson
{
    private:
        NumberContainer container;
        NumberContainer pend;
        NumberContainer mainChain;
        NumberContainer positions;
        Pair pairs;

    public:
        FordJhonson();
        ~FordJhonson();
        FordJhonson(const FordJhonson &other);
        FordJhonson &operator=(const FordJhonson &other);

        void printBefore();
        void printAfter();
        void parseAndSetSequence(int ac, char **av);
        void process(int ac, char **av);
        void fordJohnson();
        void groupPairs(Pair &pairs);
        void sortPairs(Pair &pairs);
        NumberContainer const &getSequence() const;
        void printContainer();
        void printPairs(Pair &pairs);
        void mergeSort(typename Pair::iterator begin, typename Pair::iterator end);
        void merge(typename Pair::iterator begin, typename Pair::iterator mid, typename Pair::iterator end);
        void insertionSort();
        NumberContainer generateJacobsthalNumbers(unsigned int n);
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