/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:13:57 by eduribei          #+#    #+#             */
/*   Updated: 2025/12/05 19:19:17 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static std::string	trim(std::string input);
static bool			has_e(std::string s);
static bool			has_plus(std::string s);
static t_type		getType(const std::string& input);

static t_type		is_pseudo_literal(const std::string& input);
static t_type		is_char(const std::string& input);
static t_type		is_int(const std::string& input);
static t_type		is_float(const std::string& input);
static t_type		is_double(const std::string& input);

static void	convert_literal(const std::string& rawinput, std::string results[])
static void			convert_char(const std::string& rawinput, t_type type);
static void			convert_int(const std::string& rawinput, t_type type);
static void			convert_float(const std::string& rawinput, t_type type);
static void			convert_double(const std::string& rawinput, t_type type);


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



void ScalarConverter::convert(std::string input)
{

	std::string results[4];
	std::string trimmed = trim(input);
	t_type type = getType(trimmed);

	convert_literal(trimmed, type);
	convert_char(trimmed, type);
	convert_int(trimmed, type);
	convert_float(trimmed, type);
	convert_double(trimmed, type);

	//if all results are false,
	invalid

}


// ---------- static methods ---------------------------------------------------

static void	convert_literal(const std::string& rawinput, std::string results[])
{
	std::stringstream os;

	static const std::string literal[] = {
		"-inff", "+inff", "inff", 
		"-nanf", "+nanf", "nanf",
		"-inf", "+inf", "inf",		
 		"-nan", "+nan", "nan"
	};

	std::string inputlow;
	for(size_t a = 0; a < rawinput.size(); a++)
		inputlow += std::tolower(rawinput[a]);

	static size_t sizef = sizeof(literal)/sizeof(literal[0]);

	for(size_t a = 0; a < sizef; a++) {
		if (literal[a] == inputlow)
		{
			if(has_plus(inputlow))
				remove_plus(inputlow);
			
			os.str(std::string());
			os.clear();
			os << "float: " << inputlow << std::endl;
			os >> results[3];

			os.str(std::string());
			os.clear();
			os << "float: " << inputlow << std::endl;
			os >> results[3];
		}
		break;
	}

	os.str(std::string());
	os.clear();
	os << "char:\timpossible\n";
	os >> results[0];

	os.str(std::string());
	os.clear();
	os << "int:\timpossible\n";
	os >> results[1];

}

///////continue here
















static void	convert_char(const std::string& rawinput, t_type type)
{
	const char *c = rawinput.c_str();

	if(type == PRINTBL_CHAR)
		std::cout << "char:\t\'" << *c << '\'' << std::endl;
	else if(type == NONDISP_CHAR)
		std::cout << "char:\tnon displayable" << std::endl;
	std::cout << "int:\t" << static_cast<int>(*c) << std::endl;
	std::cout << "float:\t" << static_cast<float>(*c) << ".0f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(*c) << ".0" << std::endl;	
}

static void	convert_int(const std::string& rawinput, t_type type)
{
	std::string input = rawinput;
	if (has_plus(rawinput))
		input.erase(0, 1);

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

static void convert_float(const std::string& rawinput, t_type type)
{
	std::string input = rawinput;
	if (has_plus(rawinput))
		input.erase(0, 1);

	errno = 0;
	char *end = NULL;
	const char *str = input.c_str();
	long value_long = std::strtol(str, &end, 10);
	int value_int = static_cast<int>(value_long);
	double value_double = std::strtod(str, &end);
	unsigned char c = static_cast<unsigned char>(value_int);

	if(value_int < 0 || value_int > 127) 
		std::cout << "char:\t" << "impossible" << std::endl;
	else if(!std::isprint(c))
		std::cout << "char:\t" << "non displayable" << std::endl;
	else
		std::cout << "char:\t\'" << c << '\'' << std::endl;		


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
	{
		std::string fstr = input;
		if(has_e(input))
			fstr.erase(fstr.size() - 1);
		std::cout << "float:\t" << input << std::endl;
	}

	//double
	std::string dstr = input;
	dstr.erase(dstr.size() - 1);
	std::cout << "double:\t" << dstr << std::endl;
}

static void convert_double(const std::string& rawinput, t_type type)
{
	std::string input = rawinput;
	if (has_plus(rawinput))
		input.erase(0, 1);

	errno = 0;
	char *end = NULL;
	const char *str = input.c_str();
	long value_long = std::strtol(str, &end, 10);
	int value_int = static_cast<int>(value_long);
	double value_double = std::strtod(str, &end);
	unsigned char c = static_cast<unsigned char>(value_int);

	if(value_int < 0 || value_int > 127) 
		std::cout << "char:\t" << "impossible" << std::endl;
	else if(!std::isprint(c))
		std::cout << "char:\t" << "non displayable" << std::endl;
	else
		std::cout << "char:\t\'" << c << '\'' << std::endl;

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

		std::string fstr = input;
		if(has_e(input))
			fstr.erase(fstr.size() - 1);
		std::cout << "float:\t" << std::setprecision(1000) << value_float << std::endl;
	//	std::cout << "float:\t" << input << std::endl;
	}

	// double
	if (type == DOUBLE_OVERF)
		std::cout << "double:\t" << "overflow" << std::endl;
	else if (type == DOUBLE_UNDRF)
		std::cout << "double:\t" << "underflow" << std::endl;
	else{
		std::cout << "double:\t" << std::setprecision(1000) << value_double << std::endl;
//		std::cout << "double:\t" << input << std::endl;
	}
}


// ---------- functions - validations ------------------------------------------

static t_type is_pseudo_literal(const std::string& input)
{
	std::string inputlow;
	for(size_t a = 0; a < input.size(); a++)
		inputlow += std::tolower(input[a]);



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


// ---------- helper functions -------------------------------------------------

static std::string trim(std::string input)
{
	std::string trimmed = "";

	for(size_t a = 0; a < input.length(); a++)
		if(!std::isspace(input[a])) trimmed += input[a];

	return trimmed;
}

static bool has_e(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == 'e')
			return true;
	}
	return false;
}

static bool has_plus(std::string s)
{
	if (s[0] == '+')
		return true;
	return false;
}

static void remove_plus(std::string& s)
{
	s.erase(0, 1);
}