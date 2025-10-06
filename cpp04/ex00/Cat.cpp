/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:25 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:24:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "messages.hpp"

// canonic methods -------------------------------------------------------------

Cat::Cat() {
	m_catctor();
	_type = "cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
	m_catcopy();
	_type = other._type;
}

Cat &Cat::operator=(const Cat &other) {
	m_catassg();
	_type = other._type;
	return (*this);
}

Cat::~Cat(void) {
	m_catdtor();
}

//------------------------------------------------------------------------------

void Cat::makeSound() const {
	std::cout << GRN "🐱💬 meow!\n" RST;
}

