#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
    private:
	std::string		_name;
	unsigned int	_hit_points;
	unsigned int	_hit_points_max;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;
	bool			_isdead;

    public:
        ClapTrap();
		ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif