/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:39:39 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/16 20:04:30 by eduribei         ###   ########.fr       */
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

// paramet constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string& target)
	: AForm("ShrubberyCreationForm", k_scf_signgrade, k_scf_execgrade) {
	setTarget(target);
	message_scf_defa_ctor(*this);
}

// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm("ShrubberyCreationForm", k_scf_signgrade, k_scf_execgrade) {
	setTarget(other.getTarget());
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

void ShrubberyCreationForm::action() const {
	std::string filename = getTarget() + "_" + "shrubbery";
	std::ofstream MyFile(filename.c_str());
	MyFile << getTree1();
	MyFile.close();
	std::cout << "File " << filename << " saved to local folder\n";
}

std::string getTree1() {
	std::string tree = "          .     .  .      +     .      .          .\n     .       .      .     #       .           .\n        .      .         ###            .      .      .\n      .      .   \"#:. .:##\"##:. .:#\"  .      .\n          .      . \"####\"###\"####\"  .\n       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n  .             \"#########\"#########\"        .        .\n        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n                .\"##\"#####\"#####\"##\"           .      .\n    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n      .     \"#######\"##\"#####\"##\"#######\"      .     .\n    .    .     \"#####\"\"#######\"\"#####\"    .      .\n            .     \"      000      \"    .     .\n       .         .   .   000     .        .       .\n.. .. ..................O000O........................ ......";
	return tree;
}
