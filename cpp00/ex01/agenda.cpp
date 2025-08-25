/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agenda.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:21:42 by eduribei          #+#    #+#             */
/*   Updated: 2025/08/23 14:58:54 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void clear_screen(void);

std::string mytolower(std::string input);

int main(void)
{
	//PhoneBook mycontacts;

	while (1)
	{
		clear_screen();
		std::cout << "My Phonebook" << std::endl;
		std::cout << "1. ADD" << std::endl;
		std::cout << "2. SEARCH" << std::endl;
		std::cout << "3. EXIT" << std::endl;
		std::cout << ">> ";

		std::string input;

		std::getline(std::cin, input);

		std::string lowered = mytolower(input);

		if (lowered == "add" || lowered == "1")
		{
			Contact newcontact;
			newcontact.read_firstname(std::cin);
			newcontact.read_lastname(std::cin);
			newcontact.read_phonenumber(std::cin);
			newcontact.read_secret(std::cin);
		//	mycontacts.addcontact(newcontact);
			continue;
		}

		else if (lowered == "search" || lowered == "2")
			continue;
		else if (lowered == "exit" || lowered == "3")
			return 0;
	}

}

void clear_screen(void)
{
    std::cout << "\033[2J\033[1;1H";
}

std::string mytolower(std::string input)
{
	for (int a = 0; input[a]; a++)
		input[a] = std::tolower(static_cast<unsigned char>(input[a]));
	return input;	
}


