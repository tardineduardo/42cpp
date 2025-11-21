/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:26:23 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/20 21:04:48 by eduribei         ###   ########.fr       */
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
};

struct FormEntry
{
    const char	*name;
    AForm*		(*maker)(const std::string &);
};

#endif
