#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array const &other) : _arr(new T[other._size]), _size(other._size)
{
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = other._arr[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] _arr;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    if (this != &other)
    {
        delete[] _arr;
        _arr = new T[other._size];
        _size = other._size;
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = other._arr[i];
    }
    return (*this);
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return (_arr[i]);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return (_arr[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}
