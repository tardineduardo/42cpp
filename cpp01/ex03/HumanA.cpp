#include "HumanA.hpp"


HumanA::HumanA()
{
	Weapon *w = new Weapon;
	name_ = ""; 
	w->setType("");
}

HumanA::HumanA(std::string name, Weapon weapon)
{
	name_ = name; 
	weapon_->setType(weapon.getType());
}

void	HumanA::attack()
{
	std::cout << this->name_ << " attacks with their " << this->weapon_.getType()
	<< std::endl;
}

void	HumanA::setWeapon(const Weapon& weapon)
{
	weapon_.setType(weapon.getType());
}
