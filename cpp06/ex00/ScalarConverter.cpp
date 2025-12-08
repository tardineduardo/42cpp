/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:13:57 by eduribei          #+#    #+#             */
/*   Updated: 2025/12/07 22:19:28 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


struct Values
{
	unsigned char	schar;
	int				sint;
	long			slong;
	float			sfloat;
	double			sdouble;
	double			sdouble_abs;
	double			f_max;
	double			f_min;
	double			f_de_min;
	int				i_max;
	int				i_min;	


};

static std::string	trim(std::string input);
// static bool			has_e(std::string s);
static void			remove_plus_char(std::string& s);
char whatType(std::string& input, Values& vals);
static bool is_all_digits(std::string& input);


static void put_int(std::string results[], int value_int);
static void put_int(std::string results[], std::string message);
static void put_char(std::string results[], unsigned char value_char);
static void put_char(std::string results[], std::string message);
static void put_float(std::string results[], float value_float);
static void put_double(std::string results[], double value_double);

static void	convert_literal(const std::string& input, std::string results[]);
static void	convert_char(std::string results[], Values& vals);
static void convert_int(std::string results[], Values& vals);
static void	convert_float(const std::string& input, std::string results[], Values& vals);
// static void			convert_double(const std::string& rawinput, t_type type);


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
	if (input.empty())
		return;

	Values vals;	
	std::string results[4];
	std::string trimmed = trim(input);
	char type = whatType(trimmed, vals);
	
	if (type == 'L') convert_literal(trimmed, results);
	else if	(type == 'C') convert_char(results, vals);
	else if	(type == 'I') convert_int(results, vals);
	else if	(type == 'D') convert_float(trimmed, results, vals);
	else {
		std::cout << "invalid" << std::endl;
		return;
	}

	for(size_t a = 0; a < sizeof(results)/sizeof(results[0]); a++)
		std::cout << results[a] << std::endl;
}


// ---------- static methods ---------------------------------------------------

static void	convert_literal(const std::string& input, std::string results[])
{
	std::stringstream os;

	static const std::string literal[] = {
		"-inff", "+inff", "inff", 
		"-nanf", "+nanf", "nanf",
		"-inf", "+inf", "inf",		
 		"-nan", "+nan", "nan"
	};

	std::string inputlow;
	for(size_t a = 0; a < input.size(); a++)
		inputlow += std::tolower(input[a]);

	static size_t sizef = sizeof(literal)/sizeof(literal[0]);

	size_t a;
	for(a = 0; a < sizef; a++)
	{
		if (literal[a] == inputlow)
		{
			remove_plus_char(inputlow);
			results[0] = "char:\timpossible"; 
			results[1] = "int:\timpossible";			
			results[2] = "float:\t" + inputlow;
			results[3] = "double:\t" + inputlow;
			break;
		}
	}
}

static void	convert_char(std::string results[], Values& vals)
{
	if (std::isprint(vals.schar))
		put_char(results, vals.schar);
	else
		put_char(results, "non displayable");
	put_int(results, vals.sint);
	put_float(results, vals.sfloat);
	put_double(results, vals.sdouble);
}

static void	convert_int(std::string results[], Values& vals)
{
	if (vals.slong > vals.i_max || vals.slong < vals.i_min)
	{
		put_char(results, "impossible");
		put_int(results, "impossible");
		
	 	if (vals.sdouble_abs == 0.0 && errno == 0)
		{
			put_float(results, vals.sfloat);
			put_double(results, vals.sdouble);
			return;
		}

		if (vals.sdouble_abs > vals.f_max || vals.sdouble_abs < vals.f_min) 
		{
			put_float(results, vals.sfloat);
			put_double(results, vals.sdouble);
			return;
		}

		put_float(results, vals.sfloat);
		put_double(results, vals.sdouble);
		return;
	}

	if (vals.sint >= 0 && vals.sint <= 127)
	{
		if (isprint(vals.schar))
			put_char(results, vals.schar);
		else
			put_char(results, "non displayable");
	
	}
	else
		put_char(results, "impossible");

	put_int(results, vals.sint);
	put_float(results, vals.sfloat);
	put_double(results, vals.sdouble);


}

//////////////////////////////////////////////////////////////////////////
static void	convert_float(const std::string& input, std::string results[], Values& vals)
{
		(void)vals;
	unsigned char	value_char;
	int				value_int;
	float			value_float;
	double			value_double;	
	char			*end;

	if(input[input.length() - 1] != 'f')
		return;

	if(!isdigit(input[input.length() - 2]))
		return;

	const char *str = input.c_str();
	end = NULL; errno = 0;
	value_double = std::strtod(str, &end);
	if (end == str || end[0] != 'f' || end[1] != '\0')
		return;

	double abs_val = std::fabs(value_double);
	double i_max   = std::numeric_limits<int>::max();
	double i_min   = std::numeric_limits<int>::min();

	{end = NULL; errno = 0;
	value_float = std::strtof(str, &end);}

	{end = NULL; errno = 0;
	value_int = static_cast<int>(std::strtol(str, &end, 10));}	

	if (abs_val == 0.0 && errno == 0)
	{
		if (errno == 0)
			put_char(results, "non displayable");
		else if (errno == ERANGE)
			put_char(results, "impossible");

		put_int(results, value_int);
		put_float(results, value_float);
		put_double(results, value_double);
		return;
	}


	if (value_double >= i_min && value_double <= i_max)
	{
		if (value_double >= 0 && value_double <= 127)
		{
			value_char = static_cast<unsigned char>(value_double);
			if (isprint(value_int)) put_char(results, value_char);
			else put_char(results, "non displayable");
		}
		else put_char(results, "impossible");


		{std::stringstream os;
			os << "int:\t" << value_int << std::endl;
			std::getline(os, results[1]); }

		put_float(results, value_float);
		put_double(results, value_double);
		
		return;
	}



	
}



// ---------- helper functions -------------------------------------------------

static std::string trim(std::string input)
{
	std::string trimmed = "";

	for(size_t a = 0; a < input.length(); a++)
		if(!std::isspace(input[a])) trimmed += input[a];

	return trimmed;
}

// static bool has_e(std::string s)
// {
// 	for (size_t i = 0; i < s.length(); i++)
// 	{
// 		if (s[i] == 'e')
// 			return true;
// 	}
// 	return false;
// }

// static void remove_f_char(std::string& input)
// {
//     if (!input.empty() && input[input.size() - 1] == 'f')
//         input.erase(input.size() - 1);
// }


static void remove_plus_char(std::string& s)
{
	if (s[0] == '+')
		s.erase(0, 1);
}


static bool is_all_digits(std::string& input)
{
	const char *str = input.c_str();

	if (str[0] != '+' && str[0] != '-' && !isdigit(str[0]))
		return false;

	for(size_t i = 1; i < input.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}



static void put_char(std::string results[], unsigned char value_char)
{
	std::stringstream os;
	os << "char:\t\'" <<  value_char << '\'' << std::endl;
	std::getline(os, results[0]);
}

static void put_char(std::string results[], std::string message)
{
	std::stringstream os;
	os << "char:\t" <<  message << std::endl;
	std::getline(os, results[0]);
}


static void put_int(std::string results[], int value_int)
{
	std::stringstream os;
	os << "int:\t" <<  value_int << std::endl;
	std::getline(os, results[1]);
}

static void put_int(std::string results[], std::string message)
{
	std::stringstream os;
	os << "int:\t" << message << std::endl;
	std::getline(os, results[1]);
}


static void put_float(std::string results[], float value_float)
{
	std::stringstream os;
	std::streamsize old_prec = std::cout.precision();
	std::ios_base::fmtflags old_flags = std::cout.flags();

	os << "float:\t" << std::fixed << std::setprecision(250) << value_float << std::endl;
	std::getline(os, results[2]);
	std::cout.precision(old_prec);
	std::cout.flags(old_flags);
}

static void put_double(std::string results[], double value_double)
{
	std::stringstream os;
	os << "double:\t" << std::fixed << std::setprecision(250) << value_double << std::endl;
	std::getline(os, results[3]);
}



char whatType(std::string& input, Values& vals)
{
	char			type;
	unsigned char	value_char;
	int				value_int;
	long			value_long;
	float			value_float;
	double			value_double;



	std::string inputlow;
	char *end;
	type = 0;
	const char *str = input.c_str();
	int i_min = std::numeric_limits<int>::min();
	int i_max = std::numeric_limits<int>::max();
	double f_max   = std::numeric_limits<float>::max();
	double f_min   = std::numeric_limits<float>::min();	
	double f_de_min   = std::numeric_limits<float>::denorm_min();

//------------------------------------------------------------------------------

	static const std::string literal[] = {
		"-inff", "+inff", "inff", 
		"-nanf", "+nanf", "nanf",
		"-inf", "+inf", "inf",		
 		"-nan", "+nan", "nan" };
	for(size_t a = 0; a < input.size(); a++)
		inputlow += std::tolower(input[a]);
	size_t sizef = sizeof(literal)/sizeof(literal[0]);
	for(size_t a = 0; a < sizef; a++)
		if (literal[a] == inputlow)
			return 'L';

//------------------------------------------------------------------------------
	
	value_char = static_cast<int>(*str);
	if(input.size() == 1 && value_char <= 127 && !std::isdigit(value_char))
		type = 'C';
	vals.schar = value_char;

//------------------------------------------------------------------------------

	end = NULL; errno = 0;
	if (type == 'C')
	{
		value_long = static_cast<long>(value_char);
		value_int = static_cast<int>(value_char);
		vals.sint = value_int;
		vals.slong = value_long;
	}	
	else if (is_all_digits(input))
	{
		type = 'I';		
		value_long = std::strtol(str, &end, 10);
		if(end != str || *end == 0)
		{
			if (value_long <= i_max && value_long >= i_min)
				type = 'I';
			value_int = static_cast<int>(value_long);
			vals.sint = value_int;			
			vals.slong = value_long;
		}	
	}


//------------------------------------------------------------------------------

	end = NULL; errno = 0;
	value_double = std::strtod(str, &end);
	if (end != str && *end == 0)
	{
		value_float = std::strtof(str, &end);
		vals.sfloat = value_float;
		vals.sdouble = value_double;
		vals.sdouble_abs = std::fabs(value_double);
		if (type != 'C' && type != 'I')
			type = 'D';	


	}

//------------------------------------------------------------------------------

	vals.f_max = f_max;
	vals.f_min = f_min;
	vals.f_de_min = f_de_min;

	return type;
}

