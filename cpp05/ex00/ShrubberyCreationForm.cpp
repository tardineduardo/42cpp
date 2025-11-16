/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:39:39 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/16 15:00:38 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat2.hpp"
#include "messages.hpp"

// ---------- canonical methods ------------------------------------------------

// default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", k_scf_signgrade, k_scf_execgrade) {
	message_scf_defa_ctor(*this);
}

// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm("ShrubberyCreationForm", k_scf_signgrade, k_scf_execgrade) {
	(void)other;
	message_scf_copy_ctor(*this);
}

// assignment operator overload
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}	
	return *this;
}

// destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	message_scf_deft_dtor(*this);
}


// ---------- other methods ----------------------------------------------------

void ShrubberyCreationForm::execute(Bureaucrat2 const &executor) const {
	(void)executor;
}

void ShrubberyCreationForm::actionDrawTrees(std::string& target) const {
	(void)target;
	//Creates a file <target>_shrubbery in the working directory and writes ASCII trees
	//inside it.
	//TO DO
}



// ---------- exceptions -------------------------------------------------------




// ---------- stream operator overload -----------------------------------------



// ---------- random emoji generator -------------------------------------------

