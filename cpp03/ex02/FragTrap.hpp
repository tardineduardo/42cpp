/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:48:04 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/21 22:18:18 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	protected:
		bool	_guard_mode;

		// messages
		void print_message_high_five() const;

    public:
		// canonicals
        FragTrap();									// default ctor
        FragTrap(const FragTrap& other);			// default copy ctor
        FragTrap &operator=(const FragTrap &other);	// default assignt ctor
        ~FragTrap();								// destructor

		FragTrap(std::string name);
		void highFivesGuys(void);
};

#endif
