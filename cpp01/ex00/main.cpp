#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	randomChump("Ben");
	Zombie *madonna = newZombie("madonna");
	madonna->announce();
	randomChump("suzy");
	Zombie songa("songa");
	delete(madonna);
}
