#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::bits_ = FRACTIONAL_BITS;

Fixed::Fixed() : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value) : value_(value << bits_) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float f)
    : value_(static_cast<int>(roundf(f * (1 << bits_)))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value_(other.value_) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    value_ = other.value_;
  }
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return value_;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  value_ = raw;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(value_) / static_cast<float>(1 << bits_);
}

int Fixed::toInt(void) const {
  return value_ >> bits_;
}

// Free function, not a member
std::ostream& operator<<(std::ostream& os, const Fixed& x) {
  os << x.toFloat();
  return os;
}

