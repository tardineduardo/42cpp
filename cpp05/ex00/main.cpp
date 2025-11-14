#include "Bureaucrat.hpp"

int main(void)
{
	//-------------------------------------- CASE 1 ----------------------------	
	try 
	{
		Bureaucrat max("Max", 300);
	}
	catch (...) 
	{
		std::cout << "Can't instanciate bureacrat.\n";
	}

	//-------------------------------------- CASE 2 ----------------------------	
	try 
	{
		Bureaucrat max("Max", 300);
	}
	catch (Bureaucrat::GradeTooHighException &e) 
	{
		std::cout << "Can't instanciate bureacrat.\n";
	}

	//-------------------------------------- CASE 3 ----------------------------	





	//-------------------------------------- CASE 4 ----------------------------	




}