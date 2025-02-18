#pragma once

#include <exception>

# define RED "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32;01m"
# define PURPLE "\x1b[38;2;178;58;238;01m"
# define WHITE "\x1b[37;01m"

class NotFoundException : public std::exception
{
public:
    virtual const char *what() const throw();
};

template <typename T>
int easyfind(T &container, int value);

template <typename T>
void testEasyFind(T &container, int value);

#include "easyfind.tpp"
