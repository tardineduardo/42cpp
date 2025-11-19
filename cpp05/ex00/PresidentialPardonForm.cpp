/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:39:39 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/18 23:03:38 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat2.hpp"
#include "messages.hpp"

// ---------- canonical methods ------------------------------------------------

// default constructor
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", k_ppf_signgrade, k_ppf_execgrade) {
	message_ppf_defa_ctor(*this);
}

// parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", k_ppf_signgrade, k_ppf_execgrade) {
	setTarget(target);
	message_ppf_defa_ctor(*this);
}

// copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm("PresidentialPardonForm", k_ppf_signgrade, k_ppf_execgrade) {
	setTarget(other.getTarget());
	message_ppf_copy_ctor(*this);
}

// assignment operator overload
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}	
	return *this;
}

// destructor
PresidentialPardonForm::~PresidentialPardonForm() {
	message_ppf_deft_dtor(*this);
}

// ---------- other methods ----------------------------------------------------

void PresidentialPardonForm::action() const {
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}
