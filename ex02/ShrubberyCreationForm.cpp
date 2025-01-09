#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "Default constructor called - (ShrubberyCreationForm)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Parametric constructor called - (ShrubberyCreationForm)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target)
{
    std::cout << "Copy constructor called - (ShrubberyCreationForm)" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    std::cout << "Assignation operator called - (ShrubberyCreationForm)" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        setTarget(other.getTarget());
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor called - (ShrubberyCreationForm)" << std::endl;
}

std::string const &ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::setTarget(std::string target)
{
    const_cast<std::string &>(_target) = target;
}

