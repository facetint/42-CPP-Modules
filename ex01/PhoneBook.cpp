#include "PhoneBook.hpp"

void    PhoneBook::addFirstName(void)
{
    std::string  input;

    std::cout << "First Name: " ;
    getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "First Name is empty" << std::endl;
        return true;
    }
    for(int i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]))
        {
            std::cout << "First Name is not valid" << std::endl;
            return true;
        }
    }
    return false;
}
static  bool addLastName(std::string  input)
{
    std::cout << "Last Name: " ;
    getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "Last Name is empty" << std::endl;
        return true;
    }
    for(int i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]))
        {
            std::cout << "Last Name is not valid" << std::endl;
            return true;
        }
    }
    return false;
}
void    PhoneBook::add(void)
{
    std::string  input;

        addFirstName(input);
        addLastName(input);
        addNickname(input);
        addPhoneNumber(input);
        addDarkSecret(input);
    
        std::cout << "PhoneBook is full" << std::endl;
}

void    PhoneBook::addhj()
{
    std::string  input;
      
    {
        std::cout << "Name: " ;
        getline(std::cin, input);
        if (controlName(input))
            contacts->setname(input);
    }
    {
        std::cout << "Last Name: " ;
        getline(std::cin, input);
    }
    {
        std::cout << "Nick Name: " ;
        getline(std::cin, input);
    }
    {
        std::cout << "Phone Number :" ;
        getline(std::cin, input);
    }
    {
        std::cout << "Darkest Secret : " ;
        getline(std::cin, input);
    }
    std::cout << "User added to PhoneBook" << std::endl;
}

void    PhoneBook::printUserInformation(int i)
{
    std::cout << "Name: " << contacts[i].getname() << std::endl;
    std::cout << "Last Name: " << contacts[i].getlastName() << std::endl;
    std::cout << "Nick Name: " << contacts[i].getnickName() << std::endl;
    std::cout << "Phone Number: " << contacts[i].getphoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[i].getphoneNumber() << std::endl;
}
void    PhoneBook::searchContact()
{
    std::string searchInput;
    std::cout << "Enter name to search: ";
    getline(std::cin, searchInput);

}

