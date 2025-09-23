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

/* ===== Standard foreground (30–37) ===== */
# define BLK        "\001\033[30m\002"
# define RED        "\001\033[31m\002"
# define GRN        "\001\033[32m\002"
# define YEL        "\001\033[33m\002"
# define BLU        "\001\033[34m\002"
# define MAG        "\001\033[35m\002"
# define CYN        "\001\033[36m\002"
# define WHT        "\001\033[37m\002"

/* ===== Bright foreground (90–97) ===== */
# define BBLK       "\001\033[90m\002"
# define BRED       "\001\033[91m\002"
# define BGRN       "\001\033[92m\002"
# define BYEL       "\001\033[93m\002"
# define BBLU       "\001\033[94m\002"
# define BMAG       "\001\033[95m\002"
# define BCYN       "\001\033[96m\002"
# define BWHT       "\001\033[97m\002"

# define RESET	"\001\033[0m\002"


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