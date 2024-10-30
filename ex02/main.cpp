#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap clap("Clappy");
	clap.displayStats();
	clap.attack("enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.displayStats();
	ScavTrap scav("Scavvy");
	scav.displayStats();
	scav.attack("enemy");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();
	scav.displayStats();
	FragTrap frag("Fraggy");
	frag.displayStats();
	frag.attack("enemy");
	frag.takeDamage(50);
	frag.beRepaired(20);
	frag.highFivesGuys();
	frag.displayStats();
	return (0);
}
