/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:10:20 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 13:07:52 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Unnamed_clap_name")
{
	_name			= "Unnamed";
	_type			= "DmndTrap";
	_hitpoints		= FragTrap::_hitpoints;
	_maxhitpoints	= FragTrap::_maxhitpoints;;
	_energy_points	= ScavTrap::_energy_points;
	_attack_damage	= FragTrap::_attack_damage;
	_isdead			= false;
	std::cout << PNK "[DT default constructor called for " << _type << " " << _name << "]\n" RESET;

}

DiamondTrap::DiamondTrap(const std::string& name) 
	: ClapTrap(name + "_clap_name"),
	  ScavTrap(name),
	  FragTrap(name)
{
	_name			= name;
	ClapTrap::_name	= name + "_clap_name";
	_type			= "DmndTrap";
	_hitpoints		= FragTrap::_hitpoints;
	_maxhitpoints	= FragTrap::_maxhitpoints;;
	_energy_points	= ScavTrap::_energy_points;
	_attack_damage	= FragTrap::_attack_damage;
	_isdead			= false;
	std::cout << PNK "[DT name constructor called for " << _type << " " << name << "]\n" RESET;
}

DiamondTrap::~DiamondTrap() {
	std::cout << RED "🗑️  [DT destructor called for " << _type << " " << _name << "]\n" RESET;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other),
	  ScavTrap(other),
	  FragTrap(other)
{
	std::cout << PNK "[DT default copy constructor called]\n" RESET;
	_type			= "DmndTrap";
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

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << PNK "[DT default assignment operator called]\n" RESET;
	if (this != &other) {
        ScavTrap::operator=(other);
		FragTrap::operator=(other);
        _type = other._type;
		_name = other._name;
        if (_isdead)
            print_message_copied_dead(other);
    }
    return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Who am I?\n";
	std::cout << "Clap name: " << ClapTrap::_name << '\n';
	std::cout << "Diamond name: " << _name << '\n';
}
