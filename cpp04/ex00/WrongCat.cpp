/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:25 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 19:04:53 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "wrongcat default constructor called" << std::endl;
	_type = "wrongcat";
    return ;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "wrongcat copy constructor called" << std::endl;
	_type = other._type;
    return ;
}

// Assignment operator overload
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "wrongcat assignment operator called" << std::endl;
	_type = other._type;
    return (*this);
}

// Destructor
WrongCat::~WrongCat(void)
{
    std::cout << "wrongcat Destructor called" << std::endl;
    return ;
}

//------------------------------------------------------------------------------

void WrongCat::makeSound() const
{
	std::cout << "wrong meow!\n";
}
