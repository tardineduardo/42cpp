#include "Contact.hpp"
#include <iostream>

void Contact::set_firstname(const std::string& s)	{ firstname_ = s;	}
void Contact::set_lastname(const std::string& s)	{ lastname_ = s;	}
void Contact::set_phonenumber(const std::string& s)	{ phonenumber_ = s;	}
void Contact::set_secret(const std::string& s)		{ secret_ = s;		}

const std::string& Contact::firstname()	const { return firstname_;	}
const std::string& Contact::lastname() const { return lastname_; }
const std::string& Contact::phonenumber() const { return phonenumber_; }
const std::string& Contact::secret() const { return secret_; }



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