/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:13:57 by eduribei          #+#    #+#             */
/*   Updated: 2026/05/20 00:00:00 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cerrno>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

static std::string	Trim(const std::string& input);
static bool			IsCharLiteral(const std::string& input);
static bool			IsPseudoLiteral(const std::string& input);
static bool			ParseNumber(const std::string& input, double* value);
static bool			IsNan(double value);
static bool			IsPositiveInf(double value);
static bool			IsNegativeInf(double value);
static bool			NeedsDecimalSuffix(const std::string& text);
static void			PrintImpossible(void);
static void			PrintPseudoLiteral(const std::string& input);
static void			PrintFromNumber(double value);
static void			PrintChar(double value);
static void			PrintInt(double value);
static void			PrintFloat(double value);
static void			PrintDouble(double value);
static std::string	FormatFloat(float value);
static std::string	FormatDouble(double value);

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void	ScalarConverter::convert(const std::string& input)
{
	std::string	trimmed;
	double		value;

	trimmed = Trim(input);
	if (trimmed.empty())
	{
		PrintImpossible();
		return;
	}
	if (IsPseudoLiteral(trimmed))
	{
		PrintPseudoLiteral(trimmed);
		return;
	}
	if (IsCharLiteral(trimmed))
	{
		value = static_cast<double>(trimmed[0]);
		PrintFromNumber(value);
		return;
	}
	if (!ParseNumber(trimmed, &value))
	{
		PrintImpossible();
		return;
	}
	PrintFromNumber(value);
}

static std::string	Trim(const std::string& input)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = input.length();
	while (start < end
		&& std::isspace(static_cast<unsigned char>(input[start])))
		start++;
	while (end > start
		&& std::isspace(static_cast<unsigned char>(input[end - 1])))
		end--;
	return (input.substr(start, end - start));
}

static bool	IsCharLiteral(const std::string& input)
{
	unsigned char	c;

	if (input.length() != 1)
		return (false);
	c = static_cast<unsigned char>(input[0]);
	if (std::isdigit(c))
		return (false);
	return (true);
}

static bool	IsPseudoLiteral(const std::string& input)
{
	return (input == "nan" || input == "nanf"
		|| input == "+inf" || input == "-inf"
		|| input == "+inff" || input == "-inff");
}

static bool	ParseNumber(const std::string& input, double* value)
{
	std::string	parsed;
	char		*end;

	parsed = input;
	if (parsed.length() > 1 && parsed[parsed.length() - 1] == 'f')
		parsed.erase(parsed.length() - 1);
	if (parsed.empty() || parsed == "+" || parsed == "-"
		|| parsed == "." || parsed == "+." || parsed == "-.")
		return (false);
	errno = 0;
	end = NULL;
	*value = std::strtod(parsed.c_str(), &end);
	if (end == parsed.c_str() || *end != '\0')
		return (false);
	return (true);
}

static bool	IsNan(double value)
{
	return (value != value);
}

static bool	IsPositiveInf(double value)
{
	return (value == std::numeric_limits<double>::infinity());
}

static bool	IsNegativeInf(double value)
{
	return (value == -std::numeric_limits<double>::infinity());
}

static bool	NeedsDecimalSuffix(const std::string& text)
{
	if (text.find('.') != std::string::npos)
		return (false);
	if (text.find('e') != std::string::npos)
		return (false);
	if (text.find('E') != std::string::npos)
		return (false);
	return (true);
}

static void	PrintImpossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void	PrintPseudoLiteral(const std::string& input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input == "nan" || input == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

static void	PrintFromNumber(double value)
{
	PrintChar(value);
	PrintInt(value);
	PrintFloat(value);
	PrintDouble(value);
}

static void	PrintChar(double value)
{
	char	c;

	std::cout << "char: ";
	if (IsNan(value) || IsPositiveInf(value) || IsNegativeInf(value)
		|| value < 0.0 || value > 127.0)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	c = static_cast<char>(value);
	if (!std::isprint(static_cast<unsigned char>(c)))
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	std::cout << "'" << c << "'" << std::endl;
}

static void	PrintInt(double value)
{
	std::cout << "int: ";
	if (IsNan(value) || IsPositiveInf(value) || IsNegativeInf(value)
		|| value < static_cast<double>(INT_MIN)
		|| value > static_cast<double>(INT_MAX))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

static void	PrintFloat(double value)
{
	std::cout << "float: " << FormatFloat(static_cast<float>(value)) << std::endl;
}

static void	PrintDouble(double value)
{
	std::cout << "double: " << FormatDouble(value) << std::endl;
}

static std::string	FormatFloat(float value)
{
	std::ostringstream	output;

	if (value == std::numeric_limits<float>::infinity())
		return ("inff");
	if (value == -std::numeric_limits<float>::infinity())
		return ("-inff");
	if (IsNan(value))
		return ("nanf");
	output << std::setprecision(7) << value;
	if (NeedsDecimalSuffix(output.str()))
		output << ".0";
	output << "f";
	return (output.str());
}

static std::string	FormatDouble(double value)
{
	std::ostringstream	output;

	if (IsPositiveInf(value))
		return ("inf");
	if (IsNegativeInf(value))
		return ("-inf");
	if (IsNan(value))
		return ("nan");
	output << std::setprecision(15) << value;
	if (NeedsDecimalSuffix(output.str()))
		output << ".0";
	return (output.str());
}
