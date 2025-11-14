/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:27 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/13 21:12:50 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "messages.hpp"

// parameterized constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	_grade = setGrade(grade);
	_emoji = setEmoji();
	m_bureau_deft_ctor(*this);
	return;
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name),
												  _grade(other._grade)
{
	m_bureau_copy_ctor(*this);
	return;
}

// assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) 
{
	m_bureau_assg_ctor(*this);
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

// destructor
Bureaucrat::~Bureaucrat(void)
{
	m_bureau_deft_dtor(*this);
	return ;
}

//------------------------------------------------------------------------------



const std::string& Bureaucrat::getName()
{
	return _name;
}

const std::string& Bureaucrat::getEmoji()
{
	return _emoji;
}

const int& Bureaucrat::getGrade()
{
	return _grade;
}


int Bureaucrat::setGrade(int value)
{
	if (value < 1)
		throw GradeTooHighException();
	if (value > 150)
		throw GradeTooLowException();
	_grade = value;
	return (_grade);
}


void Bureaucrat::incrementGrade(const int& increment)
{
	_grade -= increment;
}

void Bureaucrat::decrementGrade(const int& decrement)
{
	_grade += decrement;
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

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
