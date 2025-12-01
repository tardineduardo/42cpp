/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:13:59 by eduribei          #+#    #+#             */
/*   Updated: 2025/12/01 14:40:22 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>
//# include <cstdlib>
# include <cctype>
# include <cerrno> 
# include <climits>
# include <cstdlib>
# include <limits>
# include <cmath>

typedef enum e_type {
	CONTINUE = 0,
	PSEUDO_LITERAL_F,
	PSEUDO_LITERAL_D,
	PRINTBL_CHAR,
	NONDISP_CHAR,
	INT,
	INT_OVERF,
	INT_UNDRF,	
	FLOAT,
	FLOAT_OVERF,
	FLOAT_UNDRF,
	DOUBLE,
	DOUBLE_OVERF,
	DOUBLE_UNDRF,
	INVALID
} t_type;

class ScalarConverter
{
	private:
		// canonical
		ScalarConverter();											// default constructor
        ~ScalarConverter();											// destructor
        ScalarConverter(const ScalarConverter& other);				// copy constructor
        ScalarConverter &operator=(const ScalarConverter &other);	// assignment operator

	public:
		// other
		static void convert(std::string input);

};



#endif
