/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:20 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/14 23:47:23 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <exception>
# include <string>
# include <cstdlib>		// for random emoji
# include <ctime>		// for random emoji

class Bureaucrat2;

class AForm
{
	private:
		const std::string	_k_name;
		const int			_k_sign_grade;
		const int			_k_exec_grade;
		bool				_signed;
		std::string			_target;
		std::string			_emoji;

    public:
		// canonical
		AForm();										  // default constructor
        ~AForm();										  // destructor
		AForm(std::string name, int s_grade, int e_grade);// parameterized ctor
        AForm(const AForm& other);						  // copy constructor
        AForm &operator=(const AForm &other);			  // assignment operator

		// other
		const int&				getSignGrade() const;
		const int&				getExecGrade() const;
		const std::string&		getName() const;
		const std::string&		getTarget() const;	
		bool					getSigned() const;
		void					setTarget(const std::string& target);
		void					beSigned(Bureaucrat2& b);
		int&					validateSignGrade(int& value) const;
		int&					validateExecGrade(int& value) const;
		void					execute(Bureaucrat2 const &executor) const;

		// virtuals
		virtual void			action(std::string target) const = 0;

		// exceptions
		class GradeTooHighException : public std::exception {
			public: const char *what() const throw(); };

		class GradeTooLowException : public std::exception {
			public: const char *what() const throw(); };

		class FormNotSignedException : public std::exception {
			public: const char *what() const throw(); };

		class NoTargetException : public std::exception {
			public: const char *what() const throw(); };

		// extra
		const std::string& getEmoji() const;
		std::string setEmoji(void);
	
};

// stream operator overload
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
