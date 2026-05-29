/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:00:30 by eduribei          #+#    #+#             */
/*   Updated: 2026/05/29 19:00:51 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Array.hpp"


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
	_array = new int[other._size];
	_size = other._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}


Arrayint& Arrayint::operator=(const Arrayint& other)
{
	if (this != &other)
	{
		delete[] _array;
		_array = new int[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
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

int& Arrayint::operator[](unsigned int index)
{
	if (_size == 0)
		throw EmptyArrayException();
	if (index >= _size)
		throw OutOfBoundsException();		 
	return _array[index];
}

const int& Arrayint::operator[](unsigned int index) const
{
	if (_size == 0)
		throw EmptyArrayException();
	if (index >= _size)
		throw OutOfBoundsException();		 
	return _array[index];
}

int Arrayint::operator()(int index)
{
	if (_size == 0)
		throw EmptyArrayException();
	if (index < 0)
		index = _size + index;
	if (index >= static_cast<int>(_size) || index < 0)
		throw OutOfBoundsException();
	return _array[index];
}


int Arrayint::index(const unsigned int& i)
{
	return _array[i];
}

int Arrayint::index(const int& i)
{
	return _array[i];
}


unsigned int Arrayint::size()
{
	return _size;
}