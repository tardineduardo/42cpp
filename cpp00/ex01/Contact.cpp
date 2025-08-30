#include "Contact.hpp"
#include <iostream>

void Contact::set_firstname(const std::string& str) {
	firstname_ = str;}
void Contact::set_lastname(const std::string& str) {
	lastname_ = str;}
void Contact::set_nickname(const std::string& str) {
	nickname_ = str;}
void Contact::set_phone(const std::string& str) {
	phone_ = str;}
void Contact::set_secret(const std::string& str) {
	secret_ = str;}
void Contact::set_time(const std::time_t& time) {
	time_ = time;}

const std::string& Contact::firstname()	const {
	return firstname_;}
const std::string& Contact::lastname() const {
	return lastname_;}
const std::string& Contact::nickname() const {
	return nickname_;}
const std::string& Contact::phone() const {
	return phone_;}
const std::string& Contact::secret() const {
	return secret_;}
const std::time_t& Contact::time() const {
	return time_;}

void Contact::PrintContact() {
	std::cout << "first name: " << Contact::firstname() << std::endl;
	std::cout << "last name: " << Contact::lastname() << std::endl;
	std::cout << "nick name: " << Contact::nickname() << std::endl;
	std::cout << "phone number: " << Contact::phone() << std::endl;
	std::cout << "darkest secret: " << Contact::secret() << std::endl;			
}
