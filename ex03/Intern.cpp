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

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{

    const std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*formCreators[])(const std::string&) = {
        [](const std::string& target) { return static_cast<AForm*>(new ShrubberyCreationForm(target)); },

        [](const std::string& target) { return static_cast<AForm*>(new RobotomyRequestForm(target)); },

        [](const std::string& target) { return static_cast<AForm*>(new PresidentialPardonForm(target)); }
    };
    const size_t formCount = sizeof(formNames) / sizeof(formNames[0]);
    for (size_t i = 0; i < formCount; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << " form" << std::endl;
            return formCreators[i](target);
        }
    }
    throw FormNotFound();
}
