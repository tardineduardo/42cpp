/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:00:30 by eduribei          #+#    #+#             */
/*   Updated: 2026/05/24 20:33:41 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Array.hpp"

// canonic methods -------------------------------------------------------------

Arrayint::Arrayint()
{
	_array = NULL;
	_size = 0;
}

Arrayint::~Arrayint()
{
	delete[] _array;
}

Arrayint::Arrayint(const Arrayint& other)
{
	(void)other;
//Construction by copy and assignment operator. In both cases, modifying either
//the original array or its copy after copying musn’t affect the other array.
}


Arrayint& Arrayint::operator=(const Arrayint& other)
{
	(void)other;
	return *this;
//Construction by copy and assignment operator. In both cases, modifying either
//the original array or its copy after copying musn’t affect the other array.
}


// other methods ---------------------------------------------------------------

Arrayint::Arrayint(const unsigned int& n)
{
	_array = new int[n];
	_size = n; 
}


int Arrayint::index(const int& i)
{
	return _array[i];
}

int Arrayint::size()
{
	return _size;
}