#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "Default constructor called - (RobotomyRequestForm)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "Parametric constructor called - (RobotomyRequestForm)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), _target(other._target)
{
    std::cout << "Copy constructor called - (RobotomyRequestForm)" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    std::cout << "Assignation operator called - (RobotomyRequestForm)" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        setTarget(other.getTarget());
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor called - (RobotomyRequestForm)" << std::endl;
}

std::string const &RobotomyRequestForm::getTarget() const
{
    return _target;
}

void RobotomyRequestForm::setTarget(std::string target)
{
    const_cast<std::string &>(_target) = target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() < getGradeToExecute())
    {
        if (getSigned())
        {
            std::cout << "*drilling noises* " << std::endl;
            srand(time(NULL));
            if (rand() % 2)
                std::cout << _target << " has been robotomized successfully." << std::endl;
            else
                std::cout << _target << " robotomization failed." << std::endl;
        }
            std::cout << "Form is not signed." << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}
