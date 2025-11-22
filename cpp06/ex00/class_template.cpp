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
		${class}();									  // default constructor
        ~${class}();								  // destructor
        ${class}(const ${class}& other);			  // copy constructor
        ${class} &operator=(const ${class} &other);   // assignment operator
		//${class}(char arg1, int arg2);	  		  // parameterized ctor

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
