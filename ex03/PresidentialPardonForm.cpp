#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

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
        AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor called - (PresidentialPardonForm)" << std::endl;
}

std::string const &PresidentialPardonForm::getTarget() const
{
    return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (getSigned())
        std::cout << GREEN << _target << " has been pardoned by Zafod Beeblebrox." << RESET << std::endl;
    else
        std::cout << RED << "Form is not signed." << RESET << std::endl;
}
