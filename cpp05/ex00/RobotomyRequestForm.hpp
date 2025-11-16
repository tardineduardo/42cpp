/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:26:23 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/16 18:06:31 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <exception>
# include <string>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:

    public:
		// canonical
		RobotomyRequestForm();											 // default constructor
        ~RobotomyRequestForm();											 // destructor
        RobotomyRequestForm(const RobotomyRequestForm& other);			 // copy constructor
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);// assignment operator

		// other
		void action(std::string target) const;
	
		// constants
		static const int k_rrf_signgrade = 72;
		static const int k_rrf_execgrade = 45;		
};

#endif
