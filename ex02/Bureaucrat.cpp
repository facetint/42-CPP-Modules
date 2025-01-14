#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
    {
        this->_grade = other._grade;
        setName(other.getName());
    }
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

void Bureaucrat::signForm(AForm &form)
{
    if (form.getSigned())
        std::cout << _name << " cannot sign " << form.getName() << " because it's already signed." << std::endl;
    else
        std::cout << this->_name << " couldn't sign " << form.getName() << " because he don't have the ability to do this." << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executes " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << BLUE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
    return out;
}
