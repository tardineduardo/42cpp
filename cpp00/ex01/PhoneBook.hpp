#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"
# define SIZE 2

class PhoneBook
{
	private:
		Contact contactlist_[SIZE];
		void	redux(const std::string& original);

	public:
		void	SaveContact(Contact& input);
		Contact& getcontact(int index);
		int		printlist();
		int		findlowest();
		void	zerotimes();
		bool	isempty();

	};

#endif