/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:52:09 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/22 21:25:33 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

# define RED        "\001\033[31m\002"
# define YEL        "\001\033[33m\002"
# define RESET		"\001\033[0m\002"

class ClapTrap
{
    protected:
		std::string		_type;
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_maxhitpoints;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
		bool			_isdead;

		// messages
		void print_message_died() const;
		void print_message_dead() const;
		void print_message_max_hp() const;
		void print_message_no_energy() const;
		void print_message_damage(const unsigned int& points) const;		
		void print_message_repair(const unsigned int& amount) const;
		void print_message_attack(const std::string& target) const;
		void print_message_born_dead(const ClapTrap& other) const;
		void print_message_copied_dead(const ClapTrap& other) const;

    public:
		// canonicals
        ClapTrap();									// default ctor
        ClapTrap(const ClapTrap& other);			// default copy ctor
        ClapTrap &operator=(const ClapTrap &other);	// default assignt ctor
        ~ClapTrap();								// destructor

		ClapTrap(const std::string& name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif