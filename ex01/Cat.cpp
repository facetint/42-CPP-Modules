#include "Cat.hpp"

Cat::Cat()
{
    setType("Cat");
    brain = new Brain();
    std::cout << "Default constructor called - (Cat)" << std::endl;
}

Cat::Cat(const Cat& other)
{
    *this = other;
    std::cout << "Copy constructor called - (Cat)" << std::endl;
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
        if (this->brain != nullptr) {
            delete this->brain;
        }
        try {
            this->brain = new Brain(*other.brain);
        } catch (const std::bad_alloc& e) {
            std::cerr << "Memory Allocation Error: " << e.what() << std::endl;
            this->brain = nullptr;
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

Brain Cat::getBrain() const
{
    return *brain;
}

void Cat::display() const{

    std::cout << this->brain->getIdea(0) << std::endl;
}