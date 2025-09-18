#include "ClapTrap.hpp"

# include <string>

int main(void)
{
	ClapTrap eduardo("Eduardo");

	eduardo.attack("Joao");
	eduardo.takeDamage(5);
	eduardo.beRepaired(2);
	eduardo.takeDamage(1);
	eduardo.takeDamage(1);
	eduardo.takeDamage(5);		
	eduardo.takeDamage(1);
	eduardo.takeDamage(1);
	eduardo.attack("Joao");

}
