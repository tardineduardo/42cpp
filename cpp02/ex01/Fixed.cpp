/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:49:46 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/20 18:49:47 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* --------------------------------- ex01 ----------------------------------- */

Fixed::Fixed(int value) {
	std::cout << "Int constructor called\n";
	const int shift = bits_;						// number of fractional bits
	const int scale = 1 << shift;					// compute 2^bits_
	const int scaled = value * scale;				// multiply integer by scale
	value_ = scaled;								// store raw fixed-point representation
}

Fixed::Fixed(float value) {
	std::cout << "Float constructor called\n";
	const int   scale   = 1 << bits_;					// 2^bits_  (fixed-point scale)
	const float scaled  = value * scale;				// move the binary point left
	const float rounded = roundf(scaled);				// nearest integer (half away from 0)
	const int   raw     = static_cast<int>(rounded);	// convert to raw fixed format
	value_ = raw;										// store internal representation
}

int Fixed::toInt(void) const {
	return value_ >> bits_;
}

float Fixed::toFloat(void) const {
	const int scale = 1 << bits_;
	float result = static_cast<float>(value_) / scale;
	return result;
}

std::ostream& operator<<(std::ostream& os, const Fixed& x) {
	os << x.toFloat();
	return os;
}
