/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:48:04 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/22 21:25:51 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FlagTrap_HPP
# define FlagTrap_HPP
# include <iostream>
# include "ClapTrap.hpp"

# define RED        "\001\033[31m\002"
# define BLU        "\001\033[34m\002"
# define RESET		"\001\033[0m\002"

class FlagTrap : public ClapTrap
{
	protected:
		// messages
		void print_message_high_five() const;

    public:
		// canonicals
        FlagTrap();									// default ctor
        FlagTrap(const FlagTrap& other);			// default copy ctor
        FlagTrap &operator=(const FlagTrap &other);	// default assignt ctor
        ~FlagTrap();								// destructor

		FlagTrap(const std::string& name);
		void highFivesGuys(void);
};

#endif
