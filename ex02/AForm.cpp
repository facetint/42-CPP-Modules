#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signGrade(gradeToSign), _executeGrade(gradeToExecute)
{
    std::cout << "AForm parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    setSign(false);
}

AForm::AForm(AForm const &other) : _name(other.getName()), _signGrade(other.getGradeToSign()), _executeGrade(other.getGradeToExecute())
{
    std::cout << "AForm copy constructor called" << std::endl;
    *this = other;
}

AForm &AForm::operator=(AForm const &other)
{
    std::cout << "AForm assignation operator called" << std::endl;
    if (this != &other)
    {
        setName(other.getName());
        setSign(other.getSigned());
        setGradeToSign(other.getGradeToSign());
        setGradeToExecute(other.getGradeToExecute());
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}
