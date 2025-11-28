/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:13:57 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/27 21:02:17 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool			is_pseudo_literal(const std::string& input);
static bool			is_char(const std::string& input);
static bool			is_int(const std::string& input);
static bool			is_float(const std::string& input);
static bool			is_double(const std::string& input);
static std::string	trim(std::string input);



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

	std::string trimmed = trim(input);
	std::string type = ScalarConverter::getType(trimmed);

	if (type == "pseudo_literal")
		ScalarConverter::convert_literal(trimmed, type);
	else if (type == "char")
		ScalarConverter::convert_char(trimmed, type);
	else if (type == "int")
		ScalarConverter::convert_int(trimmed, type);
	else if (type == "float")
		ScalarConverter::convert_float(trimmed, type);
	else if (type == "double")
		ScalarConverter::convert_double(trimmed, type);
}

std::string ScalarConverter::getType(const std::string& input)
{
	std::string type;

	if (is_pseudo_literal(input))	{ type = "pseudo_literal"; }
	else if (is_char(input))		{ type = "char"; }
	else if (is_int(input))			{ type = "int"; }
	else if (is_float(input))		{ type = "float"; }
	else if (is_double(input))		{ type = "double"; }
	else 							{ type = "invalid"; }
	
	return type;
}

// ---------- exceptions -------------------------------------------------------

const char *ScalarConverter::ScalarConverterException::what() const throw() {
	return "generic ScalarConverter error";
}


// ---------- static methods ---------------------------------------------------

void ScalarConverter::convert_char(const std::string& input, std::string& type)
{
	//TODO
}
void ScalarConverter::convert_int(const std::string& input, std::string& type)
{
	//TODO
}
void ScalarConverter::convert_float(const std::string& input, std::string& type)
{
	//TODO
}
void ScalarConverter::convert_double(const std::string& input, std::string& type)
{
	//TODO
}


// ---------- functions - validations ------------------------------------------

static bool is_pseudo_literal(const std::string& input)
{
	std::string p_literal[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for(int a = 0; a < sizeof(p_literal)/sizeof(p_literal[0]); a++)
	{
		if (p_literal[a] == input)
			return true;
		a++;
	}
	return false;
}

static bool is_char(const std::string& input)
{
 	if (input.length() == 1 && sizeof(input) == sizeof(char)) {
 		char c = static_cast<char>(input[0]);
		if(c >= 0 && c <= 127)
			return true;
	}
	return false;
}

static bool is_int(const std::string& input) {
	int value;
	for(int a = 0; a < input.length(); a++)
		if(!isdigit(input[a]))
			return false;
	value = std::atoll(input.c_str());
	return true;
}

//input was trimmed already - trailind spaces at end and start
static bool is_float(const std::string& input)
{
	if (input.empty())
		return false;

	if(input[input.length() - 1] != 'f')
		return false;

	char *end = NULL;
	const char *cstr = input.c_str();
	std::strtod(cstr, &end);

	if (cstr == end)
    	return false;

    if (end[0] == 'f' && end[1] == '\0')
		return true;
	
	return false;	
}

static bool is_double(const std::string& input)
{
	if (input.empty())
		return false;

	char *end = NULL;
	const char *cstr = input.c_str();
	std::strtod(cstr, &end);

	if (cstr == end)
    	return false;

    if (end[0] == '\0')
		return true;
	
	return false;	
}


// ---------- functions - trim -------------------------------------------------

static std::string trim(std::string input)
{
	std::string trimmed = "";

	for(int a = 0; a < input.length(); a++)
	{
		if(!std::isspace(input[a]))
		trimmed += input[a];
	}
	
	return trimmed;
}






