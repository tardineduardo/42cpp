/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:22:06 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/16 13:31:27 by eduribei         ###   ########.fr       */
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
"A Form class has a) a constant name, b) a boolean indicating whether it is\n"
"signed (at construction, it is not), c) A constant grade required to sign it,\n"
"d) A constant grade required to execute it. As before, write getters for all\n"
"attributes and overload the insertion («) operator to print the form's info.");


	{
		Form a;
		Form b("XPTO11", 100, 20);

		std::cout << a.getName() << "/" 
				  << a.getSignGrade() << "/"
				  << a.getExecGrade() << "/"				  
				  << a.getSigned() << std::endl;

		std::cout << b.getName() << "/" 
				  << b.getSignGrade() << "/"
				  << b.getExecGrade() << "/"				  
				  << b.getSigned() << std::endl;
	
		std::cout << a;
		std::cout << b;
	}


// -----------------------------------------------------------------------------	
separator(
"The grades of the Form follow the same rules as those of the Bureaucrat. Thus,\n"
"the following exceptions will be thrown if a form's grade is out of bounds:\n"
"Form::GradeTooHighException and Form::GradeTooLowException.");

	{
		p("------ A ------");
		try { Form a("FAA1XX", 152, 10); }
		catch (...) { std::cout << "some error (1)\n\n"; }

		p("------ B ------");
		try { Form b("FBB3ZZ", 100, 10); }
		catch (...) { std::cout << "some error (2)\n\n"; }

		p("------ C ------");
		try { Form b("FCC4WL", 152, 10); }
		catch (std::exception &e) { std::cout << e.what() << "\n\n"; }

		p("------ D ------");
		try { Form d("FDD123", 10, 0); }
		catch (std::exception &e) { std::cout << e.what() << "\n\n"; }

		p("------ E ------");
		try { Form e("FEEX44", 100, 20); }
		catch (std::exception &e) { std::cout << e.what() << "\n\n"; }

		p("------ F ------");
		try { Form f("FFFX12", 1, 152); }
		catch (std::exception &e) { std::cout << e.what() << "\n\n"; }

		// INVERT ORDER DURING EVALUATION
		p("------ G ------");
		try { Form g("FGGV2", 10, 170); } 
		catch (Form::GradeTooHighException &e) { std::cout << e.what() << "\n\n"; }
		catch (Form::GradeTooLowException &e) { std::cout << e.what() << "\n\n"; }
		catch (std::exception &e) { std::cout << e.what() << "\n\n"; }
		catch (...) { std::cout << "some error (1)\n\n"; }
	}	



// -----------------------------------------------------------------------------	
separator(
"Add a beSigned() member function to the Form that takes a Bureaucrat as a\n"
"parameter. It changes the form's status to signed if the bureaucrat's grade\n"
"is high enough (greater than or equal to the required one). If the grade is\n"
"too low, throw a Form::GradeTooLowException.");

	{
		p("------ A ------");
		Bureaucrat max("Max", 100);
		Form b("XPTO11", 100, 20);
		std::cout << max;
		std::cout << b;
		b.beSigned(max);
		std::cout << b << "\n";

		// // TEST FOR EVALUATION
		// p("------ TEST ------");
		// Bureaucrat jim("Jim", 100);
		// Form x("XPTO11", 10, 20);
		// std::cout << jim;
		// std::cout << x;
		// x.beSigned(kim);
		// std::cout << x << "\n";

		p("------ B ------");
		Bureaucrat kim("Kim", 100);
		Form c("XPTO11", 10, 20);
		std::cout << kim;
		std::cout << c;
		try { c.beSigned(kim); }
		catch(std::exception &e) { std::cout << e.what() << "\n"; }
		std::cout << c << "\n";

	}

// -----------------------------------------------------------------------------	
separator(
"Add a signForm() member function in the Bureaucrat class. This function must\n"
"call Form::beSigned() to attempt to sign the form. If the form is signed successfully,\n"
"it will print something like: <bureaucrat> signed <form>. Otherwise, it will\n"
"print something like: <bureaucrat> couldn’t sign <form> because <reason>.");

	{
		p("------ A ------");
		Bureaucrat max("Max", 100);
		Form b("XPTO11", 100, 20);
		std::cout << max;
		std::cout << b;
		max.signForm(b);
		std::cout << b << "\n";

		p("------ A ------");
		Bureaucrat tim("Tim", 100);
		Form c("XPTO12", 1, 20);
		std::cout << tim;
		std::cout << c;
		tim.signForm(c);
		std::cout << c << "\n";
	}

	// TRY/CATCH NOT VISIBLE TO USER ANYMORE! <3

	std::cout << "\n";
}



////////////////////////////////////////////////////////////////////////////////
//																			  //
//							Helpersss										  //
//																			  //
////////////////////////////////////////////////////////////////////////////////

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