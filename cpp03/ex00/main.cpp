/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:52:13 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/21 16:08:55 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

# include <string>

int main(void)
{
	ClapTrap eduardo("Eduardo");
	eduardo.attack("Joao");
	eduardo.takeDamage(5);
	eduardo.beRepaired(2);
	eduardo.takeDamage(1);
	eduardo.takeDamage(1);
	eduardo.takeDamage(5);		
	eduardo.takeDamage(1);
	eduardo.takeDamage(1);
	eduardo.attack("Joao");
	ClapTrap pedro(eduardo);
	ClapTrap andre = eduardo;
	ClapTrap ana("Ana");
	ana = eduardo;
}
