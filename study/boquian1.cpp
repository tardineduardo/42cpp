int main(void)
{
	const int i = 9;		// data is const
	i = 6;					// ---> won't compile

	const int *p1 = &i;		// data is const, pointer is not
	*p1 = 5;				// ---> won't compile

	const int *p2 = &i;		// data is const, pointer is not
	*p2++;					// ---> compiles!

	// How to remember: read from left to right.
	// "const int" ---> the integer is the const.
	
	int a = 0;

	int* const p3 = &a;			// pointer is const, data is not

	// How to remember: read from left to right.
	// "const p3" ---> p3 (the pointer) is const.

	const int* const p4 = &a;	// pointer AND data are const


	//TRICKY
	int const *p4 = &i;

	// IF CONST IS LEFT OF *	--->	DATA IS CONST
	// IF CONST IS RIGHT OF *	--->	POINTER IS CONST

	// THE LINE ABOVE CAN BE REWRITTEN AS:
	const int *p4 = &i;

	const_cast<int&>(i) = 6;



}
