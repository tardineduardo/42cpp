#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void) {
    std::cout << "Destructor called" << std::endl;
}

