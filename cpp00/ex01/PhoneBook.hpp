#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"
# define SIZE 8

class PhoneBook
{
	private:
		Contact contactlist_[SIZE];

	public:
		void addcontact(Contact& input);
		void getcontact();
};

#endif