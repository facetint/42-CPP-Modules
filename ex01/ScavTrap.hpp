#ifndef SCARVTRAP_HPP
# define SCARVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
private:
    ScavTrap();

public:
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();
    ScavTrap& operator=(const ScavTrap& other);
    void attack(const std::string& target);
    void guardGate();
};

#endif