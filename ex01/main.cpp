#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook input;
	std::string str;

	while (1)
	{
		std::cout << "Enter A Values -> ADD, SEARCH, EXIT" << std::endl;
        str = get_input();
		if (str == "EXIT")
			break;
		else if (str == "ADD")
			input.addContact();
		else if (str == "SEARCH")
			input.searchContact();
		else
			std::cout << "Invalid command" << std::endl;

	}
    return 0;
}
