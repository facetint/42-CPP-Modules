#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    std::cout << "Bureaucrat assignation operator called" << std::endl;
    if (this != &other)
    {
        this->_grade = other._grade;
        setName(other.getName());
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string const &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::setName(std::string const name)
{
    const_cast<std::string &>(_name) = name;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

void Bureaucrat::incrementGrade()
{
    if (_grade <= GRADE_MIN)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= GRADE_MAX)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << BLUE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
    return out;
}
