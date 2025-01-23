#ifndef ITER_HPP

# define ITER_HPP

#include <iostream>

# define RED "\x1b[31;01m"
# define RESET "\x1b[0m"
# define WHITE "\x1b[38;2;255;255;255;01m"

template <typename T , typename F>
void iter(T *arr, size_t len, F f)
{
    for (size_t i = 0; i < len; i++)
        f(arr[i]);
}

template <typename T>
void print(T arr)
{
    std::cout << WHITE << arr << RESET << std::endl;
}

#endif