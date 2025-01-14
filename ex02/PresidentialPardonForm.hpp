#pragma once

# include "AForm.hpp"

class Bureaucrat;

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