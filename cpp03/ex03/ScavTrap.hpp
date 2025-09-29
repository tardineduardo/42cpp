/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:48:04 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 12:22:50 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

# ifndef ST_HITPOINTS
#  define ST_HITPOINTS 100
# endif

# ifndef ST_MAXHITPOINTS
#  define ST_MAXHITPOINTS 100
# endif

# ifndef ST_ENERGYPOINTS
#  define ST_ENERGYPOINTS 50
# endif

# ifndef ST_ATTACKDAMAGE
#  define ST_ATTACKDAMAGE 20
# endif

# define RED	"\001\033[31m\002"
# define GRN	"\001\033[32m\002"
# define RESET	"\001\033[0m\002"

class ScavTrap : virtual public ClapTrap
{
	protected:
		bool		_guard_mode;
		std::string	_name;

		// messages
		void print_message_guard_mode_on() const;
		void print_message_guard_mode_off() const;


    public:
		// canonicals
        ScavTrap();									// default ctor
        ScavTrap(const ScavTrap& other);			// default copy ctor
        ScavTrap &operator=(const ScavTrap &other);	// default assignt ctor
        ~ScavTrap();								// destructor

		ScavTrap(const std::string& name);
		void guardGate();
};

#endif
