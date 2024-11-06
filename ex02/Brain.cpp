#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default constructor called - (Brain)" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Destructor called - (Brain)" << std::endl;
}

Brain::Brain(const Brain &other)
{
    for (int i = 0; i < 100; i++){
        ideas[i] = other.ideas[i];
    }
    std::cout << "Copy constructor called - (Brain)" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Assignation operator called - (Brain)" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++){
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    std::cout << "Idea index out of bounds - (Brain)" << std::endl;
    return "";
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
    else
        std::cout << "Idea index out of bounds - (Brain)" << std::endl;
}

std::string Brain::getIdeas() const
{
   return ideas[0];
}
