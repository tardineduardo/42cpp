/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:13:59 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/24 21:08:45 by eduribei         ###   ########.fr       */
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

		static bool		is_literal(const std::string& input);
		static bool		is_char(const std::string& input);
		static bool		is_int(const std::string& input);
		static bool		is_float(const std::string& input);
		static bool		is_double(const std::string& input);

		static char		*getType(const std::string input);

		static void	convert_char(const std::string& input, char *type);
		static void	convert_int(const std::string& input, char *type);
		static void	convert_float(const std::string& input, char *type);
		static void	convert_double(const std::string& input, char *type);

	public:
		// other
		static void ScalarConverter::convert(std::string input);
		
		// exceptions
		class ScalarConverterException : public std::exception {
			public: const char *what() const throw(); };
};

#endif
