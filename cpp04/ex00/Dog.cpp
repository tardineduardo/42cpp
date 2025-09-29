/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:29 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 19:12:44 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Undefined"; 
}
Dog::Dog(const Dog& other) : Animal(other)
{
	_type = other._type;
}

Dog& Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Dog::~Dog() {}

void Dog::makeSound()
{
	std::cout << "Bark!\n";
}