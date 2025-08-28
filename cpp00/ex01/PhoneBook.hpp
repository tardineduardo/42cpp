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
		void	addcontact(Contact& input);
		void	getcontact();
		int		printlist();
		int		findlowest();
		void	zerotimes();
		bool	isempty();

	};

#endif