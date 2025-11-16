/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat2.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:20 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/15 19:56:15 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT2_HPP
# define BUREAUCRAT2_HPP
# include <iostream>
# include <exception>
# include <string>
# include <cstdlib>		// for random emoji
# include <ctime>		// for random emoji

class AForm;

class Bureaucrat2
{
	protected:
		const std::string	_name;
		int					_grade;
		std::string			_emoji;

	public:
		// canonical
		Bureaucrat2();									  // default constructor
        ~Bureaucrat2();									  // destructor
		Bureaucrat2(std::string name, int grade);		  // parameterized ctor
        Bureaucrat2(const Bureaucrat2& other);			  // copy constructor
        Bureaucrat2 &operator=(const Bureaucrat2 &other); // assignment operator

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
std::ostream& operator<<(std::ostream& os, const Bureaucrat2& b);

#endif
