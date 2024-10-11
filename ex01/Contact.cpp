/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 05:06:05 by facetint          #+#    #+#             */
/*   Updated: 2024/10/11 05:06:05 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(std::string name)
{
	this->_name = name;
}
void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
}
void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}
void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}
std::string	Contact::getFirstName(void) const
{
	return (_name);
}
std::string	Contact::getLastName(void) const
{
	return (_lastName);
}
std::string	Contact::getNickName(void) const
{
	return (_nickName);
}
std::string	Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}
std::string Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}
