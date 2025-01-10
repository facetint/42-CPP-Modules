#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

# define RED "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32;01m"
# define WHITE "\x1b[38;2;255;255;255;01m"
# define PURPLE "\x1b[38;2;178;58;238;01m"

class Form
{
private:
    std::string const _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;

public:
    Form();
    Form(std::string const name, int gradeToSign, int gradeToExecute);
    Form(Form const &other);
    Form &operator=(Form const &other);
    ~Form();

    std::string const &getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool getSigned() const;

    void setName(std::string const name);
    void setSign(bool sign);
    void setGradeToSign(int gradeToSign);
    void setGradeToExecute(int gradeToExecute);

    void beSigned(const Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, Form const &form);
