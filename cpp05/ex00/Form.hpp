/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:20 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/14 23:47:23 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <exception>
# include <string>
# include <cstdlib>		// for random emoji
# include <ctime>		// for random emoji

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_k_name;
		const int			_k_sign_grade;
		const int			_k_exec_grade;
		bool				_signed;
		std::string			_emoji;

    public:
		// canonical
		Form();											  // default constructor
        ~Form();										  // destructor
		Form(std::string name, int s_grade, int e_grade); // parameterized ctor
        Form(const Form& other);						  // copy constructor
        Form &operator=(const Form &other);				  // assignment operator

		// other
		const int&				getSignGrade() const;
		const int&				getExecGrade() const;
		const std::string&		getName() const;
		bool					getSigned() const;
		void					beSigned(Bureaucrat& b);
		int&					validateSignGrade(int& value) const;
		int&					validateExecGrade(int& value) const;

		// exceptions
		class GradeTooHighException : public std::exception {
			const char *what() const throw(); };

		class GradeTooLowException : public std::exception {
			const char *what() const throw(); };

		// extra
		const std::string& getEmoji() const;
		std::string setEmoji(void);
	
};

// stream operator overload
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
