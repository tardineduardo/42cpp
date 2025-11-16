/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:26:23 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/16 14:59:07 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <exception>
# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		void actionDrawTrees(std::string& target) const;

    public:
		// canonical
		ShrubberyCreationForm();											 // default constructor
        ~ShrubberyCreationForm();											 // destructor
        ShrubberyCreationForm(const ShrubberyCreationForm& other);			 // copy constructor
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);// assignment operator

		// other
		void execute(Bureaucrat2 const &executor) const;
	
		// constants
		static const int k_scf_signgrade = 145;
		static const int k_scf_execgrade = 137;		
};

#endif
