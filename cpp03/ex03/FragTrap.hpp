/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:48:04 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 12:23:00 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

# ifndef FT_HITPOINTS
#  define FT_HITPOINTS 100
# endif

# ifndef FT_MAXHITPOINTS
#  define FT_MAXHITPOINTS 100
# endif

# ifndef FT_ENERGYPOINTS
#  define FT_ENERGYPOINTS 100
# endif

# ifndef FT_ATTACKDAMAGE
#  define FT_ATTACKDAMAGE 30
# endif

# define RED        "\001\033[31m\002"
# define BLU        "\001\033[34m\002"
# define RESET		"\001\033[0m\002"

class FragTrap : virtual public ClapTrap
{
	protected:
		std::string	_name;

		// messages
		void print_message_high_five() const;

    public:
		// canonicals
        FragTrap();									// default ctor
        FragTrap(const FragTrap& other);			// default copy ctor
        FragTrap &operator=(const FragTrap &other);	// default assignt ctor
        ~FragTrap();								// destructor

		FragTrap(const std::string& name);
		void highFivesGuys(void);
};

#endif
