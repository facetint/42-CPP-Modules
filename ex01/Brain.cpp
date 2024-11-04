#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.getIdea(i);
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    for (int i = 0; i < 100; i++)
            ideas[i] = other.getIdea(i);
    return *this;
}

std::string Brain::getIdea(int index) const
{
    if (index < 0 || index >= 100)
    {
        std::cerr << "Index out of range" << std::endl;
        return ;
    }
    return ideas[index];
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index < 0 || index >= 100)
    {
        std::cerr << "Index out of range" << std::endl;
        return ;
    }
    ideas[index] = idea;
}