/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:20 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/20 23:19:09 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include <string>
# include <cstdlib>		// for random emoji
# include <ctime>		// for random emoji

class AForm;

class Bureaucrat
{
	protected:
		const std::string	_name;
		int					_grade;
		std::string			_emoji;

	public:
		// canonical
		Bureaucrat();									  // default constructor
        ~Bureaucrat();									  // destructor
		Bureaucrat(std::string name, int grade);		  // parameterized ctor
        Bureaucrat(const Bureaucrat& other);			  // copy constructor
        Bureaucrat &operator=(const Bureaucrat &other); // assignment operator

		// other
		const std::string&		getName() const;
		const int&				getGrade() const;
		void					incrementGrade();
		void					decrementGrade();
		void					incrementGrade(const int& increment);
		void					decrementGrade(const int& decrement);
		int&					validateGrade(int &value) const;
		void					signForm(AForm& f);
		void					executeForm(AForm const &form) const;

		// constants	
		static const int	kmaxgrade = 1;
		static const int	kmingrade = 150;

		// exceptions
		class GradeTooHighException : public std::exception {
			public: const char *what() const throw(); };

		class GradeTooLowException : public std::exception {
			public: const char *what() const throw(); };

		// extra
		const std::string& getEmoji() const;
		std::string setEmoji(void);
};

// ostream operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
