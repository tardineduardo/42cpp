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
		//canonicals
		Fixed();								//default constructor
		~Fixed();								//destructor
		Fixed(const Fixed& fixed);				//default copy constr
		Fixed& operator=(const Fixed& other);	//copy assignment op.

		//from subject
		int getRawBits(void) const;
		void setRawBits(int const raw);

		//new to ex01
		Fixed(const int value);
		Fixed(const float value);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& x);

#endif
