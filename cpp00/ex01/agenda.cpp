/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agenda.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:21:42 by eduribei          #+#    #+#             */
/*   Updated: 2025/08/27 21:51:53 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <time.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void		clear_screen(void);
void		print_menu(void);
void		search_contact(PhoneBook& mycontacts);
void		add_contact(PhoneBook& mycontacts);
std::string	get_option(void);

void input_firstname(Contact& contact);
void input_lastname(Contact& contact);
void input_phone(Contact& contact);
void input_secret(Contact& contact);
void store_time(Contact& contact);
std::string	mytolower(std::string input);

int main(void)
{
	PhoneBook mycontacts;
	mycontacts.zerotimes();

	while (1)
	{
		std::string	option;
	
		clear_screen();
		print_menu();
		option = get_option();

		if (option == "add" || option == "1")
			add_contact(mycontacts);

		else if (option == "search" || option == "2")
			search_contact(mycontacts);

		else if (option == "exit" || option == "3")
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
	std::cout << "First name: ";
	getline(std::cin, firstname);
	contact.set_firstname(firstname);
}

void input_lastname(Contact& contact) {
	std::string lastname;
	std::cout << "Last name: ";
	getline(std::cin, lastname);
	contact.set_lastname(lastname);
}

void input_phone(Contact& contact) {
	//Validate number
	std::string phone;
	std::cout << "Phone number: ";
	getline(std::cin, phone);
	contact.set_phone(phone);
}

void input_secret(Contact& contact) {
	std::string secret;
	std::cout << "Darkest secret: ";
	getline(std::cin, secret);
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



void print_menu(void)
{
    std::cout << "\n";
    std::cout << "                    |\\__/,|   (`\\   \n";
    std::cout << "                  _.|o o  |_   ) )  \n";
    std::cout << "+----------------(((---(((---------+\n";
    std::cout << "|                                  |\n";
    std::cout << "|            PhoneBook             |\n";
    std::cout << "+----------------------------------+\n";
    std::cout << "|                                  |\n";
    std::cout << "|            [1] Add               |\n";
    std::cout << "|            [2] Search            |\n";
    std::cout << "|            [3] Exit              |\n";
    std::cout << "|                                  |\n";
    std::cout << "+----------------------------------+\n";
}

std::string get_option()
{
	std::cout << "Choose an option: ";
	std::string input;
	getline(std::cin, input);
	return (mytolower(input));
}

void add_contact(PhoneBook& mycontacts)
{
	Contact newcontact;
	store_time(newcontact);
	input_firstname(newcontact);
	input_lastname(newcontact);
	input_phone(newcontact);
	input_secret(newcontact);
	mycontacts.SaveContact(newcontact);
}

void search_contact(PhoneBook& mycontacts)
{
	if (mycontacts.isempty())
		return;			
	mycontacts.printlist();
	std::cout << "\nSelect a contact: ";
	std::string input;
	getline(std::cin, input);
}


