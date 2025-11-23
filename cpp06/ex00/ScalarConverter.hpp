/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:13:59 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/23 17:31:27 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <exception> // Remove if no execptions are used
# include <string>

class ScalarConverter
{
	private:
		struct output {
			char *char_out;
			char *int_out;
			char *float_out;
			char *double_out; //set values
		};

		char *char_convert(const std::string& input);
		char *int_convert(const std::string& input);
		char *float_convert(const std::string& input);
		char *double_convert(const std::string& input);


	public:
		// canonical
		ScalarConverter();											// default constructor
        ~ScalarConverter();											// destructor
        ScalarConverter(const ScalarConverter& other);				// copy constructor
        ScalarConverter &operator=(const ScalarConverter &other);	// assignment operator

		// other
		static void ScalarConverter::convert(std::string input);
		
		// constants
			//static const int	kvalue = 1000;

		// operators
			//[returntype] operator[symbol]([params])

		// exceptions
		class ScalarConverterException : public std::exception {
			public: const char *what() const throw(); };

};

// ostream operator overload
// std::ostream& operator<<(std::ostream& os, const ScalarConverter& b);

#endif
