/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:35:15 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:35:17 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// canonic methods -------------------------------------------------------------

WrongAnimal::WrongAnimal(void) {
    std::cout << "wronganimal default constructor called" << std::endl;
    _type = "generic Wronganimal";
    return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << "wronganimal copy constructor called" << std::endl;
    _type = other._type;
    return ;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "wronganimal assignment operator called" << std::endl;
    _type = other._type;
    return (*this);
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "wronganimal destructor called" << std::endl;
    return ;
}

//------------------------------------------------------------------------------

const std::string& WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "generic wronganimal makes no sound" << std::endl;
	return ;	
}
