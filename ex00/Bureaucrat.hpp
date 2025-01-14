#pragma once

#include <iostream>

# define RESET "\x1b[0m"
# define BLUE "\x1b[34;01m"

# define GRADE_MIN 1
# define GRADE_MAX 150

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();
    std::string const &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);
