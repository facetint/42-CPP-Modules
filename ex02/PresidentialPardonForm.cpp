#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout << "Default constructor called - (PresidentialPardonForm)" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "Parametric constructor called - (PresidentialPardonForm)" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), _target(other._target)
{
    std::cout << "Copy constructor called - (PresidentialPardonForm)" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    std::cout << "Assignation operator called - (PresidentialPardonForm)" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        setTarget(other.getTarget());
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor called - (PresidentialPardonForm)" << std::endl;
}
