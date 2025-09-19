#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
		name_(name),
		weapon_(NULL)
{}

void	HumanB::attack()
{
	if (weapon_) {
		std::cout << this->name_
		<< " attacks with their " 
		<< this->weapon_->getType()
		<<std::endl;
	}
	else {
		std::cout << this->name_
		<< " has no weapon!"
		<<std::endl;
	}
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon_ = &weapon;
}
