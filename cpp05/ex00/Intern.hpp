/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:26:23 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/19 01:59:43 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <exception>
# include <string>

class AForm;

class Intern
{
    public:
		// canonical
		Intern();									// default constructor
        ~Intern();									// destructor
        Intern(const Intern& other);				// copy constructor
        Intern &operator=(const Intern &other);		// assignment operator

		// other
		AForm *makeForm(const std::string& name, const std::string& target);

		// exceptions
		class InvalidFormException : public std::exception {
		 	public: const char *what() const throw(); };
};


// the makeForm() function. This function
// takes two strings as parameters: the first one represents the name of a form, and the
// second one represents the target of the form. It returns a pointer to a AForm object
// (corresponding to the form name passed as a parameter), with its target initialized to
// the second parameter.


#endif
