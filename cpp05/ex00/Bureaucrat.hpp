/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:20 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/11 01:19:36 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
	protected:
 
		const std::string	_name;
		int					_grade;
		static const int	_maxgrade = 1;
		static const int	_mingrade = 150;

    public:
		//canonicals
        Bureaucrat(void);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

		//constructor
		Bureaucrat(std::string name, int grade);

		const std::string&		getName();
		const int&				getGrade();
		void					incrementGrade(const int increment);
		void					decrementGrade(const int decrement);
};

#endif

//• A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade). // Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception: either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
