/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:26:23 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/16 20:02:56 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <exception>
# include <string>
# include <fstream>
# include "AForm.hpp"

std::string getTree1();

class ShrubberyCreationForm : public AForm
{
	private:

    public:
		// canonical
		ShrubberyCreationForm();											 // default constructor
        ~ShrubberyCreationForm();											 // destructor
        ShrubberyCreationForm(const ShrubberyCreationForm& other);			 // copy constructor
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);// assignment operator

		void action(std::string target) const;

		// constants
		static const int k_scf_signgrade = 145;
		static const int k_scf_execgrade = 137;		
};

#endif
