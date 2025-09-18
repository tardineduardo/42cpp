#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	_name = "Unnamed";
	_hit_points = 10;
	_hit_points_max = 10;
	_energy_points = 10;
	_attack_damage = 0;
	_isdead = false;
}

ClapTrap::ClapTrap(std::string name) {
	_name = name;
	_hit_points = 10;
	_hit_points_max = 10;
	_energy_points = 10;
	_attack_damage = 0;
	_isdead = false;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	(void)other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	(void)other;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target) {
	if (_isdead) {
		std::cout	<< "ClapTrap " << _name
					<< " can't attack, it is dead.\n";
		return;
	}
	std::cout	<< "ClapTrap " << _name
				<< " attacks " << target
				<< ", causing " << _attack_damage
				<< " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_isdead) {
		std::cout	<< "ClapTrap " << _name
					<< " takes damage, but it is already dead.\n";
		return;
	}

	std::cout	<< "ClapTrap " << _name
				<< " took " << amount
				<< " hit points.\n";

	if (amount >= _hit_points) {
		_hit_points = 0;
		_isdead = true;
		std::cout << "ClapTrap " << _name << " died.\n";
		return;
	}
	else {
		_hit_points -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_isdead) {
		std::cout << "ClapTrap " << _name
					<< " can't be repaired, it is dead.\n";
		return;
	}

	if (_energy_points == 0) {
		std::cout << "ClapTrap " << _name
					<< " has no energy to repair itself.\n";
		return;
	}

	_hit_points += amount;
	_energy_points--;

	if (_hit_points > _hit_points_max) {
		_hit_points = _hit_points_max;
	}

	std::cout	<< "ClapTrap " << _name
				<< " repaired itself. Hit points back to "
				<< _hit_points << ".\n";
}
