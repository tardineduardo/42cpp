/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:27:27 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/20 12:38:39 by eduribei         ###   ########.fr       */
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
# include <cstdlib>

class Zombie
{
	private:
		std::string		name_;

	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);
		std::string		name();
		void			set_name(const std::string& name);
		void			announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
