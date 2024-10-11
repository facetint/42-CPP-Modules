#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
  private:
	Contact contacts[8];
	int index;

  public:
	void addContact();
	void searchContact() const;
	void printUserInformation(int i) const;
	void printPhoneBook(int i) const;
};

std::string get_input();

#endif
