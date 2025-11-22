#ifndef TESTCLASS_HPP
# define TESTCLASS_HPP
# include <exception> // Remove if no execptions are used
# include <string>

class TestClass //: public OtherClass
{
	private:
		//
	protected:
		//
	public:
		// canonical
		TestClass();                                      // default constructor
        ~TestClass();                                    // destructor
        TestClass(const TestClass& other);                // copy constructor
        TestClass &operator=(const TestClass &other);     // assignment operator
		//TestClass(char arg1, int arg2);                 // parameterized ctor

		// other
			//methods...

		// constants
			//static const int	kvalue = 1000;

		// operators
			//[returntype] operator[symbol]([params])

		// exceptions
		class TestClassException : public std::exception {
			public: const char *what() const throw(); };

};

// ostream operator overload
// std::ostream& operator<<(std::ostream& os, const TestClass& b);

#endif
