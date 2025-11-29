#include<string>
#include<iostream>
#include<cctype>
#include<limits>
#include<cmath>

int main(void)
{
	std::string input = "922337203685477580700";
	
	char *end = NULL;
	const char *str = input.c_str();
	long long value = std::strtoll(str, &end, 10);

	std::cout << value << std::endl;


}