/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:22:06 by eduribei          #+#    #+#             */
/*   Updated: 2025/12/01 14:59:01 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"


int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return 0;
	}	

	else
	{
		static int count;

		struct Case {
			std::string input;
			std::string comment;
		};

		Case cases[] = {
			// basic / weird
			{"", "empty string"},
			{" ", "single space"},
			{"   42", "leading spaces"},
			{"42   ", "trailing spaces (if you trim or not)"},
			{"\t42", "tab then number"},
			{"+", "single plus"},
			{"-", "single minus"},
			{".", "single dot"},
			{"f", "single f"},
			{"++1", "invalid: double plus"},
			{"--1", "invalid: double minus"},
			{"4.2.1", "invalid: multiple dots"},

			// chars
			{"a", "printable char (letter)"},
			{"Z", "printable char (letter)"},
			{"0", "digit as char"},
			{"~", "boundary printable ascii"},
			{"\x7f", "DEL non-displayable char (if you treat as char)"},

			// ints (normal)
			{"42", "simple int"},
			{"+42", "int with plus"},
			{"-42", "negative int"},
			{"0", "zero int"},
			{"127", "char upper bound"},
			{"128", "just past char bound"},
			{"2147483647", "INT_MAX"},
			{"-2147483648", "INT_MIN"},

			// ints (overflow-ish, using long long range)
			{"2222222222222222222", "big number"},
			{"3333333333333333333333333333333333333333333333333", "very big number"},
			{"9999999999999999999999999", "huge positive overflow"},
			{"-9999999999999999999999999", "huge negative overflow"},

			// floats with 'f'
			{"0f", "zero float"},
			{"4.2f", "simple float"},
			{"+4.2f", "float with plus"},
			{"-4.2f", "negative float"},
			{"42.0f", "float with .0f"},
			{"4.f", "float with trailing dot"},
			{".5f", "float starting with dot"},
			{"3.40282e+38f", "large float in scientific notation (near FLT_MAX)"},
			{"-3.40282e+38f", "large negative float in scientific notation"},
			{"inff", "invalid: missing sign or nan prefix (depends on your rules)"},
			{"42ff", "invalid: double f"},

			// doubles (no 'f')
			{"4.2", "simple double"},
			{"+4.2", "double with plus"},
			{"-4.2", "negative double"},
			{"42.", "double with trailing dot"},
			{".5", "double starting with dot"},
			{"3.40282e+38", "double with exponent"},
			{"-3.40282e+38", "negative double with exponent"},

			// pseudo-literals
			{"nan", "nan"},
			{"nanf", "nan float"},
			{"+inf", "positive infinity double"},
			{"-inf", "negative infinity double"},
			{"+inff", "positive infinity float"},
			{"-inff", "negative infinity float"},

			// junk / mixed
			{"42a", "number followed by letter"},
			{"a42", "letter then number"},
			{"1.2f3", "junk after valid float"},
			{"--42f", "invalid float with extra minus"},
			{"4..2f", "invalid with two dots and f"},
		};


		for(size_t a = 0; a < sizeof(cases)/sizeof(cases[0]); a++)
		{
			count++;
			std::cout << "Test " << count << "----------------------------------\n"; 	
			std::cout << "Input: \"" << cases[a].input << "\"" << std::endl;
			ScalarConverter::convert(cases[a].input);
			std::cout << std::endl;

		}










	}


}






////////////////////////////////////////////////////////////////////////////////
//																			  //
//							Helpersss										  //
//																			  //
////////////////////////////////////////////////////////////////////////////////

