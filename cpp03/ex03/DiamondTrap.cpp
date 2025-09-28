#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FlagTrap()
{
	_name = "Unnamed";
	_type = "DiamondTrap";
	_hitpoints = FlagTrap::_hitpoints;
	_maxhitpoints = FlagTrap::_maxhitpoints;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FlagTrap::_attack_damage;
	_isdead = false;
}


DiamondTrap::DiamondTrap(const std::string& name)
{
	(void)name;

}

DiamondTrap::~DiamondTrap()
{

}

// DiamondTrap::DiamondTrap(const DiamondTrap& other)
// {
// 	(void)other;

// }

DiamondTrap DiamondTrap::operator=(const DiamondTrap &other)
{
	(void)other;

	return *this;
}
