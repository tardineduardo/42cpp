/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:12:00 by eduribei          #+#    #+#             */
/*   Updated: 2026/05/24 17:35:31 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "iter.hpp"
#include "tests.hpp"

#define SIZE 10

int main( void )
{
	srand(time(NULL));

	{
		int			int_array[SIZE];
		std::string	fruit_array[SIZE];

//------------------------------------------------------------------------------		
		divider("Not using function templates - primitive int");
		
		print_array(int_array, SIZE);
		iter_int(int_array, SIZE, set_int);
		print_array(int_array, SIZE);
		iter_int(int_array, SIZE, inc_int);
		print_array(int_array, SIZE);

//------------------------------------------------------------------------------		
		divider("Not using function templates - string object");
		
		print_array(fruit_array, SIZE);
		iter_str(fruit_array, SIZE, set_fruit);
		print_array(fruit_array, SIZE);
		iter_str(fruit_array, SIZE, str_upper);
		print_array(fruit_array, SIZE);
	}


	{
		int			int_array[SIZE];
		std::string	fruit_array[SIZE];

//------------------------------------------------------------------------------		
		divider("Using function templates - primitive int");

		print_array(int_array, SIZE);
		iter<int>(int_array, SIZE, set_int);
		print_array(int_array, SIZE);
		iter<int>(int_array, SIZE, inc_int);
		print_array(int_array, SIZE);

//------------------------------------------------------------------------------		
		divider("Using function templates - string object");

		print_array(fruit_array, SIZE);
		iter<std::string>(fruit_array, SIZE, set_fruit);
		print_array(fruit_array, SIZE);
		iter<std::string>(fruit_array, SIZE, str_upper);
		print_array(fruit_array, SIZE);

//------------------------------------------------------------------------------		
		divider("Const int array");

		const int *c_int_array = int_array;
		// iter<int>(c_int_array, SIZE, inc_int); // Won´t compile!
		iter<int>(c_int_array, SIZE, put_int);	linebreak();
		iter<int>(c_int_array, SIZE, print);	linebreak();

//------------------------------------------------------------------------------		
		divider("Const string array");
	
		const std::string *c_fruit_array = fruit_array;
		//iter<std::string>(c_fruit_array, SIZE, set_fruit); // Won´t compile!
		iter<std::string>(c_fruit_array, SIZE, put_str);	linebreak();
		iter<std::string>(c_fruit_array, SIZE, print);		linebreak();
	}

	linebreak();
}

// =============================================================================
// Lembrete: na avaliacao, mostrar o overload funcoes template + nao-template.
// print/print_array
// =============================================================================