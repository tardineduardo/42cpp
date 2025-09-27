/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:04:14 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/21 22:20:01 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FlagTrap::FlagTrap() : ClapTrap()
{
	std::cout << "[FT derived default constructor called]\n";
	_type = "FlagTrap";
	_hitpoints = 100;
	_maxhitpoints = 100;
	_attack_damage = 30;
	_guard_mode = false;	
}

FlagTrap::FlagTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[FT derived name constructor called]\n";
	_type = "FlagTrap";
	_name = name;
	_hitpoints = 100;
	_maxhitpoints = 100;
	_attack_damage = 30;
	_guard_mode = false;	
}

FlagTrap::~FlagTrap() {
	std::cout << "[FT derived destructor called]\n";
}

FlagTrap::FlagTrap(const FlagTrap& other) : ClapTrap(other)  
{
	std::cout << "[FT derived default copy constructor called]\n";
	_type 			= "FlagTrap";
	_name 			= other._name;
	_hitpoints 		= other._hitpoints;
	_maxhitpoints	= other._maxhitpoints;
	_energy_points	= other._energy_points;
	_attack_damage	= other._attack_damage;
	_isdead			= other._isdead;
	if (_isdead)
		print_message_born_dead(other);
}

FlagTrap& FlagTrap::operator=(const FlagTrap& other)
{
	if (this != &other) {
		std::cout << "[FT derived default assigment operator called]\n";
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

void FlagTrap::highFivesGuys(void) {
	print_message_high_five();
}

/* ------------------------------ messages ---------------------------------- */

void FlagTrap::print_message_high_five() const {
						std::cout << "FlagTrap " 
								  << _name
								  << " gives a high five.\n";
}

