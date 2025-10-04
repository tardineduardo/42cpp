/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:29 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 18:49:11 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal(void)
{
    std::cout << "wronganimal default constructor called" << std::endl;
    _type = "generic Wronganimal";
    return ;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "wronganimal copy constructor called" << std::endl;
    _type = other._type;
    return ;
}

// Assignment operator overload
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "wronganimal assignment operator called" << std::endl;
    _type = other._type;
    return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal(void)
{
    std::cout << "wronganimal destructor called" << std::endl;
    return ;
}


const std::string& WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "generic wronganimal makes no sound" << std::endl;
	return ;	
}
