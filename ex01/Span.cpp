#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
    if (this == &other)
        return *this;
    _maxSize = other._maxSize;
    _numbers = other._numbers;
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_numbers.size() == _maxSize)
        throw std::overflow_error("Span is full.");
    _numbers.push_back(number);
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Span has less than 2 numbers.");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); i++)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Span has less than 2 numbers.");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}
