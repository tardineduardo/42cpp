/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:25 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 19:04:53 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat()
{
    std::cout << "cat default constructor called" << std::endl;
	_type = "cat"; 
    return ;
}

// Copy constructor
Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "cat copy constructor called" << std::endl;
	_type = other._type;
    return ;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "cat assignment operator called" << std::endl;
	_type = other._type;
    return (*this);
}

// Destructor
Cat::~Cat(void)
{
    std::cout << "cat Destructor called" << std::endl;
    return ;
}

//------------------------------------------------------------------------------

void Cat::makeSound() const
{
	std::cout << "meow!\n";
}
