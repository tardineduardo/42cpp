/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:12:00 by eduribei          #+#    #+#             */
/*   Updated: 2026/05/23 17:26:17 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "iter.hpp"


void set_int(int& x)
{
	x = (rand()) % 10;
}

void increment(int& x)
{
	x++;
}





void get_fruit(std::string& string)
{
	std::string fruits[30] = {
			"apple", "apricot", "avocado", "banana", "blackberry",
			"blueberry", "cherry", "coconut", "cranberry", "date",
			"dragonfruit", "fig", "grape", "grapefruit", "guava",
			"kiwi", "lemon", "lime", "lychee", "mango",
			"melon", "nectarine", "orange", "papaya", "peach",
			"pear", "pineapple", "plum", "pomegranate", "raspberry"
		};

	string = fruits[(rand()) % 10];
}


// void string_upper(std::string& x)
// {
// 	for(lon)
// 	x++;
// }

void print(int int_array[], int len)
{
	for(int i = 0; i < len; i++)
		std::cout << int_array[i] << ", ";
	std::cout << '\n';
}

void print(const std::string str_array[], int len)
{
	for(int i = 0; i < len; i++)
		std::cout << str_array[i] << ", ";
	std::cout << '\n';
}



int main( void )
{

	void(*inc)(int&);
	void(*set)(int&);
	void(*fru)(std::string&);

	int						int_array[10];
	std::string				fruit_array[10];
	// const int			const_int_array[10] = {0,1,2,3,4,5,6,7,8,9};
	// const std::string	const_str_array[10];

	inc = &increment;
	set = &set_int;
	fru = &get_fruit;


	print(int_array, 10);
	iter_int(int_array, 10, set);
	print(int_array, 10);
	iter_int(int_array, 10, inc);
	print(int_array, 10);

	print(fruit_array, 10);
	iter_str(fruit_array, 10, fru);
	print(fruit_array, 10);


}

