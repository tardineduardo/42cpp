#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <exception> // Remove if no execptions are used
# include <string>

class ScalarConverter
{
	public:
		// canonical
		ScalarConverter();											// default constructor
        ~ScalarConverter();											// destructor
        ScalarConverter(const ScalarConverter& other);				// copy constructor
        ScalarConverter &operator=(const ScalarConverter &other);	// assignment operator

		// other
		static void ScalarConverter::convert(std::string input);
		
		// constants
			//static const int	kvalue = 1000;

		// operators
			//[returntype] operator[symbol]([params])

		// exceptions
		class ScalarConverterException : public std::exception {
			public: const char *what() const throw(); };

};

// ostream operator overload
// std::ostream& operator<<(std::ostream& os, const ScalarConverter& b);

#endif
