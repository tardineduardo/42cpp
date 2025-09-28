/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:10:25 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 11:49:06 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# define RED	"\001\033[31m\002"
# define PNK	"\001\033[35m\002"
# define RESET	"\001\033[0m\002"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string		_name;
		std::string		_type;	
		unsigned int	_hitpoints;
		unsigned int	_maxhitpoints;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
		bool			_isdead;

	public:
		//canonicals
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap &other);

		//others
		DiamondTrap(const std::string& name);
		void whoAmI();
};

#endif