#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat1("user1", 50);
        Bureaucrat bureaucrat2("user2", 140);
        Bureaucrat bureaucrat3("user3", 1);

        std::cout << bureaucrat1 << std::endl;
        std::cout << bureaucrat2 << std::endl;
        std::cout << bureaucrat3 << std::endl;

        PresidentialPardonForm pardonForm("Target1");
        ShrubberyCreationForm shrubberyForm("Target2");
        RobotomyRequestForm robotomyForm("Target3");

        std::cout << "\nTrying to sign forms..." << std::endl;

        bureaucrat1.signForm(pardonForm);
        bureaucrat2.signForm(robotomyForm);
        bureaucrat3.signForm(shrubberyForm);

        std::cout << "\nTrying to execute forms..." << std::endl;

        
        bureaucrat1.executeForm(pardonForm);
        bureaucrat2.executeForm(robotomyForm);
        bureaucrat3.executeForm(shrubberyForm);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
