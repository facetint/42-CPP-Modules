#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    std::cout << "Default constructor called - (Bureaucrat)" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    std::cout << "Parameterized constructor called - (Bureaucrat)" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
    std::cout << "Copy constructor called - (Bureaucrat)" << std::endl;
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    std::cout << "Assignation operator called - (Bureaucrat)" << std::endl;
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called - (Bureaucrat)" << std::endl;
}

std::string const &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return (RED "Grade is too high" RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return (RED "Grade is too low" RESET);
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

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << WHITE << _name << " signs " << form.getName() << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << WHITE << _name << " cannot sign " << form.getName() << " because " << RESET;
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << BLUE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
    return out;
}
