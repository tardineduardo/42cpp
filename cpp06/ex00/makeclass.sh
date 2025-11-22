#!/usr/bin/env bash

set -euo pipefail

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 ClassName" >&2
    exit 1
fi

class="$1"
CLASS="$(printf '%s' "$class" | tr '[:lower:]' '[:upper:]')"

hpp_file="${class}.hpp"
cpp_file="${class}.cpp"

# Avoid overwriting existing files
for f in "$hpp_file" "$cpp_file"; do
    if [ -e "$f" ]; then
        echo "Error: '$f' already exists. Aborting." >&2
        exit 1
    fi
done

# ---------- ${class}.hpp from class_template.cpp ------------------------------
cat > "$hpp_file" <<EOF
#ifndef ${CLASS}_HPP
# define ${CLASS}_HPP
# include <exception> // Remove if no execptions are used
# include <string>

class ${class} //: public OtherClass
{
	private:
		//
	protected:
		//
	public:
		// canonical
		${class}();                                      // default constructor
        ~${class}();                                    // destructor
        ${class}(const ${class}& other);                // copy constructor
        ${class} &operator=(const ${class} &other);     // assignment operator
		//${class}(char arg1, int arg2);                 // parameterized ctor

		// other
			//methods...

		// constants
			//static const int	kvalue = 1000;

		// operators
			//[returntype] operator[symbol]([params])

		// exceptions
		class ${class}Exception : public std::exception {
			public: const char *what() const throw(); };

};

// ostream operator overload
// std::ostream& operator<<(std::ostream& os, const ${class}& b);

#endif
EOF

# ---------- ${class}.cpp from class_template.hpp ------------------------------
cat > "$cpp_file" <<EOF
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

EOF

echo "Created:"
echo "  $hpp_file"
echo "  $cpp_file"
