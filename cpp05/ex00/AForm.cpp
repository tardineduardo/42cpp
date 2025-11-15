/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:27 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/15 00:00:41 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "messages.hpp"


// ---------- canonical methods ------------------------------------------------

// default constructor
AForm::AForm()
	: _k_name("unnamed"),
	  _k_sign_grade(Bureaucrat::kmingrade),
	  _k_exec_grade(Bureaucrat::kmingrade),
	  _signed(false),
	  _emoji(setEmoji()) {
	message_Aform_defa_ctor(*this);
}

// parameterized constructor
AForm::AForm(std::string name, int s_grade, int e_grade)
	: _k_name(name),
	  _k_sign_grade(validateSignGrade(s_grade)),
	  _k_exec_grade(validateExecGrade(e_grade)),
  	  _signed(false),
	  _emoji(setEmoji()) {
  message_Aform_para_ctor(*this);
}

// copy constructor
AForm::AForm(const AForm& other)
    : _k_name(other._k_name),
	  _k_sign_grade(other._k_sign_grade),
	  _k_exec_grade(other._k_exec_grade),
	  _signed(false),
	  _emoji(setEmoji()) {
  message_Aform_copy_ctor(*this);
}

// assignment operator overload
AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_signed = false;
    	_emoji = setEmoji();
	}
	message_Aform_assg_oper(*this);
	return *this;
}

// destructor
AForm::~AForm() {
	message_Aform_deft_dtor(*this);
}


// ---------- other methods ----------------------------------------------------

const int& AForm::getSignGrade() const {
	return _k_sign_grade;
}

const int& AForm::getExecGrade() const {
	return _k_exec_grade;
}

const std::string& AForm::getName() const {
	return _k_name;
}

bool AForm::getSigned() const {
	return _signed;
}

const std::string& AForm::getEmoji() const {
	return _emoji;
}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= AForm::_k_sign_grade)
		_signed = true;
	else
		throw GradeTooLowException();
}

int& AForm::validateSignGrade(int& value) const {
	if (value < Bureaucrat::kmaxgrade)
		throw GradeTooHighException();
	if (value > Bureaucrat::kmingrade)
		throw GradeTooLowException();
	return (value);
}

int& AForm::validateExecGrade(int& value) const {
	if (value < 1)
		throw GradeTooHighException();
	if (value > 150)
		throw GradeTooLowException();
	return (value);
}

void AForm::execute(Bureaucrat const &executor)
{
	(void)executor;
}



// ---------- exceptions -------------------------------------------------------

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}


// ---------- stream operator overload -----------------------------------------

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os  << f.getName()
		<< f.getEmoji()
		<< " Aform required grades: "
		<< f.getSignGrade()
		<< " (S), "
		<< f.getExecGrade()
		<< "(E)"
		<< std::endl;
	return os;
}


// ---------- random emoji generator -------------------------------------------

std::string AForm::setEmoji(void)
{
	static bool seeded = 0;
	std::string emojis[] = {"📜", "📃", "📕",
							"📗", "📘", "📙",
							"📓", "📒", "📁", };
	if (!seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}
	int size = sizeof(emojis) / sizeof(emojis[0]);
	int index = std::rand() % size;
	return emojis[index];
}
