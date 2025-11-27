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

static bool		is_pseudo_literal(const std::string& input);
static bool		is_char(const std::string& input);
static bool		is_int(const std::string& input);
static bool		is_float(const std::string& input);
static bool		is_double(const std::string& input);


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

	char *type = ScalarConverter::getType(input);

	if (type == "pseudo_literal")
		ScalarConverter::convert_literal(input, type);
	else if (type == "char")
		ScalarConverter::convert_char(input, type);
	else if (type == "int")
		ScalarConverter::convert_int(input, type);
	else if (type == "float")
		ScalarConverter::convert_float(input, type);
	else if (type == "double")
		ScalarConverter::convert_double(input, type);
}


char* ScalarConverter::getType(const std::string& input)
{
	char *type;

	if (is_pseudo_literal(input))		{ type = "pseudo_literal"; }
	else if (is_char(input))	{ type = "char"; }
	else if (is_int(input))		{ type = "int"; }
	else if (is_float(input))	{ type = "float"; }
	else if (is_double(input))	{ type = "double"; }
	else { type = "invalid"; }
	
	return type;
}






// ---------- exceptions -------------------------------------------------------

const char *ScalarConverter::ScalarConverterException::what() const throw() {
	return "generic ScalarConverter error";
}




// -----------------------------------------------------------------------------

static bool is_pseudo_literal(const std::string& input)
{
	std::string p_literal[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for(int a = 0; a < 6; a++)
	{
		if (p_literal[a] == input)
			return true;
		a++;
	}
	return false;
}

static bool is_char(const std::string& input)
{
 	char c;	
 	if (input.length() == 1 && sizeof(input[0]) == sizeof(char)) {
 		c = static_cast<char>(input[0]);
 		}
}

static bool is_int(const std::string& input) {}

static bool is_float(const std::string& input) {}

static bool is_double(const std::string& input) {}







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


