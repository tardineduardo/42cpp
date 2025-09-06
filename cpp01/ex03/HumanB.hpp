#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB {
	private:
		Weapon		weapon_;
		std::string	name_;

	public:
		HumanB(std::string name);
		void	attack();
		void	setWeapon(const Weapon& weapon);
};

#endif