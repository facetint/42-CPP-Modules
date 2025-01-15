#pragma once

# include <iostream>

class Bureaucrat;

# define RED "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32;01m"
# define WHITE "\x1b[38;2;255;255;255;01m"
# define PURPLE "\x1b[38;2;178;58;238;01m"


class AForm
{
private:
    std::string const _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;

public:
    AForm();
    AForm(std::string const name, int gradeToSign, int gradeToExecute);
    AForm(AForm const &other);
    AForm &operator=(AForm const &other);
    virtual ~AForm();

    std::string const &getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool getSigned() const;

    void setSign(bool sign);

    void beSigned(const Bureaucrat &bureaucrat);

    virtual void execute(Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &out, AForm const &form);
