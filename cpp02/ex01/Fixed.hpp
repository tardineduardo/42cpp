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
};

//ex01
std::ostream& operator<<(std::ostream& os, const Fixed& x);

#endif
