#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "Default constructor called - (ShrubberyCreationForm)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Parametric constructor called - (ShrubberyCreationForm)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target)
{
    std::cout << "Copy constructor called - (ShrubberyCreationForm)" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    std::cout << "Assignation operator called - (ShrubberyCreationForm)" << std::endl;
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor called - (ShrubberyCreationForm)" << std::endl;
}

std::string const &ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > getGradeToExecute()) {
        std::cout << executor.getName() << " couldn't execute " << getName()
                  << " because the grade is too low." << std::endl;
        throw GradeTooLowException();
    }

    if (!getSigned()) {
        std::cout << getName() << " is not signed, can't execute." << std::endl;
        throw GradeTooLowException();
    }

    std::string filename = getTarget() + "_shrubbery";
    std::ofstream outputFile(filename.c_str());

    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create the output file." << std::endl;
        throw GradeTooLowException();
    }

    outputFile << "       _-_" << std::endl;
    outputFile << "    /~~   ~~\\" << std::endl;
    outputFile << " /~~         ~~\\" << std::endl;
    outputFile << "{               }" << std::endl;
    outputFile << " \\  _-     -_  /" << std::endl;
    outputFile << "   ~  \\ //  ~" << std::endl;
    outputFile << "_- -   | | _- _" << std::endl;
    outputFile << "  _ -  | |   -_" << std::endl;
    outputFile << "      // \\\\" << std::endl;

    outputFile.close();
    std::cout << "Shrubbery has been successfully created in " << filename << std::endl;
}
