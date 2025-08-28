#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void PhoneBook::addcontact(Contact& input)
{
	int a;

	for (a = 0; PhoneBook::contactlist_[a].firstname() != "" && a < SIZE; a++) {
	    if (PhoneBook::contactlist_[a].firstname().empty())
			break;
	}

	if (a < SIZE) {
		PhoneBook::contactlist_[a] = input;
	}
	else {
		a = findlowest();
		PhoneBook::contactlist_[a] = input;
	}	

}

int PhoneBook::findlowest()
{
	int		a;
	int		lowindex;
	time_t	lowest;
	
	a = 0;
	lowindex = a;
	lowest = PhoneBook::contactlist_[a].time();
	for (a = 0; a < SIZE; a++) {
	    if (PhoneBook::contactlist_[a].time() < lowest) {
			lowest = PhoneBook::contactlist_[a].time();
			lowindex = a;
		}
	}
	return lowindex;
}

void PhoneBook::zerotimes()
{
	for(int a = 0; a < SIZE; a++)
		PhoneBook::contactlist_[a].set_time(0);	
}

int PhoneBook::printlist()
{
	std::string pause;

	if (PhoneBook::isempty()) {
		std::cout << "The phonebook is empty " << std::endl;
		std::cout << "(press enter to continue...) " << std::endl;
		std::cin.ignore(10000, '\n');
		getline(std::cin, pause);
		return (0);
	}

	for (int a = 0; a < SIZE; a++)
	{
		std::ostringstream index;

		index << "Contact #" << a + 1;

		if (PhoneBook::contactlist_[a].firstname().empty() == false) {
			redux(index.str());
			std::cout << "|";
			redux((PhoneBook::contactlist_[a].firstname()));
			std::cout << "|";
			redux((PhoneBook::contactlist_[a].lastname()));
			std::cout << "|";
			redux((PhoneBook::contactlist_[a].phone()));
			std::cout << "|";
			redux((PhoneBook::contactlist_[a].secret()));
			std::cout << "\n";
		}
	}
	return (0);
}

bool PhoneBook::isempty()
{
	for (int a = 0; a < SIZE; a++)
		if (contactlist_[a].firstname().empty() == false)
			return (false);
	return (true);
}

void PhoneBook::redux(const std::string& original)
{
	if (original.length() <= 10)
		std::cout << std::setw(10) << std::right << original;
	else
		std::cout << original.substr(0, 9) << ".";
}