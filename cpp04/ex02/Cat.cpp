/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:25 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:39:23 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "messages.hpp"

// canonical methods -----------------------------------------------------------

Cat::Cat() {
	m_catctor();
	_type = "cat";
	_brain = new(Brain);
}

Cat::Cat(const Cat &other) : Animal(other) {
	m_catcopy();
	_brain = new(Brain);
	_brain->deepcopy(*_brain, *other._brain);
	_type = other._type;
}

Cat &Cat::operator=(const Cat &other) {
	m_catassg();
	delete(_brain);
	_brain = new(Brain);
	_brain->deepcopy(*_brain, *other._brain);
	_type = other._type;
	return (*this);
}

Cat::~Cat(void) {
	m_catdtor();
	delete(_brain);
}

//------------------------------------------------------------------------------

void Cat::makeSound() const {
	std::cout << GRN "🐱💬 meow!\n" RST;
}

void	Cat::store_idea(const int& index, const std::string& idea) {
    // Cat validates index 
	if(index >= this->_brain->_k_nb_ideas)
		std::cout << GRN "⚠️  cat: invalid idea index" RST << std::endl;
	else
		this->_brain->store_idea(index, idea);
}

void	Cat::show_ideas() {
	std::cout << GRN "🐱 showing cat's ideas:" RST << std::endl;
	_brain->show_ideas();
}
