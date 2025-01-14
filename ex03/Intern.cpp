#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Default constructor called - (Intern)" << std::endl;
}

Intern::Intern(Intern const &other)
{
    std::cout << "Copy constructor called - (Intern)" << std::endl;
    *this = other;
}

Intern &Intern::operator=(Intern const &other)
{
    std::cout << "Assignation operator called - (Intern)" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Destructor called - (Intern)" << std::endl;
}

const char *Intern::FormNotFound::what() const throw()
{
    return "Form not found";
}


