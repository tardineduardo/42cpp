/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:39:39 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/18 22:58:02 by eduribei         ###   ########.fr       */
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

// paramet constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", k_rrf_signgrade, k_rrf_execgrade) {
	setTarget(target);
	message_rrf_defa_ctor(*this);
}

// copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm("RobotomyRequestForm", k_rrf_signgrade, k_rrf_execgrade) {
	setTarget(other.getTarget());
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

void RobotomyRequestForm::action() const {
	// static bool seeded = false;
	// if (!seeded) {
	// 	std::srand(static_cast<unsigned int>(std::time(NULL)));
	// 	seeded = true;
	// }

	std::cout << "🔊 biiiiiiiip [DRILLING NOISES]" << std::endl;
	int sucess = std::rand() % 2;

	if (sucess)
		std::cout << "🤖 " << getTarget() << " has been does robotomized ✅" << std::endl;
	else {
		std::cout << "🤖 " << getTarget() << "'s robotomization failed ❌" << std::endl;
		throw (RandomFailException());
	}
}
		// ---------- exceptions -----------------------------------------------

const char *RobotomyRequestForm::RandomFailException::what() const throw() {
	return "failed robotomy";
}	