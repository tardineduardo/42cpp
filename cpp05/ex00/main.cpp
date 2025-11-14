#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
	Bureaucrat maxine("Maxine", 50);
	}
	catch (...)
	{
		std::cout << "error";
	}	
}
