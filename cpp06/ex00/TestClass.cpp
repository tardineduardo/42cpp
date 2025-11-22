#include "TestClass.hpp"

// ---------- canonical methods ------------------------------------------------

// default constructor
TestClass::TestClass() {
	// [SET VALUES, DO STUFF]
}

// parameterized constructor
// TestClass::TestClass(char arg1, int arg2)
// 	: _arg1(arg1),
// 	  _arg2(arg2) {}

// copy constructor
TestClass::TestClass(const TestClass& other) {
	// [SET VALUES, DO STUFF]
	return *this;
}

// assignment operator overload
TestClass& TestClass::operator=(const TestClass& other) {
	if (this != &other) {
		// [SET VALUES, DO STUFF]
		}
	return *this;
}

// destructor
TestClass::~TestClass() {
	// [DO STUFF, DELETE ALLOCATIONS]
}


// ---------- other methods ----------------------------------------------------

	// getters, settters and more

// ---------- exceptions -------------------------------------------------------

const char *TestClass::TestClassException::what() const throw() {
	//[DO STUFF]
	return "generic TestClass error";
}
//NOTE: return value can be anything

// ---------- stream operator overload -----------------------------------------

// std::ostream& operator<<(std::ostream& os, const TestClass& b)
// {
// 	os	<< [DO STUFF]
// 	return os;
// }

