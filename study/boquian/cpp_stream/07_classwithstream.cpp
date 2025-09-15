//stream-enabled classes
#include <string>
#include <sstream>
#include <iostream>

struct Dog {
	int			age_;
	std::string	name_;
};

std::ostream& operator<<(std::ostream& sm, const Dog& d) {
	sm << "my name is " << d.name_ << " and my age is " << d.age_ << '\n';
	return sm;
}

std::istream& operator>>(std::istream& sm, Dog& d) { //not const, we will edit Dog d


}



int main(void)
{
	Dog d{2, "Bob"};
	std::cout << d;
}
