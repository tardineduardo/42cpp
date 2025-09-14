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
		Fixed& operator=(const Fixed& other);	//copy assignment op.

		//ex00 - from subject
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
