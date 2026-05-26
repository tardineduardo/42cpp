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


const char* Arrayint::OutOfBoundsException::what() const throw() {
	return "index out of bounds";
}

const char* Arrayint::EmptyArrayException::what() const throw() {
	return "empty array.";
}


// now do for writing
int Arrayint::operator[](const int& index)
{
	if (_size == 0)
		throw EmptyArrayException();
	if (index >= _size || index < 0)
		throw OutOfBoundsException();		 
	return _array[index];
}

int Arrayint::operator[](int& index)
{
	if (_size == 0)
		throw EmptyArrayException();
	if (index >= _size || index < 0)
		throw OutOfBoundsException();		 
	return _array[index];
}



int Arrayint::operator()(const int& index)
{
	if (_size == 0)
		throw EmptyArrayException();
	else if (index == 0)
		return _array[0];
	else if (index >= _size - 1)
		return _array[index % (_size - 1)];
	else if (index < 0)
		return _array[-(index % (_size - 1))];
	return _array[index];
}


int Arrayint::index(const int& i)
{
	return _array[i];
}

int Arrayint::size()
{
	return _size;
}