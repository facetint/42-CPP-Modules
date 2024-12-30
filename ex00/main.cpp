#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat *bureaucrat1 = new Bureaucrat("facetint", 10);
        Bureaucrat *bureaucrat2 = new Bureaucrat("fatmanur", 140);

        std::cout << *bureaucrat1 << std::endl;
        std::cout << *bureaucrat2 << std::endl;

        bureaucrat1->incrementGrade();
        std::cout << "After increment: " << *bureaucrat1 << std::endl;

        bureaucrat2->decrementGrade();
        std::cout << "After decrement: " << *bureaucrat2 << std::endl;

        for (int i = 0; i < 10; ++i)
        {
            bureaucrat1->incrementGrade();
        }
        delete bureaucrat1;
        delete bureaucrat2;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "GradeTooHighException caught: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "GradeTooLowException caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat *invalidBureaucrat = new Bureaucrat("Invalid", 200);
        delete invalidBureaucrat;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "GradeTooHighException caught: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "GradeTooLowException caught: " << e.what() << std::endl;
    }

    return 0;
}
