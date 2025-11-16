/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat2.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:27 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/15 19:56:22 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat2.hpp"
#include "AForm.hpp"
#include "messages.hpp"


// ---------- canonical methods ------------------------------------------------

// default constructor
Bureaucrat2::Bureaucrat2()
	: _name("Unnamed"),
	  _grade(kmingrade),
	  _emoji(setEmoji()) {
	message_bureau2_defa_ctor(*this);
}

// parameterized constructor
Bureaucrat2::Bureaucrat2(std::string name, int value)
	: _name(name),
	  _grade(validateGrade(value)),
	  _emoji(setEmoji()) {
  message_bureau2_para_ctor(*this);
}

// copy constructor
Bureaucrat2::Bureaucrat2(const Bureaucrat2& other)
    : _name(other._name),
	  _grade(other._grade),
	  _emoji(setEmoji()) {
  message_bureau2_copy_ctor(*this);
}

// assignment operator overload
Bureaucrat2& Bureaucrat2::operator=(const Bureaucrat2& other) {
	if (this != &other) {
		_grade = other._grade;
    	_emoji = setEmoji();
	}
	message_bureau2_assg_oper(*this);
	return *this;
}

// destructor
Bureaucrat2::~Bureaucrat2() {
	message_bureau2_deft_dtor(*this);
}


// ---------- other methods ----------------------------------------------------

const int& Bureaucrat2::getGrade() const {
	return _grade;
}

const std::string& Bureaucrat2::getName() const {
	return _name;
}

const std::string& Bureaucrat2::getEmoji() const {
	return _emoji;
}

void Bureaucrat2::incrementGrade() {
	int new_grade = _grade - 1;
	_grade = validateGrade(new_grade);
}

void Bureaucrat2::decrementGrade() {
	int new_grade = _grade + 1;
	_grade = validateGrade(new_grade);
}

void Bureaucrat2::incrementGrade(const int& increment) {
	int new_grade = _grade - increment;
	_grade = validateGrade(new_grade);
}

void Bureaucrat2::decrementGrade(const int& decrement) {
	int new_grade = _grade + decrement;
	_grade = validateGrade(new_grade);
}

int& Bureaucrat2::validateGrade(int& value) const {
	if (value < kmaxgrade)
		throw GradeTooHighException();
	if (value > kmingrade)
		throw GradeTooLowException();
	return (value);
}

void Bureaucrat2::signForm(AForm& f)
{
	try {
		f.beSigned(*this);
	}
	catch (AForm::GradeTooLowException &e) {
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

void Bureaucrat2::executeForm(AForm const &form) const {
	try {
		std::cout << "debug1\n";		
		form.execute(*this);
		std::cout << getName()
				  << getEmoji()
				  << " executed "
				  << form.getName()
				  << std::endl;
	}
	catch (std::exception &e) {
		std::cout << getName()
				  << getEmoji()
				  << " can't execute "
				  << form.getName()
				  << ": "
				  << e.what()
  				  << std::endl;
	}
}

// ---------- exceptions -------------------------------------------------------

const char *Bureaucrat2::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat2::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}


// ---------- stream operator overload -----------------------------------------

std::ostream& operator<<(std::ostream& os, const Bureaucrat2& b)
{
	os	<< b.getName()
		<< b.getEmoji()
		<< ", bureaucrat2 grade "
		<< b.getGrade()
		<< std::endl;
	return os;
}


// ---------- random emoji generator -------------------------------------------

std::string Bureaucrat2::setEmoji(void)
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
