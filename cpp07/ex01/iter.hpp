/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:00:30 by eduribei          #+#    #+#             */
/*   Updated: 2026/05/24 17:33:22 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> 
void iter(T array[], const int len, void(*func)(T&))
{
	for (int i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

template <typename T> 
void iter(const T array[], const int len, void(*func)(const T&))
{
	for (int i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

#endif









// Implement a function template iter that takes 3 parameters and returns nothing.
// •The first parameter is the address of an array.
// •The second one is the length of the array, passed as a const value.
// •The third one is a function that will be called on every element of the array.
// Submit a main.cpp file that contains your tests. Provide enough code to generate a
// test executable.
// Your iter function template must work with any type of array. The third parameter
// can be an instantiated function template.
// The function passed as the third parameter may take its argument by const reference
// or non-const reference, depending on the context.
// Think carefully about how to support both const and non-const
// elements in your iter function.