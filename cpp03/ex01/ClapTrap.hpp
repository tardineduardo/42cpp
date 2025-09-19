#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
    private:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_maxhitpoints;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
		bool			_isdead;

		// messages
		void mDied();
		void mDead();
		void mRepair();
		void mNoEnergy();
		void mAttack(const std::string& target);
		void mDamage(const int points);		

    public:
		// canonicals
        ClapTrap();									// default ctor
        ClapTrap(const ClapTrap& other);			//
        ClapTrap &operator=(const ClapTrap &other);	//
        ~ClapTrap();

		ClapTrap(std::string name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif