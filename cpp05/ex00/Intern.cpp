/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:30:31 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/19 02:40:57 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "messages.hpp"

// ---------- canonical methods ------------------------------------------------

// default constructor
Intern::Intern() {
	message_intrn_defa_ctor();
}

// copy constructor
Intern::Intern(const Intern& other) {
  message_intrn_copy_ctor();
}

// assignment operator overload
Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {}
	message_intrn_assg_oper();
	return *this;
}

// destructor
Intern::~Intern() {
	message_intrn_deft_dtor();
}

AForm *Intern::makeForm(const std::string& name, const std::string& target) {
	std::string types[] = {"pardon", "shruberry", "robotomy"};

	void (AForm::*function[])(void) = {
		&pardon(target), 		&AForm:: (target),
		&AForm:: action(target),};	
	
	

}

// ---------- exceptions -------------------------------------------------------

const char *Intern::InvalidFormException::what() const throw() {
	return "Form is invalid";
}

// ---------- helpers ----------------------------------------------------------

AForm *pardon(const std::string& target) {
	AForm form = new PresidentialPardonForm(target)
	return new;
}

AForm *schruberry(const std::string& target) {
	AForm form = new ShrubberyCreationForm(target)
	return new;
}

AForm *pardon(const std::string& target) {
	AForm form = new RobotomyRequestForm(target)
	return new;
}