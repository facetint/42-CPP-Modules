#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default constructor called - (Dog)" << std::endl;
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
}

Dog::Dog(const Dog& other)
{
    std::cout << "Copy constructor called - (Dog)" << std::endl;
    try {
        this->brain = new Brain(*other.brain);
        setType(other.getType());
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory Allocation Error: " << e.what() << std::endl;
        throw;
    }
    *this = other;
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

void Dog::display() const
{
    static int i = 0;
    std::string idea = getBrain()->getIdea(i);

    std::cout << "My type is: " << getType()  << std::endl;
    if (idea != "") {
       std::cout << "My idea at index " << i << " is: " << idea << std::endl;
    } else {
        std::cout  << "I have no idea :("  << std::endl;
    }
    i++;
    makeSound();
}
