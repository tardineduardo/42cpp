#ifndef FIXED_HPP
# define FIXED_HPP

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
		
		//new to ex01
		Fixed(const int value);
		Fixed(const float value);
		float toFloat(void) const;
		int toInt(void) const;
		float operator<<(const Fixed& other);

		//from subject
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
