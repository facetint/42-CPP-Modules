#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
    private:
    std::string     name;
    std::string     lastName;
    std::string     nickName;
    std::string     phoneNumber;
    std::string     darkestSecret;
   
    public:
    void            setname(std::string name);
    void            setlastName(std::string lastName);
    void            setnickName(std::string nickName);
    void            setphoneNumber(std::string phoneNumber);
    void            setdarkestSecret(std::string darkestSecret);
    std::string     getname();
    std::string     getlastName();
    std::string     getnickName();
    std::string     getphoneNumber();
    std::string     getdarkestSecret();
};

#endif