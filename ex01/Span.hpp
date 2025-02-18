#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
        Span();

    public:
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
};
