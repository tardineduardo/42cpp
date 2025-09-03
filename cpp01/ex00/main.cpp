#include <iostream>
#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int	main(void)
{
	randomChump("Ben");
	Zombie *madonna = newZombie("madonna");
	madonna->announce();
	randomChump("suzy");
	Zombie songa("songa");
	delete(madonna);
}
