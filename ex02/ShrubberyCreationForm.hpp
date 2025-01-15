#pragma once

# include <fstream>
# include "AForm.hpp"

class Bureaucrat;

# define RED "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32;01m"

class ShrubberyCreationForm : public AForm
{
private:
    const std::string _target;
    ShrubberyCreationForm();

public:
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &other);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
    virtual ~ShrubberyCreationForm();

    std::string const &getTarget() const;

    void execute(Bureaucrat const &executor) const;

};
