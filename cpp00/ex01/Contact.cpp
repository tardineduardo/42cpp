#include "Contact.hpp"
#include <iostream>

void Contact::set_firstname(std::string s)     {firstname_ = s;  }
void Contact::set_lastname(std::string s)      {lastname_ = s;   }
void Contact::set_phonenumber(std::string s)   {phonenumber_ = s;}
void Contact::set_secret(std::string s)        {secret_ = s;     }

 std::string Contact::firstname()    {return firstname_;   }
 std::string Contact::lastname()     {return lastname_;    }
 std::string Contact::phonenumber()  {return phonenumber_; }
 std::string Contact::secret()       {return secret_;      }

void Contact::read_firstname(std::istream& in) {
  std::cout << "First name: ";
  in >> firstname_;
}

void Contact::read_lastname(std::istream& in) {
  std::cout << "Last name: ";
  in >> lastname_;
}

void Contact::read_phonenumber(std::istream& in) {
  std::cout << "Phone number: ";
  in >> phonenumber_;
}

void Contact::read_secret(std::istream& in) {
  std::cout << "Darkest secret: ";
  in >> secret_;
}