/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:22:06 by eduribei          #+#    #+#             */
/*   Updated: 2025/12/01 16:28:18 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

# define RED	"\001\033[31m\002"
# define GRN	"\001\033[32m\002"
# define YEL	"\001\033[33m\002"
# define BLU	"\001\033[34m\002"
# define MAG	"\001\033[35m\002"
# define CYN	"\001\033[36m\002"
# define WHT	"\001\033[37m\002"
# define BRED	"\001\033[1;31m\002"
# define BGRN	"\001\033[1;32m\002"
# define BYEL	"\001\033[1;33m\002"
# define BBLU	"\001\033[1;34m\002"
# define RST	"\001\033[0m\002"


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
			// basic error
			{"", "empty string"},
			{" ", "single"},
			{"   42", "leading spaces"},
			{"42   ", "trailing spaces"},
			{"\t42", "tab"},
			{"+", "plus"},
			{"-", "minus"},
			{".", "dot"},
			{"f", "f"},
			{"++1", "double plus"},
			{"--1", "double minus"},
			{"4.2.1", "multiple dots"},

			// chars
			{"a", "printable char"},
			{"Z", "printable char"},
			{"0", "digit as char"},
			{"~", "printable ascii"},
			{"\x7f", "DEL non-displayable char"},

			// ints 
			{"42", "simple int"},
			{"+42", "int with plus"},
			{"-42", "negative int"},
			{"0", "zero int"},
			{"127", "char upper bound"},
			{"128", "just past char bound"},
			{"2147483647", "INT_MAX"},
			{"-2147483648", "INT_MIN"},

			// ints
			{"2222222222222222222", "big number"},
			{"3333333333333333333333333333333333333333333333333", "very big number"},
			{"9999999999999999999999999", "positive overflow"},
			{"-9999999999999999999999999", "negative overflow"},

			// 'f'
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

			// doubles
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

			// error
			{"42a", "number followed by letter"},
			{"a42", "letter then number"},
			{"1.2f3", "junk after valid float"},
			{"--42f", "invalid float with extra minus"},
			{"4..2f", "invalid with two dots and f"},
		};


		for(size_t a = 0; a < sizeof(cases)/sizeof(cases[0]); a++)
		{
			count++;
			std::cout << GRN "Test " << count << "----------------------------------\n" RST; 	
			std::cout << GRN "Input: \"" BLU << cases[a].input << GRN "\"" RST << std::endl;
			std::cout << std::endl;

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

