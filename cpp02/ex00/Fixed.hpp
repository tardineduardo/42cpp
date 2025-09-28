/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:49:37 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/20 18:49:39 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# ifndef FRACTIONAL_BITS
#  define FRACTIONAL_BITS 8
# endif

# include <iostream>


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
};

#endif
