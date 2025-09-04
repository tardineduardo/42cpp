/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:01:41 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/03 21:01:48 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# define RED	"\001\033[31m\002"
# define RESET	"\001\033[0m\002"

# include <string>
# include <sstream>
# include <iostream>
# include <iomanip>

class Zombie {
	private:
		std::string	name_;
		static int	zombies_alive;

	public:
		Zombie();
		~Zombie();
		std::string name();
		Zombie(std::string name);
		void announce(void);
};

void	randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
