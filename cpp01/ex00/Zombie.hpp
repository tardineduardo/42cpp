#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>   // include only what is necessary

class Zombie {
	private:
		std::string name_;
		void announce(void);


	public:
		Zombie();								// Default constructor
		Zombie(const Zombie& other);			// Copy constructor
		Zombie& operator=(const Zombie& rhs);	// Copy assignment operator
		~Zombie();								// Destructor

	// Other public methods
	Zombie* newZombie(std::string name);
	void randomChump(std::string name);
};

#endif