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

        template <typename Iter>
        void addNumbersRange(Iter begin, Iter end)
        {
            size_t distance = std::distance(begin, end);
            if (_numbers.size() + distance > _maxSize)
            {
                throw std::overflow_error("Span cannot accommodate all numbers in the range.");
            }
            _numbers.insert(_numbers.end(), begin, end);
        }
};
