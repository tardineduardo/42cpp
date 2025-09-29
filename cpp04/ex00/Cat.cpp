/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:29 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 19:15:05 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Undefined"; 
}
Cat::Cat(const Cat& other) : Animal(other)
{
	_type = other._type;
}

Cat& Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Cat::~Cat() {}

void Cat::makeSound()
{
	std::cout << "Meow!\n";
}

const std::string& getType

