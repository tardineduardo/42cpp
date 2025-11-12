/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:27 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/11 01:19:46 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void) : _name("Unknown")
{
	_grade = 1;
	std::cout << "Default constructor called" << std::endl;
	return;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name),
												  _grade(other._grade)
{
	std::cout << "Copy constructor called" << std::endl;
	return;
}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) 
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

//------------------------------------------------------------------------------

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	_grade = grade;
	std::cout << "Default constructor called" << std::endl;
	return;
}

const std::string& Bureaucrat::getName()
{
	return _name;
}

const int& Bureaucrat::getGrade()
{
	return _grade;
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


}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{


}


