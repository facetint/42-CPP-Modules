#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
 private:
        Contact	contacts[8];
        int index;

    public:
        void	addContact();
        void	searchContact();
};

#endif
