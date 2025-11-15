/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:22:06 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/15 19:12:46 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
// CASE X - Default constructor------------------------------------------------

	std::cout << "1." << std::endl;

	{
		Bureaucrat a;
		std::cout << a;
	}

	std::cout << std::endl;

// CASE X - Default constructor------------------------------------------------

	std::cout << "2." << std::endl;

	{
		Bureaucrat a("Max", 1);
		std::cout << a;
		try {
			a.incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{std::cout << "error\n";}
		std::cout << a;
		try {
			a.decrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{}
				std::cout << a;





	}

	std::cout << std::endl;




	try 
	{
		Bureaucrat b1("Max", 20);
		std::cout << b1;
	}
	catch (...) 
	{
		std::cout << "Can't instanciate bureacrat.\n";
	}

	//-------------------------------------- CASE 2 ----------------------------	
	try 
	{
		Bureaucrat b2("Yan", 50);
		Bureaucrat b1("Max", 20);
		b1 = b2;
		b1.decrementGrade(6);
		std::cout << b1.getGrade() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) 
	{
		std::cout << "Can't instanciate bureacrat.\n";
	}

	//-------------------------------------- CASE 3 ----------------------------	

	Form new1;

	Form form("C10XPTO",100, Bureaucrat::kmingrade);

	std::cout << new1;
	std::cout << form;

	//-------------------------------------- CASE 4 ----------------------------	




}



//A Bureaucrat must have: • A constant name. • A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade). Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception: either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

//You will provide getters for both attributes: getName() and getGrade().

//You must also implement two member functions to increment or decrement the bureaucrat’s grade. If the grade goes out of range, both functions must throw the same exceptions as the constructor.

//If the grade goes out of range, both functions must throw the same exceptions as the constructor.

//The thrown exceptions must be catchable using try and catch blocks:

//You must implement an overload of the insertion («) operator to print output in the following format (without the angle brackets): <name>, bureaucrat grade <grade>.
