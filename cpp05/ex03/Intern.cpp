/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:16:08 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/22 17:49:24 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"

AForm *schrubb(std::string& target);
AForm *robotomy(std::string& target);
AForm *pardon(std::string& target);


// ---------- canonical methods ------------------------------------------------

// default constructor
Intern::Intern() {}

// copy constructor
Intern::Intern(const Intern& other) { (void)other; }

// assignment operator overload
Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {}
	return *this;
}

// destructor
Intern::~Intern() {}


// ---------- other methods ----------------------------------------------------


AForm *Intern::makeForm(const std::string form, std::string target) const {

	if (form == "" ) {
		std::cout << "Invalid form name";
		return NULL;
	}

	if (target == "") {
		std::cout << "Invalid target name";
		return NULL;
	}

	intern_tasks list[] = {
		{"shrubbery", &schrubb},
		{"robotomy", &robotomy},
		{"pardon", &pardon},
	};

	int a;
	int size = sizeof(list) / sizeof(list[0]);

	for(a = 0; a < size; a++) {
		if (list[a].request == form)
			return (list[a].action(target));
	}
	std::cout << "Invalid form name\n";
	return NULL;	
}

// ---------- exceptions -------------------------------------------------------

const char *Intern::InternException::what() const throw() {
	return "generic Intern error\n";
}

AForm *schrubb(std::string& target) {
	AForm *s = new ShrubberyCreationForm(target);
	return s;
}

AForm *robotomy(std::string& target) {
	AForm *s = new RobotomyRequestForm(target);
	return s;
}

AForm *pardon(std::string& target) {
	AForm *s = new PresidentialPardonForm(target);
	return s;
}


