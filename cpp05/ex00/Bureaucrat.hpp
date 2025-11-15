/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:20 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/14 23:47:23 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include <string>
# include <cstdlib>		// for random emoji
# include <ctime>		// for random emoji

std::string setEmoji(void);

class Bureaucrat
{
	protected:
		const std::string	_name;
		int					_grade;
		std::string			_emoji;
		static const int	_maxgrade = 1;
		static const int	_mingrade = 150;

    public:
		// canonical
		Bureaucrat();									  // default constructor
        ~Bureaucrat();									  // destructor
		Bureaucrat(std::string name, int grade);		  // parameterized ctor
        Bureaucrat(const Bureaucrat& other);			  // copy constructor
        Bureaucrat &operator=(const Bureaucrat &other);	  // assignment operator

		// other
		const int&				getGrade() const;
		const std::string&		getName() const;
		const std::string&		getEmoji() const;
		int						setGrade(int value);
		void					incrementGrade();
		void					decrementGrade();
		void					incrementGrade(const int& increment);
		void					decrementGrade(const int& decrement);

		//exceptions
		class GradeTooHighException : public std::exception {
			const char *what() const throw(); };

		class GradeTooLowException : public std::exception {
			const char *what() const throw(); };
};

// stream operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& x);

#endif
