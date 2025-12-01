#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:
		// canonical
		Serializer();									// default constructor
        ~Serializer();									// destructor
        Serializer(const Serializer& other);			// copy constructor
        Serializer &operator=(const Serializer &other);	// assignment operator

	public:

		// other
		static uintptr_t	serialize(Data* ptr);
		static Data			*deserialize(uintptr_t raw);

};

#endif
