#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
		name_(name),
		weapon_(NULL)
{}

void	HumanB::attack()
{
	std::cout << this->name_
	<< " attacks with their " 
	<< this->weapon_->getType()
	<<std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon_ = &weapon;
}
