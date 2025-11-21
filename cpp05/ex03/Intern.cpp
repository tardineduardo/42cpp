/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:30:31 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/20 21:04:15 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "messages.hpp"

static AForm*			createShrubbery(const std::string &target);
static AForm*			createRobotomy(const std::string &target);
static AForm*			createPardon(const std::string &target);
static FormEntry*		findFormEntry(const std::string &name);


// ---------- canonical methods ------------------------------------------------

// default constructor
Intern::Intern() {
	message_intrn_defa_ctor();
}

// copy constructor
Intern::Intern(const Intern& other) {
	(void)other;
  message_intrn_copy_ctor();
}

// assignment operator overload
Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {}
	message_intrn_assg_oper();
	return *this;
}

// destructor
Intern::~Intern() {
	message_intrn_deft_dtor();
}


// ---------- other methods-----------------------------------------------------

AForm *Intern::makeForm(const std::string &name,
                        const std::string &target)
{
  const FormEntry *entry = findFormEntry(name);
  if (!entry)
	return NULL;

  std::cout << "Intern creates " << name << std::endl;
  return entry->maker(target);
}


// ---------- find form --------------------------------------------------------

static FormEntry *findFormEntry(const std::string &name)
{
	static FormEntry kTable[] =
	{
		{ "shrubbery creation",		&createShrubbery },
		{ "robotomy request",		&createRobotomy },
		{ "presidential pardon",	&createPardon }
	};
	const int kSize = sizeof(kTable) / sizeof(kTable[0]);

	for (int i = 0; i < kSize; ++i)
	{
		if (name == kTable[i].name)
			return &kTable[i];
	}
	return NULL;
}


// ---------- makers --------------------------------------------------------

static AForm *createShrubbery(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target) {
  return new RobotomyRequestForm(target);
}

static AForm *createPardon(const std::string &target) {
  return new PresidentialPardonForm(target);
}
