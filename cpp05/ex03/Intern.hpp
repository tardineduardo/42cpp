/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:16:17 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/22 16:55:43 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <exception> // Remove if no execptions are used
# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		// canonical
		Intern();									// default constructor
        ~Intern();									// destructor
        Intern(const Intern& other);				// copy constructor
        Intern &operator=(const Intern &other); 	// assignment operator

		// other
		AForm *makeForm(const std::string form, std::string target) const;

		struct intern_tasks {
			std::string		request;
			AForm*			(*action)(std::string& target); };

		// exceptions
		class InternException : public std::exception {
			public: const char *what() const throw(); };

};

#endif
