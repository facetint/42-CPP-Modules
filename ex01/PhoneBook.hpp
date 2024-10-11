#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
 private:
        Contact	contacts[8];
        int index;

    public:
        void	add();
        void    PhoneBook::addFirstName(void);
        void	searchContact();
        void	printUserInformation(int i);
};


#endif 