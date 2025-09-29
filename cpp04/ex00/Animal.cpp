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

Animal::Animal()
{
	_type = "Undefined"; 
}
Animal::Animal(const Animal& other)
{
	_type = other._type;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Animal::~Animal() {}
