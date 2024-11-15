#pragma once

#include <iostream>

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
    void incrementGrade() const;
    void decrementGrade() const;

};