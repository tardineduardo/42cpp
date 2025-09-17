//string stream
#include <string>
#include <sstream>
#include <iostream>

int main(void)
{
	std::stringstream ss;
	ss << 255 << "  Hex: " << std::hex << 255 << "  Oct: " << std::oct << 255;
	std::cout << ss.str() << '\n';
	// "255  Hex: ff  Oct: 377"

	int a, b, c;
	std::string s1;

	ss >> std::hex >> a; //formatted input works token by token
	ss >> s1;
	ss >> std::hex >> b;
	ss.ignore(6);
	ss >> std::oct >> c;	

	std::cout << a << '\n';
	std::cout << s1 << '\n';
	std::cout << b << '\n';
	std::cout << c << '\n';

	std::istringstream in;		//learn later
	std::istringstream out;		//learn later

}
