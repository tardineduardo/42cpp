/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:58:20 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/13 20:27:34 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include <string>
# include <cstdlib>
# include <ctime>

std::string setEmoji(void);

class Bureaucrat
{
	protected:
		const std::string	_name;
		std::string			_emoji;
		int					_grade;
		static const int	_maxgrade = 1;
		static const int	_mingrade = 150;

    public:
		//canonicals (only parameterized ctor)
		Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

		const int&				getGrade();
		const std::string&		getName();
		const std::string&		getEmoji();
		int						setGrade(int value);
		void					incrementGrade(const int& increment);
		void					decrementGrade(const int& decrement);

		//exceptions
		class GradeTooHighException : public std::exception {
			const char *what() const throw(); };

		class GradeTooLowException : public std::exception {
			const char *what() const throw(); };

};

#endif
