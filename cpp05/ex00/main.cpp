/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:22:06 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/15 23:30:59 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

static void separator(std::string def);

int main(void)
{
// -----------------------------------------------------------------------------	
separator(
"A Bureaucrat must have: a) A constant name. b) A grade that ranges from 1 (highest\n"
"possible grade) to 150 (lowest possible grade).");

	{
		Bureaucrat a;
		Bureaucrat b("Max", 100);

		std::cout << a.getName() << "/" << a.getGrade() << "\n";
		std::cout << b.getName() << "/" << b.getGrade() << "\n";
	}


// -----------------------------------------------------------------------------	
separator(
"Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception:\n"
"either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.");

	// // TEST FOR EVALUATION
	// { Bureaucrat a("Kim", 152); }

	// // TEST FOR EVALUATION
	// { Bureaucrat a("Kim", 0); }

	{
		try { Bureaucrat a("Kim", 152); }
		catch (...) { std::cout << "⚠️ some error (1)\n\n"; }

		try { Bureaucrat b("Max", 100); }
		catch (...) { std::cout << "⚠️ some error (2)\n\n"; }
	}

	{
		try { Bureaucrat a("Kim", 152); }
		catch (std::exception &e) {
			std::cout << "⚠️ some error (1)\n";
			std::cout << e.what() << "\n\n"; }

		try { Bureaucrat b("Max", 100); }
		catch (std::exception &e) {
			std::cout << "⚠️ some error (2)\n\n";
			std::cout << e.what() << "\n\n";
		}

		std::cout << "\ndoesn't break! the exception was caught.\n\n";
	}	



	std::cout << "\n";
}


//A Bureaucrat must have: A constant name. A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).


//Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception: either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

//You will provide getters for both attributes: getName() and getGrade().

//You must also implement two member functions to increment or decrement the bureaucrat’s grade. If the grade goes out of range, both functions must throw the same exceptions as the constructor.

//If the grade goes out of range, both functions must throw the same exceptions as the constructor.

//The thrown exceptions must be catchable using try and catch blocks:

//You must implement an overload of the insertion («) operator to print output in the following format (without the angle brackets): <name>, bureaucrat grade <grade>.


static void separator(std::string def)
{
	static int a = 1;

	std::cout <<"\n\n--------------------------------------------------------------------------------\n"
			  << a << ". " << def << "\n\n";

	a++;
}