#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA {
	private:
		Weapon		*weapon_;
		std::string	name_;

	public:
		HumanA(std::string name, Weapon& w);
		void	attack();
		void	setWeapon(const Weapon& weapon);
};

#endif