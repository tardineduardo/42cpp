/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:13:57 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/28 19:07:59 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static e_type			is_pseudo_literal(const std::string& input);
static e_type			is_char(const std::string& input);
static e_type			is_int(const std::string& input);
static e_type			is_float(const std::string& input);
static e_type			is_double(const std::string& input);
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
	e_type type = ScalarConverter::getType(trimmed);

	if (type == PSD_LITERAL)
		ScalarConverter::convert_literal(trimmed, type);
	else if (type == NONDISP_CHAR || type == PRINTBL_CHAR)
		ScalarConverter::convert_char(trimmed, type);
	else if (type == INT || type == INT_OVERF)
		ScalarConverter::convert_int(trimmed, type);
	else if (type == FLOAT)
		ScalarConverter::convert_float(trimmed, type);
	else if (type == DOUBLE)
		ScalarConverter::convert_double(trimmed, type);
}

e_type ScalarConverter::getType(const std::string& input)
{
	e_type type = ERROR;

	if (!type) { type = is_pseudo_literal(input); }
	if (!type) { type = is_char(input);}
	if (!type) { type = is_int(input);}
	if (!type) { type = is_float(input);}
	if (!type) { type = is_double(input);}
	if (!type) { type = INVALID; }
	
	return type;
}

// ---------- exceptions -------------------------------------------------------

const char *ScalarConverter::ScalarConverterException::what() const throw() {
	return "generic ScalarConverter error";
}


// ---------- static methods ---------------------------------------------------

void ScalarConverter::convert_char(const std::string& input, e_type type)
{
	//TODO
}
void ScalarConverter::convert_int(const std::string& input, e_type type)
{
	//TODO
}
void ScalarConverter::convert_float(const std::string& input, e_type type)
{
	//TODO
}
void ScalarConverter::convert_double(const std::string& input, e_type type)
{
	//TODO
}


// ---------- functions - validations ------------------------------------------

static e_type is_pseudo_literal(const std::string& input)
{
	static const std::string p_literal[] = {
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	static size_t size = sizeof(p_literal)/sizeof(p_literal[0]);

	for(size_t a = 0; a < size; a++)
		if (p_literal[a] == input)
			return PSD_LITERAL;
	return ERROR;
}

static e_type is_char(const std::string& input)
{
    if(input.size() != 1)
        return ERROR;
		
    unsigned char c = static_cast<unsigned char>(input[0]);

    if(c > 127)
		return ERROR;
	if (std::isdigit(c))
    	return ERROR;
	if (!std::isprint(c))
		return NONDISP_CHAR;
	return PRINTBL_CHAR;
}

static e_type is_int(const std::string& input)
{
	if (input.empty())
    	return ERROR;

	char *end = NULL;
	const char *str = input.c_str();
	long value = std::strtol(str, &end, 10);

	if(end == str)
		return ERROR;

	if(end != NULL)
			


	for(int a = 0; a < input.length(); a++)
		if(!isdigit(input[a]))
			return false;
	int value = std::atoll(input.c_str());
	return true;
}

//input was trimmed already - trailind spaces at end and start
static e_type is_float(const std::string& input)
{
	if(input.empty())
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

static e_type is_double(const std::string& input)
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
		if(!std::isspace(input[a])) trimmed += input[a];
	

	return trimmed;
}






