/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:13:57 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/24 21:09:19 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ---------- canonical methods (PRIVATE!) -------------------------------------

// default constructor
ScalarConverter::ScalarConverter() {}

// copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other) {}

// assignment operator overload
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other) {}
	return *this;
}

// destructor
ScalarConverter::~ScalarConverter() {}





// ---------- other methods ----------------------------------------------------

void ScalarConverter::convert(std::string input) {
	ScalarConverter::output out;

	out.char_out = ScalarConverter::char_convert(input);


	if (isint(input)) {

	}
	else if (isint(input)) {

	}
	else if (isint(input)) {

	}


}


// ---------- exceptions -------------------------------------------------------

const char *ScalarConverter::ScalarConverterException::what() const throw() {
	return "generic ScalarConverter error";
}

// ---------- stream operator overload -----------------------------------------

// std::ostream& operator<<(std::ostream& os, const ScalarConverter& b)
// {
// 	os	<< [DO STUFF]
// 	return os;
// }


// -----------------------------------------------------------------------------

void ScalarConverter::is_literal(const std::string& input) {

}


void ScalarConverter::is_char(const std::string& input) {
	char c;
	
	if (input.length() == 1 && sizeof(input[0]) == sizeof(char)) {
		c = static_cast<char>(input[0]);
			if 
		}

}


void ScalarConverter::is_int(const std::string& input) {}
void ScalarConverter::is_float(const std::string& input) {}
void ScalarConverter::is_double(const std::string& input) {}

void ScalarConverter::convert_int(const std::string& input, char *type) {}
void ScalarConverter::convert_float(const std::string& input, char *type) {}
void ScalarConverter::convert_double(const std::string& input, char *type) {}
void ScalarConverter::convert_char(const std::string& input, char *type) {}


// Write a class ScalarConverter that will contain only one static method "convert"
// that will take as a parameter a string representation of a C++ literal in its most common
// form and output its value in the following series of scalar types:
// • char
// • int
// • float
// • double
// As this class doesn’t need to store anything at all, it must not be instantiable by users.
// Except for char parameters, only the decimal notation will be used.
// Examples of char literals: ’c’, ’a’, ...
// To make things simple, please note that non-displayable characters shouldn’t be used as
// inputs. If a conversion to char is not displayable, print an informative message.
// Examples of int literals: 0, -42, 42...
// Examples of float literals: 0.0f, -4.2f, 4.2f...
// You have to handle these pseudo-literals as well (you know, for science): -inff, +inff,
// and nanf.
// 9C++ - Module 06
// C++ casts
// Examples of double literals: 0.0, -4.2, 4.2...
// You have to handle these pseudo-literals as well (you know, for fun): -inf, +inf, and
// nan.


"-inff", "+inff", "nanf", "-inf", "+inf", "nan"