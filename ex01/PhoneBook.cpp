#include "PhoneBook.hpp"
#include <cstdlib>
#include <iomanip>

static bool checkName(std::string input)
{
	if (input.empty())
	{
		std::cout << GREEN_COLOR << "First Name is empty" << RESET << std::endl;
		return (true);
	}
	for (size_t i = 0; i < input.length(); ++i)
	{
		if (isdigit(input[i]))
		{
			std::cout << BLUE_COLOR << "Name must be only letters" << RESET << std::endl;
			return (true);
		}
	}
	return (false);
}

static bool checkNickName(std::string input)
{
	if (input.empty())
	{
		std::cout << GREEN_COLOR << "Nick Name is empty" << RESET << std::endl;
		return (true);
	}
	return (false);
}
static bool checkDarkestSecret(std::string input)
{
	if (input.empty())
	{
		std::cout << GREEN_COLOR << "Darkest Secret is empty" << RESET << std::endl;
		return (true);
	}
	return (false);
}
static bool checkPhoneNumber(std::string input)
{
	if (input.empty())
	{
		std::cout << GREEN_COLOR << "Phone Number is empty" << RESET << std::endl;
		return (true);
	}
	if (input.length() != 10)
	{
		std::cout << BLUE_COLOR << "Phone number must be 10 digits" << RESET << std::endl;
		return (true);
	}
	for (size_t i = 0; i < input.length(); ++i)
	{
		if (isalpha(input[i]))
		{
			std::cout << BLUE_COLOR << "Phone number must be only numbers" << RESET << std::endl;
			return (true);
		}
	}
	return (false);
}

static bool checkSearchIndex(std::string input)
{
	if (input.empty())
	{
		std::cout << GREEN_COLOR "Index is empty" << RESET << std::endl;
		return (true);
	}
	for (int i = 0; input[i]; i++)
	{
		if (isalpha(input[i]))
		{
			std::cout << RED_COLOR << "False Index !" << RESET << std::endl;
			return (true);
		}
	}
	return (false);
}