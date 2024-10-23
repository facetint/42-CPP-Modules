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
    ClasTrap(const ClasTrap& other);
    ~ClasTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    ClasTrap& operator=(const ClasTrap& other);
};

#endif

