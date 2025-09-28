/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:48:04 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/22 21:37:53 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

# define RED        "\001\033[31m\002"
# define GRN        "\001\033[32m\002"
# define RESET		"\001\033[0m\002"

class ScavTrap : virtual public ClapTrap
{
	protected:
		bool	_guard_mode;

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
