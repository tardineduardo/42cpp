/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:04:14 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/21 17:07:14 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "[derived default constructor called]\n";
	_hitpoints = 100;
	_maxhitpoints = 100;
	_attack_damage = 20;
	_isdead = false;
}