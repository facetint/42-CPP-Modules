#pragma once

# include <iostream>

class AForm;

# define RED "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32;01m"
# define WHITE "\x1b[38;2;255;255;255;01m"
# define PURPLE "\x1b[38;2;178;58;238;01m"

class Intern
{
private:
    typedef struct s_form
    {
        std::string name;
        AForm *(*create)(const std::string &);
    } t_form;

public:
    Intern();
    Intern(Intern const &other);
    Intern &operator=(Intern const &other);
    ~Intern();

    AForm *makeForm(std::string const &formName, std::string const &target);
    class FormNotFound : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};
