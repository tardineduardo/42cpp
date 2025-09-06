#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& w)
{
	name_ = name; 
	name_ = ""; 
	w.setType("");
}

void	HumanA::attack()
{
	std::cout << this->name_ << " attacks with their " << this->weapon_->getType() << std::endl;
}

void	HumanA::setWeapon(const Weapon& weapon)
{
	weapon_->setType(weapon.getType());
}
