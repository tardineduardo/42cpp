#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

# define RED        "\001\033[31m\002"
# define GRN    	"\001\033[32m\002"
# define YEL        "\001\033[33m\002"
# define BLU        "\001\033[34m\002"
# define RESET		"\001\033[0m\002"

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
