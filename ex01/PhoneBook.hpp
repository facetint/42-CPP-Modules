/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 05:05:52 by facetint          #+#    #+#             */
/*   Updated: 2024/10/11 05:05:53 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
