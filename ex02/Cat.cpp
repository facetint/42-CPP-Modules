#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Default constructor called - (Cat)" << std::endl;

}

Cat::Cat(const Cat& other)
{
    std::cout << "Copy constructor called - (Cat)" << std::endl;
    try {
        this->brain = new Brain(*other.brain);
        setType(other.getType());
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory Allocation Error: " << e.what() << std::endl;
        throw;
    }
}
Cat::~Cat()
{
    std::cout << "Destructor called - (Cat)" << std::endl;
    delete brain;
}
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->setType(other.getType());
        if (this->brain != NULL) {
            delete this->brain; 
        }
        try {
            this->brain = new Brain(*other.brain);
        } catch (const std::bad_alloc& e) {
            std::cerr << "Memory Allocation Error: " << e.what() << std::endl;
            this->brain = NULL;
            throw;
        }
    }
    std::cout << "Assignation operator called - (Cat)" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}

Brain *Cat::getBrain() const
{
    return brain;
}

void Cat::display() const
{
    std::cout << "---------------------------" << std::endl;
    std::cout << WHITE_COLOR << "My type is: " << BLUE_COLOR << getType() << RESET << std::endl;
    makeSound();
    std::cout << "---------------------------" << std::endl;
}
