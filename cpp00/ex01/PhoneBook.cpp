#include <string>
#include <iostream>
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
		std::cout << "The phonebook is empty ";
		//usar getline
		std::cout << "(press enter to continue...) " ;
		std::cin >> pause;
		return (0);
	}

	for (int a = 0; a < SIZE; a++)
	{
		if (PhoneBook::contactlist_[a].firstname().empty() == false) {
			std::cout << PhoneBook::contactlist_[a].firstname() << "|" <<
			PhoneBook::contactlist_[a].lastname() << "|" <<
			PhoneBook::contactlist_[a].phone() << "|" <<
			PhoneBook::contactlist_[a].secret() << std::endl;
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
