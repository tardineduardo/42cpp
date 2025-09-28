#include "Harl.hpp"

#include <iostream>

void Harl::debug(void) {
	std::cout << "printing debug message" << std::endl;}

void Harl::info(void) {
	std::cout << "printing info message" << std::endl;}

void Harl::warning(void) {
	std::cout << "printing warning message" << std::endl;}

void Harl::error(void) {
	std::cout << "printing error message" << std::endl;}

void Harl::complain(std::string level) {
	std::string levels[] = {"debug", "info", "warning", "error"};
	void (Harl::*function[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};
	
	int count = sizeof(levels) / sizeof(levels[0]);
	for(int i = 0; i < count; i++) {
		if (levels[i] == level) 
			(this->*function[i])();}

}
