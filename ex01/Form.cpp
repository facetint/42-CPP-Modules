#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
    std::cout << "Default constructor called - (Form)" << std::endl;
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signGrade(gradeToSign), _executeGrade(gradeToExecute)
{
    std::cout << "Parametric constructor called - (Form)" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    setSign(false);
}

Form::Form(Form const &other) : _name(other.getName()), _signGrade(other.getGradeToSign()), _executeGrade(other.getGradeToExecute())
{
    std::cout << "Copy constructor called - (Form)" << std::endl;
    *this = other;
}

Form &Form::operator=(Form const &other)
{
    std::cout << "Assignation operator called - (Form)" << std::endl;
    if (this != &other)
    {
        setName(other.getName());
        setSign(other.getSigned());
        setGradeToSign(other.getGradeToSign());
        setGradeToExecute(other.getGradeToExecute());
    }
    return *this;
}

Form::~Form()
{
    std::cout << "Destructor called - (Form)" << std::endl;
}

std::string const &Form::getName() const
{
    return _name;
}

int Form::getGradeToSign() const
{
    return _signGrade;
}

int Form::getGradeToExecute() const
{
    return _executeGrade;
}

bool Form::getSigned() const
{
    return _isSigned;
}

void Form::setName(std::string const name)
{
    const_cast<std::string &>(_name) = name;
}

void Form::setSign(bool sign)
{
    _isSigned = sign;
}

void Form::setGradeToSign(int gradeToSign)
{
    const_cast<int &>(_signGrade) = gradeToSign;
}

void Form::setGradeToExecute(int gradeToExecute)
{
    const_cast<int &>(_executeGrade) = gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > getGradeToSign())
        throw Form::GradeTooLowException();
    setSign(true);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << WHITE << "  - - - Form details - - - " << RESET << std::endl;
    out << GREEN << "Form name: " << RESET << WHITE << form.getName() << std::endl << RESET;
    out << GREEN << "Form sign grade: " << RESET << WHITE << form.getGradeToSign() << std::endl << RESET;
    out << GREEN << "Form execute grade: " << RESET << WHITE << form.getGradeToExecute() << std::endl << RESET;
    out << GREEN << "Form signed: " << RESET << WHITE << form.getSigned() << std::endl << RESET;
    return out;
}

