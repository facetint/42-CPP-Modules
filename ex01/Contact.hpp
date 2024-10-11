/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 05:06:02 by facetint          #+#    #+#             */
/*   Updated: 2024/10/11 05:19:47 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

# define RED_COLOR "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN_COLOR "\x1b[32;01m"
# define BLUE_COLOR "\x1b[34;01m"
# define PURPLE_COLOR "\x1b[38;2;178;58;238;01m"
# define DARK_BLUE "\x1b[38;2;0;0;139;01m"

class Contact
{ 
  private:
	std::string _name;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;

  public:
	void setFirstName(std::string name);
	void setLastName(std::string lastName);
	void setNickName(std::string nickName);
	void setPhoneNumber(std::string phoneNumber);
	void setDarkestSecret(std::string darkestSecret);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickName(void) const;
	std::string getPhoneNumber(void) const;
	std::string getDarkestSecret(void) const;
};

#endif
