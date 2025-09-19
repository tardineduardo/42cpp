#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_name = "Unnamed";
	_hitpoints = 10;
	_maxhitpoints = 10;
	_energy_points = 10;
	_attack_damage = 0;
	_isdead = false;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitpoints = 10;
	_maxhitpoints = 10;
	_energy_points = 10;
	_attack_damage = 0;
	_isdead = false;
}

ClapTrap::~ClapTrap() {}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	(void)other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	(void)other;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_isdead)
	{
		mDead();
		return;
	}
	
	mAttack(target);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_isdead)
	{
		mDead();
		return;
	}
	
	mDamage(amount);
	
	if (amount >= _hitpoints)
	{
		_hitpoints = 0;
		_isdead = true;
		mDied();
		return;
	}
	else
		_hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_isdead)
	{
		mDead();
		return;
	}
	
	if (_energy_points == 0)
	{
		mNoEnergy();
		return;
	}
	
	_hitpoints += amount;
	_energy_points--;
	
	if (_hitpoints > _maxhitpoints)
		_hitpoints = _maxhitpoints;
	mRepair();
}

/* ------------------------------ messages ---------------------------------- */

void ClapTrap::mDead() {
						std::cout << "ClapTrap "
			  					  << _name
								  << " is dead\n";
}
void ClapTrap::mDied() {
						std::cout << "ClapTrap "
			  					  << _name
			  					  << " died\n";
}
void ClapTrap::mNoEnergy() {
						std::cout << "ClapTrap "
								  << _name
								  << " has no energy to repair itself.\n";
}
void ClapTrap::mAttack(const std::string& target) {
						std::cout << "ClapTrap "
								  << _name
								  << " attacks "
								  << target
								  << ", causing "
								  << _attack_damage
								  << " points of damage.\n";
}
void ClapTrap::mDamage(const int points) {
						std::cout << "ClapTrap "
								  << _name
								  << " took "
								  << points
								  << " hit points.\n";
}
void ClapTrap::mRepair() {
						std::cout << "ClapTrap "
								  << _name
								  << " repaired itself. Hit points back to "
								  << _hitpoints
								  << ".\n";
}
