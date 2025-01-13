#pragma once

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    const std::string _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    virtual ~RobotomyRequestForm();

    std::string const &getTarget() const;
    void setTarget(std::string target);

    void execute(Bureaucrat const &executor) const;
};
