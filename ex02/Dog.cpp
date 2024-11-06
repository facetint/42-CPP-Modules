#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    try
    {
        setType("Dog");
        brain = new Brain();
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Memory Allocation Error: " << e.what() << std::endl;
        brain = NULL;
        throw;
    }
    std::cout << "Default constructor called - (Dog)" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal()
{
    try {
        this->brain = new Brain(*other.brain);
        setType(other.getType());
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory Allocation Error: " << e.what() << std::endl;
        throw;
    }
    std::cout << "Copy constructor called - (Dog)" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Destructor called - (Dog)" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        delete this->brain;
        try {
            this->setType(other.getType());
            this->brain = new Brain(*other.brain);
        } catch (const std::bad_alloc& e) {
            std::cerr << "Memory Allocation Error: " << e.what() << std::endl;
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

void Dog::display() const
{
    std::string idea = getBrain()->getIdeas();

    std::cout << "My type is: " << getType() << std::endl;
    if (idea != "") {
        std::cout << "My idea is: " << idea << std::endl;
    } else {
        std::cout << "I have no idea :(" << std::endl;
    }
    makeSound();
}
