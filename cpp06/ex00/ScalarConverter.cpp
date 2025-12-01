/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:13:57 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/29 23:09:32 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static std::string	trim(std::string input);
static t_type getType(const std::string& input);

static t_type		is_pseudo_literal(const std::string& input);
static t_type		is_char(const std::string& input);
static t_type		is_int(const std::string& input);
static t_type		is_float(const std::string& input);
static t_type		is_double(const std::string& input);

static void			convert_literal(const std::string& input, t_type type);
static void			convert_char(const std::string& input, t_type type);
static void			convert_int(const std::string& input, t_type type);
static void			convert_float(const std::string& input, t_type type);
static void			convert_double(const std::string& input, t_type type);


// ---------- canonical methods (PRIVATE!) -------------------------------------

// default constructor
ScalarConverter::ScalarConverter() {}

// copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

// assignment operator overload
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other) {}
	return *this;
}

// destructor
ScalarConverter::~ScalarConverter() {}


// ---------- other methods ----------------------------------------------------

static t_type getType(const std::string& input)
{
	t_type type;
	type = CONTINUE;

	if (!type) { type = is_pseudo_literal(input); }
	if (!type) { type = is_char(input); }
	if (!type) { type = is_int(input); }
	if (!type) { type = is_float(input); }
	if (!type) { type = is_double(input); }
	if (!type) { type = INVALID; }
	
	return type;
}


void ScalarConverter::convert(std::string input) {

	std::string trimmed = trim(input);
	t_type type = getType(trimmed);

	if (type == PSEUDO_LITERAL_F || type == PSEUDO_LITERAL_D)
		convert_literal(trimmed, type);
	else if (type == NONDISP_CHAR || type == PRINTBL_CHAR)
		convert_char(trimmed, type);
	else if (type == INT || type == INT_OVERF || type == INT_UNDRF)
		convert_int(trimmed, type);
	else if (type == FLOAT || type == FLOAT_OVERF || type == FLOAT_UNDRF)
		convert_float(trimmed, type);
	else if (type == DOUBLE || type == DOUBLE_OVERF || type == DOUBLE_UNDRF)
		convert_double(trimmed, type);
	else
		std::cout << "invalid input\n";

	
}


// ---------- static methods ---------------------------------------------------

static void	convert_literal(const std::string& input, t_type type)
{
	(void)type;
	std::string inputlow;
	for(size_t a = 0; a < input.size(); a++)
		inputlow += std::tolower(input[a]);

	std::cout << "char:\timpossible\n"; 
	std::cout << "int:\timpossible\n";		

	if(inputlow == "inff")
		std::cout << "float:\t" << "inff";
	if(inputlow == "+inff")
		std::cout << "float:\t" << "+inff";
	if(inputlow == "-inff")
		std::cout << "float:\t" << "-inff";

	if(inputlow == "nanf")
		std::cout << "float:\t" << "nanf";
	if(inputlow == "+nanf")
		std::cout << "float:\t" << "+nanf";
	if(inputlow == "-nanf")
		std::cout << "float:\t" << "-nanf";

	char *end = NULL;
	const char *str = inputlow.c_str();
	errno = 0;
	float valuef = std::strtod(str, &end);
	std::cout << "\t\t(" << valuef << ')' << std::endl;

	if(inputlow == "inff")
		std::cout << "double:\t" << "inf";
	else if(inputlow == "+inff")
		std::cout << "double:\t" << "+inf";
	else if(inputlow == "-inff")
		std::cout << "double:\t" << "-inf";

	else if(inputlow == "nanf")
		std::cout << "double:\t" << "nan";
	else if(inputlow == "+nanf")
		std::cout << "double:\t" << "+nan";
	else if(inputlow == "-nanf")
		std::cout << "double:\t" << "-nan";

	double valued = std::strtod(str, &end);
	std::cout << "\t\t(" << valued << ')' << std::endl;
}

static void	convert_char(const std::string& input, t_type type)
{
	 const char *c = input.c_str();
	
	if(type == PRINTBL_CHAR)
		std::cout << "char:\t\'" << *c << '\'' << std::endl;
	else if(type == NONDISP_CHAR)
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int:\t" << static_cast<int>(*c) << std::endl;
	std::cout << "float:\t" << static_cast<float>(*c) << ".0f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(*c) << ".0" << std::endl;	
}

