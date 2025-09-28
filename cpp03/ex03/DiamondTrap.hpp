#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FlagTrap.hpp"

class DiamondTrap : public ScavTrap, public FlagTrap {
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
//		DiamondTrap(const DiamondTrap& other);
		DiamondTrap operator=(const DiamondTrap &other);

		//others
		DiamondTrap(const std::string& name);

};





#endif