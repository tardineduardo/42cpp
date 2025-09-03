#include "Zombie.hpp"

Zombie::Zombie()
{
	static int count = 1;
	std::ostringstream name;
	name << "generic" << std::setfill('0') << std::setw(3) << count++;
	name_ = name.str();
}

Zombie::Zombie(std::string name)
{
	name_ = name;
}

Zombie::~Zombie()
{
	std::cout << RED "❌ destroying " << Zombie::name_ << RESET << std::endl;
}

void Zombie::announce(void)
{
	std::cout << "🧟 " << Zombie::name_ << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::name()
{	
	return Zombie::name_;
}
