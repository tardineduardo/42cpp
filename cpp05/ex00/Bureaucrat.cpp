/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:27 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/14 23:47:47 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "messages.hpp"


// ---------- canonical methods ------------------------------------------------

// default constructor
Bureaucrat::Bureaucrat()
	: _name("default"),
	  _grade(150),
	  _emoji(setEmoji()) {
	message_bureau_defa_ctor(*this);
}

// destructor
Bureaucrat::~Bureaucrat() {
	message_bureau_deft_dtor(*this);
}

// parameterized constructor
Bureaucrat::Bureaucrat(std::string name, int value)
	: _name(name),
	  _grade(setGrade(value)),
	  _emoji(setEmoji()) {
  message_bureau_para_ctor(*this);
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name),
	  _grade(other._grade),
	  _emoji(setEmoji()) {
  message_bureau_copy_ctor(*this);
}

// assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
    	_emoji = setEmoji();
	}
	message_bureau_assg_oper(*this);
	return *this;
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

int Bureaucrat::setGrade(int value) {
	if (value < 1)
		throw GradeTooHighException();
	if (value > 150)
		throw GradeTooLowException();
	_grade = value;
	return (_grade);
}

void Bureaucrat::incrementGrade() {
	int new_grade = _grade - 1;
	setGrade(new_grade);}

void Bureaucrat::decrementGrade() {
	int new_grade = _grade + 1;
	setGrade(new_grade);
}

void Bureaucrat::incrementGrade(const int& increment) {
	int new_grade = _grade - increment;
	setGrade(new_grade);
}

void Bureaucrat::decrementGrade(const int& decrement) {
	int new_grade = _grade + decrement;
	setGrade(new_grade);
}


// ---------- exceptions -------------------------------------------------------

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}


// ---------- stream operator overload -----------------------------------------

std::ostream& operator<<(std::ostream& os, const Bureaucrat& x)
{
	os	<< x.getName()
		<< x.getEmoji()
		<< ", bureaucrat grade "
		<< x.getGrade()
		<< std::endl;
	return os;
}


// ---------- random emoji generator -------------------------------------------

std::string setEmoji(void)
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
