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
		float	toFloat(void) const;
		int		toInt(void) const;

		//ex02
		bool	operator>(const Fixed& other);
		bool	operator<(const Fixed& other);
		bool	operator>=(const Fixed& other);		
		bool	operator<=(const Fixed& other);
		bool	operator==(const Fixed& other);	
		bool	operator!=(const Fixed& other);
		Fixed&	operator+(const Fixed& other) const;
		Fixed&	operator-(const Fixed& other) const;
		Fixed&	operator*(const Fixed& other) const;
		Fixed&	operator/(const Fixed& other) const;				
		Fixed	operator++(int); // post
		Fixed	operator--(int); // post
		Fixed&	operator++();    // pre
		Fixed&	operator--();    // pre

};

//ex01
std::ostream& operator<<(std::ostream& os, const Fixed& x);

//ex02
Fixed& min(Fixed& val1, Fixed& val2);
Fixed& min(const Fixed& val1, const Fixed& val2);
Fixed& max(Fixed& val1, Fixed& val2);
Fixed& max(const Fixed& val1, const Fixed& val2);

#endif
