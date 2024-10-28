#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamond("Diamondy");
	diamond.displayStats();
	diamond.takeDamage(40); 
	diamond.beRepaired(20); 
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();      
	diamond.displayStats();
	return (0);
}
