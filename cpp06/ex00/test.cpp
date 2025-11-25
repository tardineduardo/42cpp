#include<string>
#include<iostream>
#include<cctype>

int main(void)
{
	std::string a = "éb";

	std::cout << a[0] << std::endl;
	std::cout << static_cast<char>(a[0]) << std::endl;
	std::cout << static_cast<int>(a[0]) << std::endl;
	std::cout << static_cast<unsigned int>(a[0]) << std::endl;
	std::cout << static_cast<unsigned char>(a[0]) << std::endl;
	std::cout << a[0] << std::endl;
}