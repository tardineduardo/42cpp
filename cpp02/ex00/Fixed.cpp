#include "Fixed.hpp"

Fixed::Fixed() : value_(0) {
	std::cout << "Constructor #1 called (default)" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->value_ = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (0);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value_ = raw;
}

//new to ex01

//1. A constructor that takes a constant integer as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value should be initialized to 8, like in exercise 00.
Fixed::Fixed(const int value) {
	std::cout << "Constructor #2 called" << std::endl;
	this->setRawBits(value);
}

//2. A constructor that takes a constant floating-point number as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value should be initialized to 8, like in exercise 00.
Fixed::Fixed(const float value) {
	std::cout << "Constructor #3 called" << std::endl;
	this->setRawBits(value);
}

//3. A member function float toFloat( void ) const; that converts the fixed-point value to a floating-point value.
float Fixed::toFloat(void) const {
	return 0.0;
}

//4. A member function int toInt( void ) const; that converts the fixed-point value to an integer value.
int Fixed::toInt(void) const {
	return 0;
}

//5. And add the following function to the Fixed class files: An overload of the insertion («) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as a parameter.
float Fixed::operator<<(const Fixed& other) {
	std::cout << "<< operator called" << std::endl;
	return other.toFloat();
}
