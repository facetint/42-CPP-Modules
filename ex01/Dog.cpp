#include "Dog.hpp"

Dog::Dog()
{
    setType("Dog");
    brain = new Brain();
    std::cout << "Default constructor called - (Dog)" << std::endl;
}

Dog::Dog(const Dog& other)
{
    *this = other;
    std::cout << "Copy constructor called - (Dog)" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Destructor called - (Dog)" << std::endl;
    delete brain;
}
Dog& Dog::operator=(const Dog& other)
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
    std::cout << "Assignation operator called - (Dog)" << std::endl;
    return *this;
}


void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;   
}

Brain *Dog::getBrain() const
{
    return brain;
}