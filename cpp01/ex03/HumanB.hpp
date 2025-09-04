#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
class HumanB {
	private:
		Weapon		weapon_;
		std::string	name_;

	public:
		HumanB();
		void	attack();

};

//While HumanA takes the Weapon in its constructor, HumanB does not.

#endif