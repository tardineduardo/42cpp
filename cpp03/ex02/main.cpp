/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:52:13 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/21 15:12:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

int main(void)
{
	std::cout << "\n1 ---------------------------------------------\n\n";
	{
		ClapTrap marcos;
		ClapTrap pedro = marcos;
		ClapTrap joao("Joao");
		pedro = joao;
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

	std::cout << "\n4 ---------------------------------------------\n\n";
	
	{	
		FlagTrap generic;
		FlagTrap s1("Alice");
		s1.highFivesGuys();
		s1.attack("Bob");
		s1.takeDamage(30);
		s1.beRepaired(10);
		s1.beRepaired(1000);
	}
	
	std::cout << "\n5 ---------------------------------------------\n\n";

	{
		FlagTrap s2("Madonna");
		FlagTrap s3(s2);
	}

	std::cout << "\n6 ---------------------------------------------\n\n";
	{
		FlagTrap s4("Britney");
		s4.takeDamage(99);
		s4.takeDamage(1);
		s4.takeDamage(1);
	

	std::cout << "\n7 ---------------------------------------------\n\n";


	FlagTrap s3;
	s3 = s4;
	s3.attack("Charlie");

	std::cout << "\n8 ---------------------------------------------\n\n";

	FlagTrap s5("Cher");
	for (int i = 0; i < 5; ++i) s5.attack("Bob");

	std::cout << "\n9 ---------------------------------------------\n\n";

	s5.takeDamage(1000);
	s5.attack("Bob");
	s5.beRepaired(5);
	}
}

