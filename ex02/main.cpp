#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try 
    {
        Bureaucrat bureaucrat1("user1", 4);
        Bureaucrat bureaucrat2("user2", 42);
        Bureaucrat bureaucrat3("user3", 120);

        std::cout << bureaucrat1 << std::endl;
        std::cout << bureaucrat2 << std::endl;
        std::cout << bureaucrat3 << std::endl;

        PresidentialPardonForm pardonForm("target1");
        ShrubberyCreationForm shrubberyForm("target2");
        RobotomyRequestForm robotomyForm("target3");

        std::cout << std::endl;
        std::cout << "~ - - Trying to sign forms - - ~" << std::endl;

        bureaucrat1.signForm(pardonForm);
        bureaucrat2.signForm(robotomyForm);
        bureaucrat3.signForm(shrubberyForm);

        std::cout << std::endl;
        std::cout << "~ - - Trying to execute forms - - ~" << std::endl;

    
        bureaucrat1.executeForm(pardonForm);
        bureaucrat2.executeForm(robotomyForm);
        bureaucrat3.executeForm(shrubberyForm);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
