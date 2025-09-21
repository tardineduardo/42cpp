/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:48:04 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/21 17:04:20 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		static std::string	_type;

    public:
		// canonicals
        ScavTrap();									// default ctor
        ScavTrap(const ScavTrap& other);			// default copy ctor
        ScavTrap &operator=(const ScavTrap &other);	// default assignt ctor
        ~ScavTrap();								// destructor


};

#endif

