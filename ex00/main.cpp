#include "Zombie.hpp"

int	main(void)
{
	Zombie	z;
	Zombie	*ptr;

	z.setName("Zombie1");
	z.announce();
	ptr = newZombie("Foo");
	ptr->announce();
	randomChump("Blades");
	delete	ptr;
	return (0);
}
