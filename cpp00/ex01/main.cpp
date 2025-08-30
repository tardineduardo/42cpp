/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agenda.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:21:42 by eduribei          #+#    #+#             */
/*   Updated: 2025/08/29 21:22:05 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <sstream> 
#include <time.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void		clear_screen(void);
void		print_menu(void);
void		search_contact(PhoneBook& mycontacts);
void		add_contact(PhoneBook& mycontacts);
void		input_firstname(Contact& contact);
void		input_lastname(Contact& contact);
void		input_phone(Contact& contact);
void		input_secret(Contact& contact);
void		store_time(Contact& contact);
bool		is_valid(std::string& phone);
bool		is_empty(std::string& input);
std::string	mytolower(std::string input);
std::string	get_option(void);

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

		else if (option == "search" || option == "2") {
			clear_screen();
			search_contact(mycontacts);
		}

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
	while(1){
		getline(std::cin, firstname);
		if (is_empty(firstname))
			continue;
		else
			break;	
	}
	contact.set_firstname(firstname);
}

void input_lastname(Contact& contact) {
	std::string lastname;
	std::cout << "Last name: ";
	while(1){
		getline(std::cin, lastname);
		if (is_empty(lastname))
			continue;
		else
			break;	
	}
	contact.set_lastname(lastname);
}

void input_phone(Contact& contact) {
	std::string phone;
	std::cout << "Phone number: ";
	while(1) {
		getline(std::cin, phone);
		if (!is_valid(phone))
			continue;
		else
			break;
	}		
	contact.set_phone(phone);
}

void input_secret(Contact& contact) {
	std::string secret;
	std::cout << "Darkest secret: ";
	while(1){
		getline(std::cin, secret);
		if (is_empty(secret))
			continue;
		else
			break;	
	}
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

int my_atoi(const std::string& str) {
    std::istringstream iss(str);
    int value = 0;
    iss >> value;
    return value;
}

void print_menu(void)
{
    std::cout << "\n";
    std::cout << "                       |\\__/,|   (`\\   \n";
    std::cout << "                     _.|o o  |_   ) )  \n";
    std::cout << "+-------------------(((---(((---------------+\n";
    std::cout << "|                                           |\n";
    std::cout << "|                 PhoneBook                 |\n";
    std::cout << "|                                           |\n";
    std::cout << "+-------------------------------------------+\n";                    
    std::cout << "|                                           |\n";
    std::cout << "|                  [1] Add                  |\n";
    std::cout << "|                                           |\n";
    std::cout << "|                  [2] Search               |\n";
    std::cout << "|                                           |\n";
    std::cout << "|                  [3] Exit                 |\n";
    std::cout << "|                                           |\n";
    std::cout << "+-------------------------------------------+\n";
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
	std::cout << std::endl;
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
	std::cout << "\nSelect an index: ";
	std::string input;

	int index = -1;
	Contact selected;

	while (index <= 0 || index >= SIZE) {
		getline(std::cin, input);
		if (input == "exit") return;

		if (my_atoi(input) <= 0 || my_atoi(input) > SIZE) {
			std::cout << "Invalid index, try again: (or \"exit\"): ";
			continue;
		}

		selected = mycontacts.getcontact((my_atoi(input)) - 1);

		if(selected.firstname() == "") {
			std::cout << "Invalid index, try again: (or \"exit\"): ";
			continue;
		}
		else {
			std::cout << std::endl;
			break;	
		}
	}	
	selected.PrintContact();
	std::string pause;
	std::cout << "\n(Press enter to continue...) ";
	getline(std::cin, pause);
}


bool is_valid(std::string& phone)
{
	int pluscount = 0;
	for (int a = 0; phone[a]; a++)
	{
		if (!std::isdigit(static_cast<unsigned char>(phone[a])) && phone[a] != '+')
		{
			std::cout << "Only digits and '+' accepted, try again: ";
			return (false);		
		}
		else if (phone[a] == '+')
			pluscount++;
	}
	if (pluscount > 1)
	{
		std::cout << "Only one '+' accepted, try again: ";
		return (false);
	}
	return (true);
}

bool is_empty(std::string& input)
{
	if (input == "") {
		std::cout << "Can't be empty, try again: ";
		return (true);
	}
	return (false);
}
