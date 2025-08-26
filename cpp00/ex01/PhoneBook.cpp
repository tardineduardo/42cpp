# include <string>
# include "Contact.hpp"
# include "PhoneBook.hpp"

void PhoneBook::addcontact(Contact& input)
{

//    if (contactlist_[a].get_firstname().empty())


	int a;
	//find empty slot
	for (a = 0; contactlist_[a].firstname() != "" && a < SIZE; a++);

	if (a < SIZE)
	{


	}
	


}


