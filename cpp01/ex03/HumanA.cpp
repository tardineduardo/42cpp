/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:30:11 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/20 12:34:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name_(name),
												   weapon_(weapon)
{}

void	HumanA::attack()
{
	std::cout << this->name_
	<< " attacks with their " 
	<< this->weapon_.getType()
	<< std::endl;
}
