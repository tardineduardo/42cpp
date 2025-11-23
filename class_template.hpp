#include "${class}.hpp"

// ---------- canonical methods ------------------------------------------------

// default constructor
${class}::${class}() {
	// [SET VALUES, DO STUFF]
}

// parameterized constructor
// ${class}::${class}(char arg1, int arg2)
// 	: _arg1(arg1),
// 	  _arg2(arg2) {}

// copy constructor
${class}::${class}(const ${class}& other) {
	// [SET VALUES, DO STUFF]
	return *this;
}

// assignment operator overload
${class}& ${class}::operator=(const ${class}& other) {
	if (this != &other) {
		// [SET VALUES, DO STUFF]
		}
	return *this;
}

// destructor
${class}::~${class}() {
	// [DO STUFF, DELETE ALLOCATIONS]
}


// ---------- other methods ----------------------------------------------------

	// getters, settters and more

// ---------- exceptions -------------------------------------------------------

const char *${class}::${class}Exception::what() const throw() {
	//[DO STUFF]
	return "generic ${class} error";
}
//NOTE: return value can be anything

// ---------- stream operator overload -----------------------------------------

// std::ostream& operator<<(std::ostream& os, const ${class}& b)
// {
// 	os	<< [DO STUFF]
// 	return os;
// }

