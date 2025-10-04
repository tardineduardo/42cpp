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

// Default constructor
Dog::Dog()
{
    std::cout << "dog default constructor called" << std::endl;
	_type = "dog"; 
    return ;
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "dog copy constructor called" << std::endl;
	_type = other._type;
    return ;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "dog assignment operator called" << std::endl;
	_type = other._type;
    return (*this);
}

// Destructor
Dog::~Dog(void)
{
    std::cout << "dog Destructor called" << std::endl;
    return ;
}

//------------------------------------------------------------------------------

void Dog::makeSound() const
{
	std::cout << "woof!\n";
}
