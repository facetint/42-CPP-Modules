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
    unsigned int getHitPoint() const;
    unsigned int getEnergyPoint() const;
    unsigned int getAttackDamage() const;
    std::string getName() const;
    void setName(std::string name);
    void setHitPoint(unsigned int hitPoint);
    void setEnergyPoint(unsigned int energyPoint);
    void setAttackDamage(unsigned int attackDamage);
    
};

#endif

