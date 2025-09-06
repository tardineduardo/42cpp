#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	name_ = name;
	weapon_.setType("hands");
}

void	HumanB::attack()
{
	std::cout << this->name_ << " attacks with their " << this->weapon_.getType()
	<< std::endl;
}

void	HumanB::setWeapon(const Weapon& weapon)
{
	weapon_.setType(weapon.getType());
}
