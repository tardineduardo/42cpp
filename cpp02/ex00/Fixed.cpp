#include "Fixed.hpp"

const int Fixed::bits_ = FRACTIONAL_BITS;

/* --------------------------------- ex00 ----------------------------------- */

Fixed::Fixed() : value_(0) {
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called\n";
	value_ = other.value_;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		value_ = other.value_;
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (value_);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	value_ = raw;
}
