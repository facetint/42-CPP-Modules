#include "Form.hpp"

int main()
{
    Bureaucrat *bureaucrat1 = new Bureaucrat("facetint", 11);
    Form *form1 = new Form("form1", 10, 10);

    std::cout << *bureaucrat1 << std::endl;
    std::cout << *form1 << std::endl;

    try
    {
        form1->beSigned(*bureaucrat1);
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Exception caught: " << e.what() << std::endl << RESET;
    }

    std::cout << *form1 << std::endl;

    delete bureaucrat1;
    delete form1;

    return 0;
}
