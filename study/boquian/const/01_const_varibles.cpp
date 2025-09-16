//const
//a compile time constraint that an object can not be modified.

int main(void)
{
	const int a = 9;
	a = 6; // fails at compile time.
	
	// low level const
	const int *p1 = &a;			// data is const, pointer is not
	*p1 = 3;					// fails at compile time.
	p1++; 						// OK
	// tip: read from left to right: "const" is right before "int"

	// top level const
	int b = 1;
	int* const p2 = &b;			// pointer is const, data is not
								// b can't be const, or this won't compile
	*p2 = 4;					// OK
	p2++;						// fails at compile time
	// tip: read from left to right: "const" is right before "p2"

	const int* const p3 = &a;	// data and pointer are both const
	*p3 = 1;					// fails at compile time
	p3++;						// fails at compile time
	//(const int const *p3)

	// THESE ARE TE SAME THING...
	int const *p4 = &a;
	const int *p5 = &b;
	// if const is on the left of *, data is const
	// if const is on the right of *, pointer is const

	// C++ references
	int y = 5;
	const int& ref = y;			// reference to const data
	ref = 6;					// error: data is const through this ref
	y = 6;						// OK: x itself is not const

	const int x = 9;
	x = 6;						// fails at compile time
	const_cast<int&>(x) = 6;	// OK
	// const_cast will cast away the constness of x (AVOID!)

	int j;
	static_cast<const int&>(j) = 7; // fails at compile time
	j = 7; 							// OK	
	// static_cast will turn j into const (AVOID!)
}

/*
	Why use const?
	1) Guards against inadvertent write to the variable
	2) Documenting - for youerself and others
	3) Enables compiler to optimize code
	4) variale can be put in ROM (useful in embeded programming)
*/
