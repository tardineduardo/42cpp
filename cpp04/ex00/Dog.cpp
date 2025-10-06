/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:29 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:26:57 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "messages.hpp"

// canonic methods -------------------------------------------------------------

Dog::Dog() {
	m_dogctor();
	_type = "dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
	m_dogcopy();
	_type = other._type;
}

Dog &Dog::operator=(const Dog &other) {
	m_dogassg();
	_type = other._type;
	return (*this);
}

Dog::~Dog(void) {
	m_dogdtor();
}

//------------------------------------------------------------------------------

void Dog::makeSound() const {
	std::cout << GRN "🐶💬 woof!\n" RST;
}
