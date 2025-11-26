/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:27 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/20 21:44:15 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "messages.hpp"


// ---------- canonical methods ------------------------------------------------

// default constructor
Bureaucrat::Bureaucrat()
	: _name("Unnamed"),
	  _grade(kmingrade),
	  _emoji(setEmoji()) {
	message_bureau_defa_ctor(*this);
}

// parameterized constructor
Bureaucrat::Bureaucrat(std::string name, int value)
	: _name(name),
	  _emoji(setEmoji()) {
	message_bureau_para_ctor(*this);
	try { _grade = validateGrade(value); }
	catch (std::exception &e)
	{
		std::cerr << e.what() <<std::endl;
		std::cerr << "Setting grade to default minimun: " 
				  << Bureaucrat::kmingrade << std::endl;
		_grade = Bureaucrat::kmingrade; }
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name),
	  _grade(other._grade),
	  _emoji(setEmoji()) {
  message_bureau_copy_ctor(*this);
}

// assignment operator overload
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
    	_emoji = setEmoji();
	}
	message_bureau_assg_oper(*this);
	return *this;
}

// destructor
Bureaucrat::~Bureaucrat() {
	message_bureau_deft_dtor(*this);
}


// ---------- other methods ----------------------------------------------------

const int& Bureaucrat::getGrade() const {
	return _grade;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

const std::string& Bureaucrat::getEmoji() const {
	return _emoji;
}

void Bureaucrat::incrementGrade() {
	int new_grade = _grade - 1;
	_grade = validateGrade(new_grade);
}

void Bureaucrat::decrementGrade() {
	int new_grade = _grade + 1;
	_grade = validateGrade(new_grade);
}

void Bureaucrat::incrementGrade(const int& increment) {
	int new_grade = _grade - increment;
	_grade = validateGrade(new_grade);
}

void Bureaucrat::decrementGrade(const int& decrement) {
	int new_grade = _grade + decrement;
	_grade = validateGrade(new_grade);
}

int& Bureaucrat::validateGrade(int& value) const {
	if (value < kmaxgrade)
		throw GradeTooHighException();
	if (value > kmingrade)
		throw GradeTooLowException();
	return (value);
}

void Bureaucrat::signForm(Form& f)
{
	try {
		f.beSigned(*this);
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << _name << _emoji
				  << " couldn't sign " 
				  << f.getName() << f.getEmoji() 
				  << " because their grade is too low."
				  << std::endl;
		return;
	}
	std::cout << _name << _emoji
			  << " signed " 
			  << f.getName() << f.getEmoji()
			  << std::endl;	
}


// ---------- exceptions -------------------------------------------------------

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}


// ---------- stream operator overload -----------------------------------------

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os	<< b.getName()
		<< b.getEmoji()
		<< ", bureaucrat grade "
		<< b.getGrade()
		<< std::endl;
	return os;
}


// ---------- random emoji generator -------------------------------------------

std::string Bureaucrat::setEmoji(void)
{
	static bool seeded = 0;
	std::string emojis[] = {"🙍", "🧕", "🤵", "🎅",
							"🧟", "🧛", "👳", "👷",
							"👮", "💂", "🥷", "👲",
							"🧙", "🧝", "🙎", "👰"};
	if (!seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}
	int size = sizeof(emojis) / sizeof(emojis[0]);
	int index = std::rand() % size;
	return emojis[index];
}
