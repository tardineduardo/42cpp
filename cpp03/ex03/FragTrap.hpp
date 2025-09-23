/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:48:04 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/22 21:26:12 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP
# include <iostream>
# include "ClapTrap.hpp"

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
