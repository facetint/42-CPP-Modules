#pragma once

# include "AForm.hpp"

class Bureaucrat;;

# define RED "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32;01m"

class PresidentialPardonForm : public AForm
{
private:
    const std::string _target;
    PresidentialPardonForm();

public:
    PresidentialPardonForm(const std::string target);
    PresidentialPardonForm(PresidentialPardonForm const &other);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
    virtual ~PresidentialPardonForm();

    std::string const &getTarget() const;

    void execute(Bureaucrat const &executor) const;
};