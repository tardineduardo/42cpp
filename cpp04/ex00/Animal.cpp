/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:29 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 18:49:11 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal(void)
{
    std::cout << "animal default constructor called" << std::endl;
    _type = "generic animal";
    return ;
}

// Copy constructor
Animal::Animal(const Animal &other)
{
    std::cout << "animal copy constructor called" << std::endl;
    _type = other._type;
    return ;
}

// Assignment operator overload
Animal &Animal::operator=(const Animal &other)
{
    std::cout << "animal assignment operator called" << std::endl;
    _type = other._type;
    return (*this);
}

// Destructor
Animal::~Animal(void)
{
    std::cout << "animal destructor called" << std::endl;
    return ;
}


const std::string& Animal::getType() const
{
	return _type;
}

void Animal::makeSound(void) const
{
    std::cout << "generic animal makes no sound" << std::endl;
	return ;	
}
