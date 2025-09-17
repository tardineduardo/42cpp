//const
//a compile time constraint that an object can not be modified.

#include <string>
#include <iostream>

class Dog1 {
	private:
		int			age;
		std::string	name;

	public:
		int			weight;
		Dog1()		{age = 3; name = "dummy";}
		

		// 1. CONST PARAMETERS

		// the value of 'a' can be changed by the member function
		void setAge1(int& a)		{age = a;} 
		// the value of 'a' can NOT be changed by the member function
		void setAge2(const int& a)	{age = a;}
		// 'a' can be changed, but it does't matter, because it's a copy
		void setAge3(const int a)	{age = a;}
		// this setAge3 overload won't compile: they are the same
		void setAge3(int a)			{age = a;}
		// this overload is possible! why? very long story... read below
		// just remember: always prefer the second option, it covers all cases
		void setAge4(int& a)		{age = a;}
		void setAge4(const int& a)	{age = a;}


		// 2. CONST RETURN VALUE

		// the caller can't change the value of the returned variable
		// a ref& to a const is used instead of a copy for efficiency
		const std::string& getName1()	{return name;}

		// const is useless here, because a copy is returned
		const std::string getName2()	{return name;}


		// 3. CONST FUNCTION
		
		// no member variables of the object will be changed 
		void printDogName1() 	const {std::cout << name << '\n';}

		// won't compile because it tries to change a member variable
		// it does not matter if the variable  is public or private
		void printDogName2() 	const {std::cout << name << '\n'; name = "a";}

		// won't compile because it tries to change a member variable
		// it does not matter if the variable is public or private
		void printDogName3() 	const {std::cout << name << '\n'; score = 1;}

		// won't compile because getName() is not a const function, so it could
		// change member variables. const functions only call other const funct.
		// it does not matter if thefunction does not actally change a variable
		void printDogName4() 	const {std::cout << getName1() << '\n';}

		// it is possible to overload functions as const and not const
		// the const function will be called if the Dog object is const, and
		// the non-const function will be called if the Dog object is not const
		void printDogName5() 	const {std::cout << name << "const\n";}
		void printDogName5() 	{std::cout << getName1() << "not const\n";}


};

int main(void)
{
	Dog1 d;

	int i = 9;
	d.setAge1(i);
	std::cout << i << std::endl;
	const std::string& n = d.getName1();

	// didn't do so many notes here

}


/*
Explanation about overloading const/not const parameters:
int x = 10;
const int cx = 20;
setAge4(x);     // calls int&   (non-const lvalue binds to non-const reference)
setAge4(cx);    // calls const int& (cx is const, can't bind to int&)
setAge4(42);    // calls const int& (literal is a temporary rvalue, only const& can bind)
setAge4(x + 5); // calls const int& (expression is rvalue/temporary)
*/