/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:04:14 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/22 21:19:46 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_type = "ScavTrap";
	_hitpoints = 100;
	_maxhitpoints = 100;
	_energy_points = 50; 	
	_attack_damage = 20;
	_guard_mode = false;	
	std::cout << GRN "[ST default constructor called for " << _name << "]\n" RESET;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_type = "ScavTrap";
	_hitpoints = 100;
	_energy_points = 50; 	
	_maxhitpoints = 100;
	_attack_damage = 20;
	_guard_mode = false;	
	std::cout << GRN "[ST name constructor called for " << _type << " " << name << "]\n" RESET;
}

ScavTrap::~ScavTrap() {
	std::cout << RED "🗑️  [ST destructor called for " << _type << " " << _name << "]\n" RESET;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)  
{
	std::cout << GRN "[ST default copy constructor called]\n" RESET;
	_type			= "ScavTrap";
	_name			= other._name;
	_hitpoints		= other._hitpoints;
	_maxhitpoints	= other._maxhitpoints;
	_energy_points	= other._energy_points;
	_attack_damage	= other._attack_damage;
	_isdead			= other._isdead;
    _guard_mode		= other._guard_mode;
	if (_isdead)
		print_message_born_dead(other);
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << GRN "[ST default assignment operator called]\n" RESET;
	if (this != &other) {
		ClapTrap::operator=(other);
		_type = "ScavTrap";
	    _guard_mode = other._guard_mode;		
		if (_isdead)
			print_message_copied_dead(other);
	}
	return (*this);
}

void ScavTrap::guardGate() {
	if (_guard_mode) {
		_guard_mode = false;
		print_message_guard_mode_off(); }
	else {
		_guard_mode = true;
		print_message_guard_mode_on(); }
}

/* ------------------------------ messages ---------------------------------- */

void ScavTrap::print_message_guard_mode_on() const {
						std::cout << _name
								  << " is in gate keeper mode.\n";
}

void ScavTrap::print_message_guard_mode_off() const {
						std::cout << _name
								  << " is no longer in gate keeper mode.\n";
}
