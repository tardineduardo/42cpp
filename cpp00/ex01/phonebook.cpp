/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:21:42 by eduribei          #+#    #+#             */
/*   Updated: 2025/08/17 18:55:24 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include "Contact.hpp"

void clear_screen(void);


int main(void)
{
	while (1)
	{
		std::cout << "My Phonebook\n";
		std::cout << "1. ADD\n";
		std::cout << "2. SEARCH\n";
		std::cout << "3. EXIT\n";
		std::cout << ">> ";

		std::string input;
		std::cin >> input;

		if (input == "EXIT")
			break;

		std::string lowered = mytolower(input);

		if (lowered == "add" || lowered == "1")
		//caput


		clear_screen();
	}

 





}

void clear_screen(void)
{
    std::cout << "\033[2J\033[1;1H";
}

std::string mytolower(std::string& input)
{
	for (int a = 0; input[a]; a++)
		input[a] = tolower(input[a]);
}


