/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:01:37 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/20 12:36:40 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	static int count = 1;
	std::ostringstream name;
	name << "generic" << std::setfill('0') << std::setw(3) << count++;
	name_ = name.str();
}

Zombie::Zombie(const std::string& name)
{
	name_ = name;
}

Zombie::~Zombie()
{
	std::cout << RED "❌ destroying " << Zombie::name_ << RESET << std::endl;
}

void Zombie::announce(void)
{
	std::cout << "🧟 " << Zombie::name_ << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::name() const
{	
	return (name_);
}
