#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA {
	private:
		Weapon		arma_;
		std::string	name_;

	public:
		HumanA(std::string name, Weapon arma);
		void	attack();

};

#endif