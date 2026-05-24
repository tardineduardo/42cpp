/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:00:30 by eduribei          #+#    #+#             */
/*   Updated: 2026/05/24 13:38:22 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <cstdlib>

// =============================================================================
//                                 INT
// =============================================================================

void set_int(int& x)
{
	x = (rand()) % 10;
}

void inc_int(int& x)
{
	x++;
}

void put_int(const int& x)
{
	std::cout << x << ", ";
}

void iter_int(int array[], const int len, void(*func)(int&))
{
	for (int i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

void iter_int(const int array[], const int len, void(*func)(const int&))
{
	for (int i = 0; i < len; i++)
	{
		func(array[i]);
	}
}


// =============================================================================
//                              STRINGS
// =============================================================================

void set_fruit(std::string& string)
{
	std::string fruits[30] = {
			"apple", "apricot", "avocado", "banana", "blackberry",
			"blueberry", "cherry", "coconut", "cranberry", "date",
			"dragonfruit", "fig", "grape", "grapefruit", "guava",
			"kiwi", "lemon", "lime", "lychee", "mango",
			"melon", "nectarine", "orange", "papaya", "peach",
			"pear", "pineapple", "plum", "pomegranate", "raspberry"
		};

	string = fruits[(rand()) %30];
}

void str_upper(std::string& str)
{
	int len = str.length();

	for(int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
}

void put_str(const std::string& str)
{
	std::cout << str << ", ";
}

void iter_str	(std::string array[], const int len, void(*func)(std::string&))
{
	for (int i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

void iter_str(const std::string array[], const int len, void(*func)(const std::string&))
{
	for (int i = 0; i < len; i++)
	{
		func(array[i]);
	}
}


// =============================================================================
//                              PRINT (OVERLOAD)
// =============================================================================

void print_array(const int int_array[], int len)
{
	for(int i = 0; i < len; i++)
		std::cout << int_array[i] << ", ";
	std::cout << '\n';
}

void print_array(const std::string str_array[], int len)
{
	for(int i = 0; i < len; i++)
		std::cout << str_array[i] << ", ";
	std::cout << '\n';
}


// =============================================================================
//                             TEST HELPERS
// =============================================================================

void divider(std::string message)
{
	static int count = 1;
	std::cout << "\n\n" << "----------------------------------------\n";
	std::cout << count << ". " << message << "\n\n";
	count++;
}

void linebreak()
{
	std::cout << "\n";
}
