/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agenda.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:21:42 by eduribei          #+#    #+#             */
/*   Updated: 2025/08/25 22:30:52 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void clear_screen(void);
void input_firstname(Contact& contact);
void input_lastname(Contact& contact);
void input_phone(Contact& contact);
void input_secret(Contact& contact);
void store_time(Contact& contact);
std::string	mytolower(std::string input);

int main(void)
{
	PhoneBook mycontacts;

	while (1)
	{
		clear_screen();
		std::cout << "My Phonebook"	<< std::endl;
		std::cout << "1. ADD"		<< std::endl;
		std::cout << "2. SEARCH"	<< std::endl;
		std::cout << "3. EXIT"		<< std::endl;
		std::cout << ">> ";

		std::string input;

		//std::getline(cin, input);
		std::cin >> input;
		std::string lowered = mytolower(input);

		if (lowered == "add" || lowered == "1") {
			Contact newcontact;
			store_time(newcontact);
			input_firstname(newcontact);
			input_lastname(newcontact);
			input_phone(newcontact);
			input_secret(newcontact);
			//mycontacts.addcontact(newcontact);
		}
		else if (lowered == "search" || lowered == "2")
			continue;
		else if (lowered == "exit" || lowered == "3")
			return 0;
	}
}

void store_time(Contact& contact) {
	std::time_t time;
	std::time(&time);
	contact.set_time(time);
}

void input_firstname(Contact& contact) {
	std::string firstname;
	std::cin >> firstname;
	contact.set_firstname(firstname);
}

void input_lastname(Contact& contact) {
	std::string lastname;
	std::cin >> lastname;
	contact.set_lastname(lastname);
}

void input_phone(Contact& contact) {
	//Validate number
	std::string phone;
	std::cin >> phone;
	contact.set_phone(phone);
}

void input_secret(Contact& contact) {
	std::string secret;
	std::cin >> secret;
	contact.set_secret(secret);
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


