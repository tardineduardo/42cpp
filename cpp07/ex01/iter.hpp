/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:00:30 by eduribei          #+#    #+#             */
/*   Updated: 2026/05/23 17:32:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


// template <typename T1>
// void iter(T1& array, int len, void(*func)(T1))
// {
// 	for (int i = 0; i < len; i++)
// 	{
// 		func(array[i]);
// 	}
// }


void iter_int(int array[], const int len, void(*func)(int&))
{
	for (int i = 0; i < len; i++)
	{
		func(array[i]);
	}
}


void iter_str(std::string array[], const int len, void(*func)(std::string&))
{
	for (int i = 0; i < len; i++)
	{
		func(array[i]);
	}
}



// template <typename T1>
// void iter(const T1 *array, size_t len, void(*func)(T1))
// {.+
// 	for (int i = 0; i < len; i++)
// 	{
// 		func(array[i])
// 	}
// }



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

