#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

# include "messages.hpp"

class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(const Animal& other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        virtual const std::string& getType() const;
        virtual void makeSound(void) const;
};

#endif
