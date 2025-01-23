#pragma once

template <typename T>

class Array
{
    private:
        T *_arr;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(Array const &other);
        ~Array();
        Array &operator=(Array const &other);
        const T &operator[](unsigned int i) const;
        T &operator[](unsigned int i);
        unsigned int size() const;

};

#include "Array.tpp"