#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie *horde = zombieHorde(5, "blob");
	(void)horde;


	free(horde);


	// randomChump("Ben");
	// Zombie *madonna = newZombie("madonna");
	// madonna->announce();
	// randomChump("suzy");
	// Zombie songa("songa");
	// delete(madonna);




}



Zombie* zombieHorde(int N, std::string name)
{
	Zombie **horde = (Zombie **)malloc(N * sizeof(Zombie *));

	for(int i = 0; i < N; i++) {
		*horde[i].set_name(name);
	}


	return (horde);
}