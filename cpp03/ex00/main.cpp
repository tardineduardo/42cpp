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


int main(void)
{
	std::cout << "\n1 ---------------------------------------------\n\n";
	{


		ClapTrap marcos;
		ClapTrap pedro = marcos;
		ClapTrap joao("Joao");
		pedro = joao;
		pedro.beRepaired(15);


	}
	std::cout << "\n2 ---------------------------------------------\n\n";
	{
		ClapTrap eduardo("Eduardo");
		eduardo.attack("Ze");
		eduardo.attack("Ze");
		eduardo.attack("Ze");
		eduardo.attack("Ze");
		eduardo.attack("Ze");
		eduardo.attack("Ze");
		eduardo.attack("Ze");
		eduardo.attack("Ze");
		eduardo.attack("Ze");
		eduardo.attack("Ze");
		eduardo.attack("Ze");
	}
	std::cout << "\n3 ---------------------------------------------\n\n";
	{
		ClapTrap felipe("Felipe");
		felipe.takeDamage(5);
		felipe.beRepaired(2);
		felipe.takeDamage(1);
		felipe.takeDamage(2);
		felipe.takeDamage(3);		
		felipe.takeDamage(100);
		felipe.takeDamage(1);
		felipe.attack("Joao");
	}
	std::cout << "\n ----------------------------------------------\n\n";
}
