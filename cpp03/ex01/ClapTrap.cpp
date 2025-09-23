/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:52:02 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/22 21:42:23 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << YEL "[CT base default constructor called]\n" RESET;
	_type = "ClapTrap";
	_name = "Unnamed";
	_hitpoints = 10;
	_maxhitpoints = 10;
	_energy_points = 10;
	_attack_damage = 0;
	_isdead = false;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << YEL "[CT base name constructor called]\n" RESET;
	_type = "ClapTrap";
	_name = name;
	_hitpoints = 10;
	_maxhitpoints = 10;
	_energy_points = 10;
	_attack_damage = 0;
	_isdead = false;
}

ClapTrap::~ClapTrap() {
	std::cout << YEL "[CT base destructor called]\n" RESET;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << YEL "[CT base default copy constructor called]\n" RESET;
	_name = other._name;
	_hitpoints = other._hitpoints;
	_maxhitpoints = other._maxhitpoints;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	_isdead = other._isdead;
	if (_isdead)
		print_message_born_dead(other);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << YEL "[CT base default assigment operator called]\n" RESET;
	_name = other._name;
	_hitpoints = other._hitpoints;
	_maxhitpoints = other._maxhitpoints;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	_isdead = other._isdead;
	if (_isdead)
		print_message_copied_dead(other);
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_isdead)
	{
		print_message_dead();
		return;
	}

	if (_energy_points == 0)
	{
		print_message_no_energy();
		return;
	}	
	_energy_points--;
	print_message_attack(target);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_isdead)
	{
		print_message_dead();
		return;
	}
	
	print_message_damage(amount);
	
	if (amount >= _hitpoints)
	{
		_hitpoints = 0;
		_isdead = true;
		print_message_died();
		return;
	}
	else
		_hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_isdead)
	{
		print_message_dead();
		return;
	}
	
	if (_energy_points == 0)
	{
		print_message_no_energy();
		return;
	}
	
	_hitpoints += amount;
	_energy_points--;
	
	if (_hitpoints > _maxhitpoints)
		_hitpoints = _maxhitpoints;
	print_message_repair();
}

/* ------------------------------ messages ---------------------------------- */

void ClapTrap::print_message_dead() const {
						std::cout << _type
								  << " "
								  << _name
								  << " is dead. 💀\n";
}
void ClapTrap::print_message_died() const {
						std::cout << _type
								  << " "
								  << _name
			  					  << " died\n";
}
void ClapTrap::print_message_no_energy() const {
						std::cout << _type
								  << " "
								  << _name
								  << " has no energy points left. 🪫\n";
}
void ClapTrap::print_message_attack(const std::string& target) const {
						std::cout << _type
								  << " "
								  << _name
								  << " attacks "
								  << target
								  << ", causing "
								  << _attack_damage
								  << " points of damage.\n";
}
void ClapTrap::print_message_damage(const int points) const {
						std::cout << _type
								  << " "
								  << _name
								  << " took "
								  << points
								  << " hit points.\n";
}
void ClapTrap::print_message_repair() const {
						std::cout << _type
								  << " "
								  << _name
								  << " repaired itself. Hit points back to "
								  << _hitpoints
								  << ".\n";
}
void ClapTrap::print_message_born_dead(const ClapTrap& other) const {
						std::cout << _type
								  << " "
								  << _name
								  << " was born dead because "
								  << other._name
								  << " is dead.\n";
}
void ClapTrap::print_message_copied_dead(const ClapTrap& other) const {
						std::cout << _type
								  << " "
								  << _name
								  << " is dead because copied from dead "
								  << other._name
								  << ".\n";
}
