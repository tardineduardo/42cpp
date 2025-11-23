/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:13:59 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/23 18:18:30 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <exception> // Remove if no execptions are used
# include <string>
# include <cstdlib>
# include <cctype>

class ScalarConverter
{
	private:
		// canonical
		ScalarConverter();											// default constructor
        ~ScalarConverter();											// destructor
        ScalarConverter(const ScalarConverter& other);				// copy constructor
        ScalarConverter &operator=(const ScalarConverter &other);	// assignment operator
		
		void charConvert(const std::string& input);
		void intConvert(const std::string& input);
		void floatConvert(const std::string& input);
		void doubleConvert(const std::string& input);


	public:
		// other
		static void ScalarConverter::convert(std::string input);
		
		// exceptions
		class ScalarConverterException : public std::exception {
			public: const char *what() const throw(); };

};

#endif
