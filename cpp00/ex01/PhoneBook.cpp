# include <string>
# include "Contact.hpp"
# include "PhoneBook.hpp"

// int PhoneBook::find_lowest();


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
