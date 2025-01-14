#pragma once

# include <fstream>
# include "AForm.hpp"

class Bureaucrat;

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
    void setTarget(std::string target);

    void execute(Bureaucrat const &executor) const;

};
