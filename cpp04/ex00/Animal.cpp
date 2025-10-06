/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:29 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:34:42 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "messages.hpp"

// canonic methods -------------------------------------------------------------

Animal::Animal(void) {
    m_animalctor();
    _type = "generic animal";
    return ;
}

Animal::Animal(const Animal &other) {
    m_animalcopy();
    _type = other._type;
    return ;
}

Animal &Animal::operator=(const Animal &other) {
    m_animalassg();
    _type = other._type;
    return (*this);
}

Animal::~Animal(void) {
    m_animaldtor();
    return ;
}

//------------------------------------------------------------------------------

const std::string& Animal::getType() const
{
	return _type;
}

void Animal::makeSound(void) const
{
    std::cout << "⚠️  generic animal makes no sound" << std::endl;
	return ;	
}
