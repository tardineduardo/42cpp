/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:27 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/15 00:00:41 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "messages.hpp"


// ---------- canonical methods ------------------------------------------------

// default constructor
Form::Form()
	: _k_name("unnamed"),
	  _k_sign_grade(Bureaucrat::kmingrade),
	  _k_exec_grade(Bureaucrat::kmingrade),
	  _signed(false),
	  _emoji(setEmoji()) {
	message_form_defa_ctor(*this);
}

// parameterized constructor
Form::Form(std::string name, int s_grade, int e_grade)
	: _k_name(name),
	  _k_sign_grade(Bureaucrat::kmingrade),
	  _k_exec_grade(Bureaucrat::kmingrade),	
  	  _signed(false),
	  _emoji(setEmoji()) {

	try { const_cast<int&>(_k_sign_grade) = validateSignGrade(s_grade); }	
	catch (std::exception &e)
	{
		std::cerr << e.what() <<std::endl;
		std::cerr << "Setting grade to default minimun: "
				  << Bureaucrat::kmingrade << std::endl;
		const_cast<int&>(_k_sign_grade) = Bureaucrat::kmingrade;
	}
	
	try { const_cast<int&>(_k_exec_grade) = validateExecGrade(e_grade); }	
	catch (std::exception &e)
	{
		std::cerr << e.what() <<std::endl;
		std::cerr << "Setting grade to default minimun: "
				  << Bureaucrat::kmingrade << std::endl;
		const_cast<int&>(_k_exec_grade) = Bureaucrat::kmingrade;
	}
	message_form_para_ctor(*this);
}

// copy constructor
Form::Form(const Form& other)
    : _k_name(other._k_name),
	  _k_sign_grade(other._k_sign_grade),
	  _k_exec_grade(other._k_exec_grade),
	  _signed(false),
	  _emoji(setEmoji()) {
  message_form_copy_ctor(*this);
}

// assignment operator overload
Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_signed = false;
    	_emoji = setEmoji();
	}
	message_form_assg_oper(*this);
	return *this;
}

// destructor
Form::~Form() {
	message_form_deft_dtor(*this);
}


// ---------- other methods ----------------------------------------------------

const int& Form::getSignGrade() const {
	return _k_sign_grade;
}

const int& Form::getExecGrade() const {
	return _k_exec_grade;
}

const std::string& Form::getName() const {
	return _k_name;
}

bool Form::getSigned() const {
	return _signed;
}

const std::string& Form::getEmoji() const {
	return _emoji;
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= Form::_k_sign_grade)
		_signed = true;
	else
		throw GradeTooLowException();
}

int& Form::validateSignGrade(int& value) const {
	if (value < Bureaucrat::kmaxgrade)
		throw GradeTooHighException();
	if (value > Bureaucrat::kmingrade)
		throw GradeTooLowException();
	return (value);
}

int& Form::validateExecGrade(int& value) const {
	if (value < 1)
		throw GradeTooHighException();
	if (value > 150)
		throw GradeTooLowException();
	return (value);
}


// ---------- exceptions -------------------------------------------------------

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}


// ---------- stream operator overload -----------------------------------------

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	std::string signedstatus;

	if (f.getSigned())
		signedstatus = "signed";
	else
		signedstatus = "not signed";

	os  << f.getName() << f.getEmoji()
		<< " required grades: "
		<< f.getSignGrade() << "(sign), "
		<< f.getExecGrade() << "(exec), "
		<< signedstatus << std::endl;
	return os;
}


// ---------- random emoji generator -------------------------------------------

std::string Form::setEmoji(void)
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