static void	convert_int(const std::string& input, t_type type)
{
	const char *str = input.c_str();

	errno = 0;
	char *end = NULL;
	long value_long = std::strtol(str, &end, 10);
	int value_int = static_cast<int>(value_long);
	unsigned char c = static_cast<unsigned char>(value_int);	

	if(value_int < 0 || value_int > 127 || type == INT_OVERF || type == INT_UNDRF)
		std::cout << "char:\t" << "impossible" << std::endl;
	else if(!std::isprint(c))
		std::cout << "char:\t" << "non displayable" << std::endl;
	else
		std::cout << "char:\t\'" << c << '\'' << std::endl;


	if(type == INT)
		std::cout << "int:\t" << value_int << std::endl;	
	else if(type == INT_OVERF)
		std::cout << "int:\t" << "overflow" << std::endl;
	else if(type == INT_UNDRF)
		std::cout << "int:\t" << "underflow" << std::endl;


	end = NULL;
	errno = 0;
	double value_double = std::strtod(str, &end);
	double abs_val = std::fabs(value_double);
	double f_max   = std::numeric_limits<float>::max();
	double f_min   = std::numeric_limits<float>::denorm_min();
	// float value_float = static_cast<float>(value_double);

	if (abs_val == 0.0 && errno == 0)
		std::cout << "float:\t" << value_int << ".0f" << std::endl;	
	else if (abs_val > f_max)
		std::cout << "float:\t" << "overflow" << std::endl;
	else if (abs_val < f_min)
		std::cout << "float:\t" << "underflow" << std::endl;
	else
		std::cout << "float:\t" << input << ".0f" << std::endl;	
		

	if (abs_val == 0.0 && errno == 0)
		std::cout << "double:\t" << value_int << ".0" << std::endl;	
	else if (value_double == 0.0 && errno == ERANGE)
		std::cout << "double:\t" << "underflow" << std::endl;
	else if (errno == ERANGE && (value_double == HUGE_VAL || value_double == -HUGE_VAL))
		std::cout << "double:\t" << "overflow" << std::endl;
	else
		std::cout << "double:\t" << input << ".0" << std::endl;	
}

static void convert_float(const std::string& input, t_type type)
{
	const char *str = input.c_str();
	char *end = NULL;
	double value_double = std::strtod(str, &end);
//	float value_float = static_cast<float>(value_double);
	int value_int;
	unsigned char c;	

	//char
	if(value_double < std::numeric_limits<int>::min())
		std::cout << "int:\t" << "underflow" << std::endl;
	else if(value_double > std::numeric_limits<int>::max())
		std::cout << "int:\t" << "overflow" << std::endl;
	else {
		value_int = static_cast<int>(value_double);
    	c = static_cast<unsigned char>(value_int);

	    if(c > 127 || std::isdigit(c))
			std::cout << "char:\t" << "impossible" << std::endl;
		else if (!std::isprint(c))
			std::cout << "char:\t" << "non displayable" << std::endl;
		else
			std::cout << "char:\t\'" << c << '\'' << std::endl;
	}

	//int
	if(!std::isfinite(value_double))
		std::cout << "int:\t" << "impossible" << std::endl;
	else if(value_double < std::numeric_limits<int>::min())
		std::cout << "int:\t" << "underflow" << std::endl;
	else if(value_double > std::numeric_limits<int>::max())
		std::cout << "int:\t" << "overflow" << std::endl;
	else {
		int value_int = static_cast<int>(value_double);
		std::cout << "int:\t" << value_int << std::endl;}

	//float
	if(type == FLOAT_OVERF)
		std::cout << "float:\t" << "overflow" << std::endl;
	else if(type == FLOAT_UNDRF)
		std::cout << "float:\t" << "underflow" << std::endl;
	else
		std::cout << "float:\t" << input << std::endl;

	//double
	std::string dstr = input;
	dstr.erase(dstr.size() - 1);
	std::cout << "double:\t" << dstr << std::endl;

}


static void convert_double(const std::string& input, t_type type)
{
	int value_int;
	unsigned char c;	
	const char *str = input.c_str();
	char *end = NULL;

	double value_double = std::strtod(str, &end);

	//char
	if(value_double < std::numeric_limits<int>::min())
		std::cout << "int:\t" << "underflow" << std::endl;
	else if(value_double > std::numeric_limits<int>::max())
		std::cout << "int:\t" << "overflow" << std::endl;
	else {
		value_int = static_cast<int>(value_double);
    	c = static_cast<unsigned char>(value_int);
	    if(c > 127 || std::isdigit(c))
			std::cout << "char:\t" << "impossible" << std::endl;
		else if (!std::isprint(c))
			std::cout << "char:\t" << "non displayable" << std::endl;
		else
			std::cout << "char:\t\'" << c << '\'' << std::endl;
	}

	// int
	if (!std::isfinite(value_double))
		std::cout << "int:\t" << "impossible" << std::endl;
	else if (value_double < std::numeric_limits<int>::min())
		std::cout << "int:\t" << "underflow" << std::endl;
	else if (value_double > std::numeric_limits<int>::max())
		std::cout << "int:\t" << "overflow" << std::endl;
	else
	{
		int value_int = static_cast<int>(value_double);
		std::cout << "int:\t" << value_int << std::endl;
	}

	// float
	double abs_val = std::fabs(value_double);
	double f_max = std::numeric_limits<float>::max();
	double f_min = std::numeric_limits<float>::denorm_min();

	if (type == DOUBLE_OVERF)
		std::cout << "float:\t" << "overflow" << std::endl;
	else if (type == DOUBLE_UNDRF)
		std::cout << "float:\t" << "underflow" << std::endl;
	else if (!std::isfinite(value_double))
		std::cout << "float:\t" << "impossible" << std::endl;
	else if (abs_val > f_max)
		std::cout << "float:\t" << "overflow" << std::endl;
	else if (abs_val < f_min && abs_val != 0.0)
		std::cout << "float:\t" << "underflow" << std::endl;
	else
	{
		float value_float = static_cast<float>(value_double);
			(void)value_float;

		std::cout << "float:\t" << input << "f" << std::endl;
	}

	// double
	if (type == DOUBLE_OVERF)
		std::cout << "double:\t" << "overflow" << std::endl;
	else if (type == DOUBLE_UNDRF)
		std::cout << "double:\t" << "underflow" << std::endl;
	else
		std::cout << "double:\t" << input << std::endl;
}


