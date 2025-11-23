#include "ScalarConverter.hpp"

// ---------- canonical methods ------------------------------------------------

// default constructor
ScalarConverter::ScalarConverter() {
	// [SET VALUES, DO STUFF]
}

// parameterized constructor
// ScalarConverter::ScalarConverter(char arg1, int arg2)
// 	: _arg1(arg1),
// 	  _arg2(arg2) {}

// copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	// [SET VALUES, DO STUFF]
}

// assignment operator overload
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other) {
		// [SET VALUES, DO STUFF]
		}
	return *this;
}

// destructor
ScalarConverter::~ScalarConverter() {
	// [DO STUFF, DELETE ALLOCATIONS]
}


// ---------- other methods ----------------------------------------------------

static void ScalarConverter::convert(std::string input) {



}
// ---------- exceptions -------------------------------------------------------

const char *ScalarConverter::ScalarConverterException::what() const throw() {
	//[DO STUFF]
	return "generic ScalarConverter error";
}
//NOTE: return value can be anything

// ---------- stream operator overload -----------------------------------------

// std::ostream& operator<<(std::ostream& os, const ScalarConverter& b)
// {
// 	os	<< [DO STUFF]
// 	return os;
// }

