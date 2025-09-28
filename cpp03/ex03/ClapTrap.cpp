/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:52:02 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/22 22:26:08 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_type = "ClapTrap";
	_name = "Unnamed";
	_hitpoints = 10;
	_maxhitpoints = 10;
	_energy_points = 10;
	_attack_damage = 0;
	_isdead = false;
	std::cout << YEL "[CT default constructor called for Unnamed]\n" RESET;
}

ClapTrap::ClapTrap(const std::string& name)
{
	_type = "ClapTrap";
	_name = name;
	_hitpoints = 10;
	_maxhitpoints = 10;
	_energy_points = 10;
	_attack_damage = 0;
	_isdead = false;
	std::cout << YEL "[CT name constructor called for " << _type << " " << name << "]\n" RESET;
}

ClapTrap::~ClapTrap() {
	std::cout << RED "🗑️  [CT destructor called for " << _type << " " << _name << "]\n" RESET;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << YEL "[CT default copy constructor called]\n" RESET;
	_type = "ClapTrap";
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
	if (this != &other) {
		std::cout << YEL "[CT default assignment operator called]\n" RESET;
		_type = "ClapTrap";
		_name = other._name;
		_hitpoints = other._hitpoints;
		_maxhitpoints = other._maxhitpoints;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
		_isdead = other._isdead;
		if (_isdead)
			print_message_copied_dead(other);
	}
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

	if (amount >= _hitpoints)
	{
		_hitpoints = 0;
		_isdead = true;
		print_message_damage(amount);
		print_message_died();
		return;
	}
	else
		_hitpoints -= amount;

	print_message_damage(amount);
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

	if (_hitpoints == _maxhitpoints)
	{
		print_message_max_hp();
		return;
	}

	unsigned int real_amount = amount;
	if (_hitpoints + amount > _maxhitpoints)
		real_amount = _maxhitpoints - _hitpoints;

	_hitpoints += real_amount;
	_energy_points--;
	
	print_message_repair(real_amount);
}

/* ------------------------------ messages ---------------------------------- */

void ClapTrap::print_message_dead() const {
						std::cout << "⚰️  "
								  << _type 
								  << " " 
								  << _name
								  << " is dead\n";
}
void ClapTrap::print_message_died() const {
						std::cout << "💀 "
								  << _type 
								  << " " 
								  << _name
			  					  << " died \n";
}
void ClapTrap::print_message_no_energy() const {
						std::cout << "🪫  "
								  << _type 
								  << " " 
								  << _name
								  << " has no energy points left\n";
}
void ClapTrap::print_message_max_hp() const {
						std::cout << "✅ "
								  << _type 
								  << " " 
								  << _name
								  << " is already at "
								  << _maxhitpoints
								  << " max hit points\n";
}

void ClapTrap::print_message_attack(const std::string& target) const {
						std::cout << "🔪 "
								  << _type 
								  << " " 
								  << _name
								  << " attacks "
								  << target
								  << ", causing "
								  << _attack_damage
								  << " points of damage, "
								  << _energy_points
								  << " energy left\n";
}
void ClapTrap::print_message_damage(const unsigned int& points) const {
						std::cout << "💥 "
								  << _type
								  << " "
								  << _name
								  << " took "
								  << points
								  << " hit point(s), "
								  << _hitpoints	
								  << " left\n";
}
void ClapTrap::print_message_repair(const unsigned int& amount) const {
						std::cout << "❤️‍🩹 "
								  << _type
								  << " "
								  << _name
								  << " repaired "
								  << amount
								  << " hit point(s), "
								  << _hitpoints
								  << " left\n";
}
void ClapTrap::print_message_born_dead(const ClapTrap& other) const {
						std::cout << "⚰️  "
								  << _type
								  << " "
								  << _name
								  << " was born dead because "
								  << other._name
								  << " is dead.\n";
}
void ClapTrap::print_message_copied_dead(const ClapTrap& other) const {
						std::cout << "⚰️  "
								  << _type
								  << " "
								  << _name
								  << " is dead because copied from dead "
								  << other._name
								  << ".\n";
}
