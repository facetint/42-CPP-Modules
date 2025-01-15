#pragma once

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class Bureaucrat;

# define RED "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32;01m"

class RobotomyRequestForm : public AForm
{
private:
    const std::string _target;
    RobotomyRequestForm();

public:
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    virtual ~RobotomyRequestForm();

    std::string const &getTarget() const;

    void execute(Bureaucrat const &executor) const;
};
