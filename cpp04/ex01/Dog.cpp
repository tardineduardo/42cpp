/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:29 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:37:40 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "messages.hpp"

// canonic methods -------------------------------------------------------------

Dog::Dog() {
	m_dogctor();
	_type = "dog";
	_brain = new(Brain);
}

Dog::Dog(const Dog &other) : Animal(other) {
	m_dogcopy();
	_brain = new(Brain);
	_brain->deepcopy(*_brain, *other._brain);
	_type = other._type;
}

Dog &Dog::operator=(const Dog &other) {
	m_dogassg();
	delete(_brain);
	_brain = new(Brain);
	_brain->deepcopy(*_brain, *other._brain);
	_type = other._type;
	return (*this);
}

Dog::~Dog(void) {
	m_dogdtor();
	delete(_brain);
}

//------------------------------------------------------------------------------

void Dog::makeSound() const {
	std::cout << GRN "🐶💬 woof!\n" RST;
}

void	Dog::store_idea(const int& index, const std::string& idea) {
    // brain validates index 
	this->_brain->store_idea(index, idea);
}

void	Dog::show_ideas() {
	std::cout << GRN "🐶 showing dog's ideas:" RST << std::endl;
	_brain->show_ideas();
}
