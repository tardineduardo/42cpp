/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:39:39 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/16 15:01:24 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat2.hpp"
#include "messages.hpp"

// ---------- canonical methods ------------------------------------------------

// default constructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", k_rrf_signgrade, k_rrf_execgrade) {
	message_rrf_defa_ctor(*this);
}

// copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm("RobotomyRequestForm", k_rrf_signgrade, k_rrf_execgrade) {
	(void)other;
	message_rrf_copy_ctor(*this);
}

// assignment operator overload
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}	
	return *this;
}

// destructor
RobotomyRequestForm::~RobotomyRequestForm() {
	message_rrf_deft_dtor(*this);
}


// ---------- other methods ----------------------------------------------------

void RobotomyRequestForm::execute(Bureaucrat2 const &executor) const {
	(void)executor;
}

void RobotomyRequestForm::actionDoRobotomy(std::string& target) const {
	(void)target;
	//Makes some drilling noises, then informs that <target> has been robotomized
	//successfully 50% of the time. Otherwise, it informs that the robotomy failed.
	//TO DO
}



// ---------- exceptions -------------------------------------------------------




// ---------- stream operator overload -----------------------------------------



// ---------- random emoji generator -------------------------------------------

