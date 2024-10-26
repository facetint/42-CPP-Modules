#ifndef FRAGTRAP_HPP

# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    FragTrap();

public:
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    ~FragTrap();
    FragTrap& operator=(const FragTrap& other);
    void highFivesGuys(void);

};

#endif