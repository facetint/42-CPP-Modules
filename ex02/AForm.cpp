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

std::string const &AForm::getName() const
{
    return _name;
}

int AForm::getGradeToSign() const
{
    return _signGrade;
}

int AForm::getGradeToExecute() const
{
    return _executeGrade;
}

bool AForm::getSigned() const
{
    return _isSigned;
}

void AForm::setName(std::string const name)
{
    const_cast<std::string &>(_name) = name;
}

void AForm::setSign(bool sign)
{
    _isSigned = sign;
}

void AForm::setGradeToSign(int gradeToSign)
{
    const_cast<int &>(_signGrade) = gradeToSign;
}

void AForm::setGradeToExecute(int gradeToExecute)
{
    const_cast<int &>(_executeGrade) = gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > getGradeToSign())
        throw AForm::GradeTooLowException();
    setSign(true);
}
