#pragma once

#include <stack>
#include <deque>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:

    MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack &operator=(const MutantStack &other);
    ~MutantStack();

    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;
    typedef typename std::deque<T>::reverse_iterator reverse_iterator;
    typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

