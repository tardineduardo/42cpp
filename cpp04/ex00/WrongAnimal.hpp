#ifndef WRONGWrongANIMAL_HPP
# define WRONGWrongANIMAL_HPP
# include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;

    public:
       WrongAnimal();
       WrongAnimal(const WrongAnimal& other);
       WrongAnimal &operator=(const WrongAnimal &other);
       ~WrongAnimal();

       const std::string& getType() const;
       void makeSound(void) const;
};

#endif
