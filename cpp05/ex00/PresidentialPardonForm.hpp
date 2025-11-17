/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:26:23 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/16 18:04:57 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include <exception>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:

    public:
		// canonical
		PresidentialPardonForm();											   // default constructor
		PresidentialPardonForm(std::string& target);						   // paramet constructor
        ~PresidentialPardonForm();											   // destructor
        PresidentialPardonForm(const PresidentialPardonForm& other);		   // copy constructor
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);// assignment operator
				
		void action() const;

		// constants
		static const int k_ppf_signgrade = 25;
		static const int k_ppf_execgrade = 5;
};

#endif