// ---------- functions - validations ------------------------------------------

static t_type is_pseudo_literal(const std::string& input)
{
	std::string inputlow;
	for(size_t a = 0; a < input.size(); a++)
		inputlow += std::tolower(input[a]);

	static const std::string f_literal[] = {
		"-inff", "+inff", "nanf", "inff"};

	static const std::string d_literal[] = {
		"-inf", "+inf", "nan", "inf"};

	static size_t sizef = sizeof(f_literal)/sizeof(f_literal[0]);
	static size_t sized = sizeof(d_literal)/sizeof(d_literal[0]);	

	for(size_t a = 0; a < sizef; a++)
		if (f_literal[a] == inputlow)
			return PSEUDO_LITERAL_F;

	for(size_t a = 0; a < sized; a++)
		if (d_literal[a] == inputlow)
			return PSEUDO_LITERAL_D;

	return CONTINUE;
}

static t_type is_char(const std::string& input)
{
    if(input.size() != 1)
        return CONTINUE;
		
    unsigned char c = static_cast<unsigned char>(input[0]);

	// we are looking for ascii chars only
    if(c > 127)
		return CONTINUE;

	// can't be an int
	if (std::isdigit(c))
    	return CONTINUE;

	// checks if is is printable
	if (!std::isprint(c))
		return NONDISP_CHAR;
		
	return PRINTBL_CHAR;
}

static t_type is_int(const std::string& input)
{
	if (input.empty())
    	return CONTINUE;

	char *end = NULL;
	const char *str = input.c_str();

	errno = 0;
	long value = std::strtol(str, &end, 10);

	if(end == str)
		return CONTINUE;

	if(*end != 0)
		return CONTINUE;

	if(value == LONG_MAX && errno == ERANGE)
		return INT_OVERF;

	if(value == LONG_MIN && errno == ERANGE)
		return INT_UNDRF;

	if(value > INT_MAX)
		return INT_OVERF;	
	
	if(value < INT_MIN)
		return INT_UNDRF;
	
	return INT;
}

t_type is_float(const std::string& input)
{
	if (input.empty())
		return CONTINUE;

	if(input[input.length() - 1] != 'f')
		return CONTINUE;

	if(!isdigit(input[input.length() - 2]))
		return CONTINUE;

	const char *str = input.c_str();
	char *end = NULL;

	errno = 0;
	double value = std::strtod(str, &end);

	if (end == str)
		return CONTINUE;

	if (end[0] != 'f' || end[1] != '\0')
		return CONTINUE;

	if (errno == ERANGE && (value == HUGE_VAL || value == -HUGE_VAL))
		return FLOAT_OVERF;

	double abs_val = std::fabs(value);
	double f_max   = std::numeric_limits<float>::max();
	double f_min   = std::numeric_limits<float>::denorm_min();

	if (abs_val == 0.0 && errno == 0)
    	return FLOAT;

	if (abs_val > f_max)
    	return FLOAT_OVERF;

	if (abs_val < f_min)
    	return FLOAT_UNDRF;

	return FLOAT;
}

t_type is_double(const std::string& input)
{
	if (input.empty())
		return CONTINUE;

	const char *str = input.c_str();
	char *end = NULL;

	errno = 0;
	double value = std::strtod(str, &end);

	if (end == str)
		return CONTINUE;

	if (*end != '\0')
		return CONTINUE;

	if (errno == ERANGE && (value == HUGE_VAL || value == -HUGE_VAL))
		return DOUBLE_OVERF;

	if (value == 0.0 && errno == ERANGE)
		return DOUBLE_UNDRF;

	return DOUBLE;
}


// ---------- functions - trim -------------------------------------------------

static std::string trim(std::string input)
{
	std::string trimmed = "";

	for(size_t a = 0; a < input.length(); a++)
		if(!std::isspace(input[a])) trimmed += input[a];

	return trimmed;
}
