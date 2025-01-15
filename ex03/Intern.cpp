#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

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

static AForm* createShrubberyForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

const char *Intern::FormNotFound::what() const throw()
{
    return (RED "Form not found" RESET);
}

AForm* Intern::makeForm(std::string const &formName, std::string const &target)
{
    static const t_form formTypes[] = {
        {"shrubbery creation", createShrubberyForm},
        {"robotomy request", createRobotomyForm},
        {"presidential pardon", createPresidentialPardonForm}
    };

    const size_t formCount = sizeof(formTypes) / sizeof(formTypes[0]);

    for (size_t i = 0; i < formCount; ++i) {
        if (formName == formTypes[i].name) {
            std::cout << PURPLE << "Intern creates " << formName << " form" << RESET << std::endl;
            return formTypes[i].create(target);
        }
    }
    throw FormNotFound();
}
