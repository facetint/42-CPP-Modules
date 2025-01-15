#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat1("user1", 50);
        Bureaucrat bureaucrat2("user2", 140);
        Bureaucrat bureaucrat3("user3", 1);

        std::cout << bureaucrat1 << std::endl;
        std::cout << bureaucrat2 << std::endl;
        std::cout << bureaucrat3 << std::endl;

        Intern someRandomIntern;

        std::cout << "\n - - - Intern is trying to create forms - - -" << std::endl;

        AForm* form1 = someRandomIntern.makeForm("robotomy request", "Target1");
        AForm* form2 = someRandomIntern.makeForm("presidential pardon", "Target2");
        AForm* form3 = someRandomIntern.makeForm("shrubbery creation", "Target3");

        std::cout << "\n - - - Trying to sign forms - - - " << std::endl;
        bureaucrat1.signForm(*form1);
        bureaucrat2.signForm(*form2);
        bureaucrat3.signForm(*form3);

        std::cout << "\n - - - Trying to execute forms - - -" << std::endl;
        bureaucrat1.executeForm(*form1);
        bureaucrat2.executeForm(*form2);
        bureaucrat3.executeForm(*form3);

        delete form1;
        delete form2;
        delete form3;

    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
