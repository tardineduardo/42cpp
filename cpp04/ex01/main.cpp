/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:22 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 19:04:17 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		//std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete i, 
		delete j;
	}

	std::cout << "\n--------------------------------\n\n";

	{
		Cat felix;
		Cat tom;

		felix.store_idea(0, "play");
		felix.store_idea(1, "ball");
		felix.store_idea(2, "run");
		tom.store_idea(5, "sleep");
		felix.store_idea(10, "hide");								
		felix.store_idea(500, "play");

		felix.show_ideas();
		tom.show_ideas();		

		felix = tom;
		felix.show_ideas();

	}

	{
		int size = 4;
		Animal* animals[size];

		for (int i = 0; i < size; ++i)
		{
			if (i < size / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		for (int i = 0; i < size; ++i)
			animals[i]->makeSound();

		for (int i = 0; i < size; ++i)
			delete animals[i]; 
		}
}
