/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:52:09 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/21 17:03:40 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	private:
		static std::string	_type;

    protected:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_maxhitpoints;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
		bool			_isdead;

		// messages
		void print_message_died() const;
		void print_message_dead() const;
		void print_message_repair() const;
		void print_message_no_energy() const;
		void print_message_damage(const int points) const;		
		void print_message_attack(const std::string& target) const;
		void print_message_born_dead(const ClapTrap& other) const;
		void print_message_copied_dead(const ClapTrap& other) const;

    public:
		// canonicals
        ClapTrap();									// default ctor
        ClapTrap(const ClapTrap& other);			// default copy ctor
        ClapTrap &operator=(const ClapTrap &other);	// default assignt ctor
        ~ClapTrap();								// destructor

		ClapTrap(std::string name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif