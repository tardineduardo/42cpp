/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:39:35 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/22 17:52:28 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.hpp"


//------------------------------------------------------------------------------

void message_bureau_defa_ctor(Bureaucrat& b) { 
	std::cout << CYN "🔨default constructor called for bureaucrat " << b.getName() << "" RST << b.getEmoji() << std::endl; }

void message_bureau_para_ctor(Bureaucrat& b) { 
	std::cout << CYN "📐paramet constructor called for bureaucrat " << b.getName() << "" RST << b.getEmoji() << std::endl; }

void message_bureau_deft_dtor(Bureaucrat& b) { 
	std::cout << RED "🗑️ destructor called for bureaucrat " << b.getName() << "" RST << b.getEmoji() << std::endl; }

void message_bureau_copy_ctor(Bureaucrat& b) {
	std::cout << CYN "👯 copy constructor called for bureaucrat " << b.getName() << "" RST << b.getEmoji() << std::endl; }

void message_bureau_assg_oper(Bureaucrat& b) { 
	std::cout << CYN "🟰 assignment operator called for bureaucrat " << b.getName() << "" RST << b.getEmoji() << std::endl; }	

//------------------------------------------------------------------------------

void message_AForm_defa_ctor(AForm& af) { 
	std::cout << GRN "🔨default constructor called for " << af.getName() << af.getEmoji() << " (base)" RST << std::endl; }

void message_AForm_para_ctor(AForm& af) { 
	std::cout << GRN "📐paramet constructor called for " << af.getName() << af.getEmoji() << " (base)" RST << std::endl; }

void message_AForm_deft_dtor(AForm& af) { 
	std::cout << RED "🗑️ destructor called for " << af.getName() << af.getEmoji() << " (base)" RST << std::endl; }

void message_AForm_copy_ctor(AForm& af) {
	std::cout << GRN "👯 copy constructor called for " << af.getName() << af.getEmoji() << " (base)" RST << std::endl; }

void message_AForm_assg_oper(AForm& af) { 
	std::cout << GRN "🟰 assignment operator called for " << af.getName() << af.getEmoji() << " (base)" RST << std::endl; }	

//------------------------------------------------------------------------------

void message_scf_defa_ctor(ShrubberyCreationForm& s) {
	std::cout << BGRN "🔨default constructor called for " << s.getName() << s.getEmoji() << " (derived)" RST << std::endl; }

void message_scf_para_ctor(ShrubberyCreationForm& s) {
	std::cout << BGRN "📐paramet constructor called for " << s.getName() << s.getEmoji() << " (derived)" RST << std::endl; }

void message_scf_deft_dtor(ShrubberyCreationForm& s) {
	std::cout << BRED "🗑️ destructor called for " << s.getName() << s.getEmoji() << " (derived)" RST << std::endl; }

void message_scf_copy_ctor(ShrubberyCreationForm& s) {
	std::cout << BGRN "👯 copy constructor called for " << s.getName() << s.getEmoji() << " (derived)" RST << std::endl; }

void message_scf_assg_oper(ShrubberyCreationForm& s) {
	std::cout << BGRN "🟰 assignment operator called for " << s.getName() << s.getEmoji() << " (derived)" RST << std::endl; }

//------------------------------------------------------------------------------

void message_rrf_defa_ctor(RobotomyRequestForm& r) {
	std::cout << BGRN "🔨default constructor called for " << r.getName() << r.getEmoji() << " (derived)" RST << std::endl; }

void message_rrf_para_ctor(RobotomyRequestForm& r) {
	std::cout << BGRN "📐paramet constructor called for " << r.getName() << r.getEmoji() << " (derived)" RST << std::endl; }

void message_rrf_deft_dtor(RobotomyRequestForm& r) {
	std::cout << BRED "🗑️ destructor called for " << r.getName() << r.getEmoji() << " (derived)" RST << std::endl; }

void message_rrf_copy_ctor(RobotomyRequestForm& r) {
	std::cout << BGRN "👯 copy constructor called for " << r.getName() << r.getEmoji() << " (derived)" RST << std::endl; }

void message_rrf_assg_oper(RobotomyRequestForm& r) {
	std::cout << BGRN "🟰 assignment operator called for " << r.getName() << r.getEmoji() << " (derived)" RST << std::endl; }

//------------------------------------------------------------------------------

void message_ppf_defa_ctor(PresidentialPardonForm& r) {
	std::cout << BGRN "🔨default constructor called for " << r.getName() << r.getEmoji() << " (derived)" RST << std::endl; }

void message_ppf_para_ctor(PresidentialPardonForm& r) {
	std::cout << BGRN "📐paramet constructor called for " << r.getName() << r.getEmoji() << " (derived)" RST << std::endl; }

void message_ppf_deft_dtor(PresidentialPardonForm& r) {
	std::cout << BRED "🗑️ destructor called for " << r.getName() << r.getEmoji() << " (derived)" RST << std::endl; }

void message_ppf_copy_ctor(PresidentialPardonForm& r) {
	std::cout << BGRN "👯 copy constructor called for " << r.getName() << r.getEmoji() << " (derived)" RST << std::endl; }

void message_ppf_assg_oper(PresidentialPardonForm& r) {
	std::cout << BGRN "🟰 assignment operator called for " << r.getName() << r.getEmoji() << " (derived)" RST << std::endl; }

//------------------------------------------------------------------------------

void message_intrn_defa_ctor() {
	std::cout << YEL "🔨default constructor called for intern 👼" RST << std::endl; }

void message_intrn_para_ctor() {
	std::cout << YEL "📐paramet constructor called for intern 👼" RST << std::endl; }

void message_intrn_deft_dtor() {
	std::cout << RED "🗑️ destructor called for intern 👼" RST << std::endl; }

void message_intrn_copy_ctor() {
	std::cout << YEL "👯 copy constructor called for intern 👼" RST << std::endl; }

void message_intrn_assg_oper() {
	std::cout << YEL "🟰 assignment operator called for intern 👼" RST << std::endl; }		