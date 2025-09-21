/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:51:40 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/20 18:51:42 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# ifndef FRACTIONAL_BITS
#  define FRACTIONAL_BITS 8
# endif

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int					value_;
		static const int	bits_;

	public:
		//ex00 - canonicals
		Fixed();								//default constructor
		~Fixed();								//destructor
		Fixed(const Fixed& other);				//default copy constr
		Fixed&	operator=(const Fixed& other);	//copy assignment op.

		//ex00 - from subject
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		//ex01
		Fixed(const int value);					//ctor from int
		Fixed(const float value);				//ctor from float
		int		toInt(void) const;
		float	toFloat(void) const;

		//ex02
		bool	operator > (const Fixed& other) const;
		bool	operator < (const Fixed& other) const;
		bool	operator >=(const Fixed& other) const;		
		bool	operator <=(const Fixed& other) const;
		bool	operator ==(const Fixed& other) const;	
		bool	operator !=(const Fixed& other) const;
		Fixed	operator + (const Fixed& other) const;
		Fixed	operator - (const Fixed& other) const;
		Fixed	operator * (const Fixed& other) const;
		Fixed	operator / (const Fixed& other) const;				
		Fixed	operator ++(int);						//post
		Fixed	operator --(int);						//post
		Fixed&	operator ++(); 							//pre
		Fixed&	operator --();							//pre
		static Fixed&		max(Fixed& a, Fixed& b);
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
};

//ex01
std::ostream& operator<<(std::ostream& os, const Fixed& x);

#endif
