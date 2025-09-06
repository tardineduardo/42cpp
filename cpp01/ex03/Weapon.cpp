#include <string>
#include "Weapon.hpp"

Weapon::Weapon()
{
	type_ = "";
}

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

const std::string&	Weapon::getType() const {
    return type_;
}

void	Weapon::setType(const std::string type) {
	this->type_ = type;
}
