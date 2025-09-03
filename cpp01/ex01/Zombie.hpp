#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# define RED	"\001\033[31m\002"
# define RESET	"\001\033[0m\002"

# include <string>
# include <sstream>
# include <iostream>
# include <iomanip>
# include <cstdlib>

class Zombie {
	private:
		std::string	name_;

	public:
		Zombie();
		~Zombie();
		std::string name();
		void set_name(std::string name);
		Zombie(std::string name);
		void announce(void);
};

Zombie* zombieHorde(int N, std::string name);


#endif
