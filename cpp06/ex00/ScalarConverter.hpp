/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:13:59 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/27 20:58:32 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <exception> // Remove if no execptions are used
# include <string>
# include <cstdlib>
# include <cctype>
# include <cstdlib>

class ScalarConverter
{
	private:
		// canonical
		ScalarConverter();											// default constructor
        ~ScalarConverter();											// destructor
        ScalarConverter(const ScalarConverter& other);				// copy constructor
        ScalarConverter &operator=(const ScalarConverter &other);	// assignment operator


		static void		convert_literal(const std::string& str, std::string& type);
		static void		convert_char(const std::string& str, std::string& type);
		static void		convert_int(const std::string& str, std::string& type);
		static void		convert_float(const std::string& str, std::string& type);
		static void		convert_double(const std::string& str, std::string& type);
		
		static std::string	getType(const std::string& str);


	public:
		// other
		static void ScalarConverter::convert(std::string input);
		
		// exceptions
		class ScalarConverterException : public std::exception {
			public: const char *what() const throw(); };
};

#endif
