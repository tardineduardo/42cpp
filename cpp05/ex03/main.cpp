/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:22:06 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/22 17:58:04 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

static void separator(std::string def);
static void p(std::string x);

int main(void)
{
try { 

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
"The base class Form must be an abstract class and should therefore be renamed\n"
"AForm. The form's attributes need to remain private\n\n."
"ShrubberyCreationForm: Required grades: sign 145, exec 137. Creates a file\n"
"<target>_shrubbery in the working directory and writes ASCII trees inside it.\n"
"All of them take only one parameter in their constructor: the target of the form.");

	{
		p("------ A ------");
		Bureaucrat max("Max", 1);
		Bureaucrat kim("Kim", 150);
		std::cout << max;
		std::cout << kim;

		p("------ B ------");
		ShrubberyCreationForm a("file_path");
		std::cout << a;

		p("------ C ------");
		kim.signForm(a);
		max.signForm(a);
	
		p("------ D ------");
		kim.executeForm(a);
		max.executeForm(a);

		p("------ D ------");
		a.setTarget("xxxxxxxxxx");

		p("------ E ------");
		kim.executeForm(a);
		std::cout << std::endl;
		max.executeForm(a);

		std::cout << std::endl;
	}


// -----------------------------------------------------------------------------
separator(
"RobotomyRequestForm: Required grades: sign 72, exec 45. Makes some drilling\n"
"noises, then informs that <target> has been robotomized successfully 50\% of\n"
"the time. Otherwise, it informs that the robotomy failed. All of them take\n"
"only one parameter in their constructor: the target of the form.");

	{
		p("------ A ------");
		Bureaucrat ben("Ben", 1);
		Bureaucrat tim("Tim", 150);
		std::cout << ben;
		std::cout << tim;

		p("------ B ------");
		RobotomyRequestForm a("Robot1");
		RobotomyRequestForm b("Robot2");
		RobotomyRequestForm c("Robot3");
		RobotomyRequestForm d("Robot4");
		RobotomyRequestForm e("Robot5");		
		RobotomyRequestForm f("Robot6");
		RobotomyRequestForm g("Robot7");				
		RobotomyRequestForm h("Robot8");
		RobotomyRequestForm i("Robot9");
		RobotomyRequestForm j("Robot10");

		
		p("------ C ------");
		ben.signForm(a);
		ben.signForm(b);
		ben.signForm(c);	
		ben.signForm(d);
		ben.signForm(e);
		ben.signForm(f);
		ben.signForm(g);
		ben.signForm(h);
		ben.signForm(i);
		ben.signForm(j);
	
		p("------ D ------");
		ben.executeForm(a); std::cout << std::endl;
		ben.executeForm(b); std::cout << std::endl;
		ben.executeForm(c); std::cout << std::endl;	
		ben.executeForm(d); std::cout << std::endl;
		ben.executeForm(e); std::cout << std::endl;
		ben.executeForm(f); std::cout << std::endl;
		ben.executeForm(g); std::cout << std::endl;
		ben.executeForm(h); std::cout << std::endl;
		ben.executeForm(i); std::cout << std::endl;
		ben.executeForm(j); std::cout << std::endl;

		p("------ D ------");
		a.setTarget("xxxxxxxxxx");

		p("------ E ------");
		tim.executeForm(a);
		std::cout << std::endl;
		ben.executeForm(a);

		std::cout << std::endl;
	}

// -----------------------------------------------------------------------------
separator(
"PresidentialPardonForm: Required grades: sign 25, exec 5. Informs that <target>\n"
"has been pardoned by Zaphod Beeblebrox. Takes only one parameter in the\n"
"constructor: the target of the form.");

	{
		p("------ A ------");
		Bureaucrat max("Max", 1);
		Bureaucrat kim("Kim", 150);
		std::cout << max;
		std::cout << kim;

		p("------ B ------");
		PresidentialPardonForm a("John");
		std::cout << a;

		p("------ C ------");
		kim.signForm(a);
		max.signForm(a);
	
		p("------ D ------");
		kim.executeForm(a);
		max.executeForm(a);

		p("------ D ------");
		a.setTarget("xxxxxxxxxx");

		p("------ E ------");
		kim.executeForm(a);
		std::cout << std::endl;
		max.executeForm(a);

		std::cout << std::endl;
	}

// -----------------------------------------------------------------------------
separator(
"Intern: makeForm(\"form name\", \"target\") returns a concrete AForm* or\n"
"NULL and prints an error if the form name is invalid.");

    {
        p("------ A ------");
        Intern      random_intern;
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 20);
		std::cout << boss;
		std::cout << manager;
        p("------ B ------");


        // 1) Valid form name: Shrubbery
        AForm *shrub = random_intern.makeForm("shrubbery", "file_prefix");
        if (shrub != NULL)
        {
            std::cout << *shrub;
            manager.signForm(*shrub);
            manager.executeForm(*shrub);
			boss.signForm(*shrub);
            boss.executeForm(*shrub);
            delete shrub;
        }

        // 2) Valid form name: Robotomy
        p("------ C ------");

        AForm *robotomy = random_intern.makeForm("robotomy", "Mario");
        if (robotomy != NULL)
        {
            std::cout << *robotomy;
            manager.signForm(*robotomy);
            manager.executeForm(*robotomy);			
            boss.signForm(*robotomy);
            boss.executeForm(*robotomy);
            delete robotomy;
        }

        // 3) Valid form name: Presidential pardon
        p("------ D ------");

        AForm *pardon = random_intern.makeForm("pardon", "Luigi");
        if (pardon != NULL)
        {
            std::cout << *pardon;
            manager.signForm(*pardon);
            manager.executeForm(*pardon);			
            boss.signForm(*pardon);
            boss.executeForm(*pardon);
            delete pardon;
        }

        // 4) Invalid form name – should trigger Intern's error path
        p("------ E ------");

		AForm *unknown = random_intern.makeForm("coffee", "Melita");
        if (unknown != NULL)
		    delete unknown;
	

    }	



	std::cout << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

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