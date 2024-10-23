#ifndef CLAPTRAP_HPP

# define CLAPTRAP_HPP

# include <iostream>

class ClasTrap{

private:
    std::string name;
    unsigned int hitPoint;
    unsigned int energyPoint;
    unsigned int attackDamage;
    ClasTrap();

public:
    ClasTrap(std::string name);
    void attack(const std::string& target);
    void attack(const std::string& target);
    void beRepaired(unsigned int amount);
};

#endif

