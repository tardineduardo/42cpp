#include "ScalarConverter.hpp"

// ---------- canonical methods ------------------------------------------------

// default constructor
ScalarConverter::ScalarConverter() {}

// copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other) {}

// assignment operator overload
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other) {}
	return *this;
}

// destructor
ScalarConverter::~ScalarConverter() {}


// ---------- other methods ----------------------------------------------------

void ScalarConverter::convert(std::string input) {
	




}


// ---------- exceptions -------------------------------------------------------

const char *ScalarConverter::ScalarConverterException::what() const throw() {
	return "generic ScalarConverter error";
}

// ---------- stream operator overload -----------------------------------------

// std::ostream& operator<<(std::ostream& os, const ScalarConverter& b)
// {
// 	os	<< [DO STUFF]
// 	return os;
// }

