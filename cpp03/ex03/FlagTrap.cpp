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
	_type			= "FlagTrap";
	_hitpoints		= 100;
	_maxhitpoints	= 100;
	_energy_points	= 100;
	_attack_damage	= 30;
	std::cout << BLU "[FT default constructor called for Unnamed]\n" RESET;
}

FlagTrap::FlagTrap(const std::string& name) : ClapTrap(name)
{
	_type			= "FlagTrap";
	_hitpoints		= 100;
	_maxhitpoints	= 100;
	_energy_points	= 100;
	_attack_damage	= 30;
	std::cout << BLU "[FT name constructor called for " << _type << " " << name << "]\n" RESET;
}

FlagTrap::~FlagTrap() {
	std::cout << RED "🗑️  [FT destructor called for " << _type << " " << _name << "]\n" RESET;
}

FlagTrap::FlagTrap(const FlagTrap& other) : ClapTrap(other)  
{
	std::cout << BLU "[FT default copy constructor called]\n" RESET;
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
	std::cout << BLU "[FT default assignment operator called]\n" RESET;
	if (this != &other) {
		ClapTrap::operator=(other);
		_type = "FlagTrap";
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
