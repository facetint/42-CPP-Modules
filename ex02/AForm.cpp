#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
    std::cout << "Default constructor called - (AForm)" << std::endl;
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signGrade(gradeToSign), _executeGrade(gradeToExecute)
{
    std::cout << "Parametric constructor called - (AForm)" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    setSign(false);
}

AForm::AForm(AForm const &other) : _name(other.getName()), _signGrade(other.getGradeToSign()), _executeGrade(other.getGradeToExecute())
{
    std::cout << "Copy constructor called - (AForm)" << std::endl;
    *this = other;
}

AForm &AForm::operator=(AForm const &other)
{
    std::cout << "Assignation operator called - (AForm)" << std::endl;
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
    std::cout << "Destructor called - (AForm)" << std::endl;
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

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    out << WHITE << "  - - - Form details - - - " << RESET << std::endl;
    out << GREEN << "Form name: " << RESET << WHITE << form.getName() << std::endl << RESET;
    out << GREEN << "Form sign grade: " << RESET << WHITE << form.getGradeToSign() << std::endl << RESET;
    out << GREEN << "Form execute grade: " << RESET << WHITE << form.getGradeToExecute() << std::endl << RESET;
    out << GREEN << "Form signed: " << RESET << WHITE << form.getSigned() << std::endl << RESET;
    return out;
}
