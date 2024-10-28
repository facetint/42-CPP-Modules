#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
  private:
	std::string _name;
	DiamondTrap();

  public:
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &other);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &other);
	void whoAmI();
	std::string getDiamondName() const;
	void setDiamondName(std::string name);
};
#endif
