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
static void p(std::string x);

int main(void)
{
// -----------------------------------------------------------------------------	
separator(
"A Bureaucrat must have: a) A constant name. b) A grade that ranges from 1 (highest\n"
"possible grade) to 150 (lowest possible grade). You will provide getters for both\n"
"attributes: getName() and getGrade()");

	{
		Bureaucrat a;
		Bureaucrat b("Max", 100);

		std::cout << a.getName() << "/" << a.getGrade() << std::endl;
		std::cout << b.getName() << "/" << b.getGrade() << std::endl;
	}


// -----------------------------------------------------------------------------	
separator(
"You must implement an overload of the insertion («) operator to print output in\n"
"the following format (without the angle brackets): <name>, bureaucrat grade <grade>.");

	{
		Bureaucrat a;
		Bureaucrat b("Max", 100);

		std::cout << a;
		std::cout << b;
	}


// -----------------------------------------------------------------------------	
separator(
"Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception:\n"
"either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.\n"
"The thrown exceptions must be catchable using try and catch blocks.");

	// // TEST FOR EVALUATION
	// { Bureaucrat a("Kim", 152); }

	// // TEST FOR EVALUATION
	// { Bureaucrat a("Kim", 0); }

	{
		p("------ A ------");
		try { Bureaucrat kim("Kim", 152); }
		catch (...) { std::cout << "some error (1)\n\n"; }

		p("------ B ------");
		try { Bureaucrat max("Max", 100); }
		catch (...) { std::cout << "some error (2)\n\n"; }

		p("------ C ------");
		try { Bureaucrat zoe("Zoe", 152); }
		catch (std::exception &e) { std::cout << e.what() << "\n\n"; }

		p("------ D ------");
		try { Bureaucrat joe("Joe", 0); }
		catch (std::exception &e) { std::cout << e.what() << "\n\n"; }

		p("------ E ------");
		try { Bureaucrat ian("Ian", 100); }
		catch (std::exception &e) { std::cout << e.what() << "\n\n"; }

		p("------ F ------");
		try { Bureaucrat sam("Sam", 152); }
		catch (std::exception &e) { std::cout << e.what() << "\n\n"; }

		// INVERT ORDER DURING EVALUATION
		p("------ G ------");
		try { Bureaucrat dan("Dan", 170); } 
		catch (Bureaucrat::GradeTooHighException &e) { std::cout << e.what() << "\n\n"; }
		catch (Bureaucrat::GradeTooLowException &e) { std::cout << e.what() << "\n\n"; }
		catch (std::exception &e) { std::cout << e.what() << "\n\n"; }
		catch (...) { std::cout << "some error (1)\n\n"; }
	}	


// -----------------------------------------------------------------------------	
separator(
"You must also implement two member functions to increment or decrement the\n" 
"bureaucrat's grade. If the grade goes out of range, both functions must throw\n"
"the same exceptions as the constructor.");

	p("------ A ------");
	{
		// // TEST FOR EVALUATION
		// Bureaucrat max("Max", 1);	
		// max.incrementGrade();

		Bureaucrat bob("Bob", 10);	
		std::cout << bob;
		bob.incrementGrade();
		std::cout << bob;

		Bureaucrat don("Don", 1);
		std::cout << don;
		don.decrementGrade();
		std::cout << don;

		Bureaucrat max("Max", 1);	
		try { max.incrementGrade(); }
		catch (std::exception &e) { std::cout << e.what() << "\n"; }

		Bureaucrat jan("Jan", 150);	
		try { jan.decrementGrade(); }
		catch (std::exception &e) { std::cout << e.what() << "\n"; }
	}

	p("------ B ------");
	{
		Bureaucrat bob("Bob", 10);	
		std::cout << bob;
		bob.incrementGrade(9);
		std::cout << bob;

		Bureaucrat don("Don", 1);
		std::cout << don;
		don.decrementGrade(100);
		std::cout << don;

		Bureaucrat max("Max", 100);	
		try { max.incrementGrade(200); }
		catch (std::exception &e) { std::cout << e.what() << "\n"; }

		Bureaucrat jan("Jan", 100);	
		try { jan.decrementGrade(60); }
		catch (std::exception &e) { std::cout << e.what() << "\n"; }
	}


// -----------------------------------------------------------------------------	
separator(
"A Form class has a) a constant name, b) a boolean indicating whether it is"
"signed (at construction, it is not), c) A constant grade required to sign it,"
"d) A constant grade required to execute it.");












	std::cout << "\n";
}


































static void separator(std::string def)
{
	static int a = 1;

	std::cout <<"\n\n--------------------------------------------------------------------------------\n"
			  << a << ". " << def << "\n\n";

	a++;
}

static void p(std::string x)
{
	std::cout << "\n[" << x << "]\n";

}