/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:04:14 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 10:56:55 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_type			= "FragTrap";
	_hitpoints		= 100;
	_maxhitpoints	= 100;
	_energy_points	= 100;
	_attack_damage	= 30;
	std::cout << BLU "[FT default constructor called for Unnamed]\n" RESET;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_type			= "FragTrap";
	_hitpoints		= 100;
	_maxhitpoints	= 100;
	_energy_points	= 100;
	_attack_damage	= 30;
	std::cout << BLU "[FT name constructor called for " << _type << " " << name << "]\n" RESET;
}

FragTrap::~FragTrap() {
	std::cout << RED "🗑️  [FT destructor called for " << _type << " " << _name << "]\n" RESET;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)  
{
	std::cout << BLU "[FT default copy constructor called]\n" RESET;
	_type 			= "FragTrap";
	_name 			= other._name;
	_hitpoints 		= other._hitpoints;
	_maxhitpoints	= other._maxhitpoints;
	_energy_points	= other._energy_points;
	_attack_damage	= other._attack_damage;
	_isdead			= other._isdead;
	if (_isdead)
		print_message_born_dead(other);
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << BLU "[FT default assignment operator called]\n" RESET;
	if (this != &other) {
		ClapTrap::operator=(other);
		_type = "FragTrap";
		if (_isdead)
			print_message_copied_dead(other);
	}
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	print_message_high_five();
}

/* ------------------------------ messages ---------------------------------- */

void FragTrap::print_message_high_five() const {
						std::cout << "FragTrap " 
								  << _name
								  << " gives a high five.\n";
}
