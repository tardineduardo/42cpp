/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:39:35 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/16 14:58:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.hpp"


void message_bureau_defa_ctor(Bureaucrat& b) { 
	std::cout << CYN "🔨default constructor called for bureaucrat " << b.getName() << "" RST << b.getEmoji() << std::endl; }

void message_bureau_para_ctor(Bureaucrat& b) { 
	std::cout << CYN "📐parameterized constructor called for bureaucrat " << b.getName() << "" RST << b.getEmoji() << std::endl; }

void message_bureau_deft_dtor(Bureaucrat& b) { 
	std::cout << RED "🗑️ destructor called for bureaucrat " << b.getName() << "" RST << b.getEmoji() << std::endl; }

void message_bureau_copy_ctor(Bureaucrat& b) {
	std::cout << CYN "👯 copy constructor called for bureaucrat " << b.getName() << "" RST << b.getEmoji() << std::endl; }

void message_bureau_assg_oper(Bureaucrat& b) { 
	std::cout << CYN "🟰 assignment operator called for bureaucrat " << b.getName() << "" RST << b.getEmoji() << std::endl; }


void message_bureau2_defa_ctor(Bureaucrat2& b) { 
	std::cout << CYN "🔨default constructor called for bureaucrat2 " << b.getName() << "" RST << b.getEmoji() << std::endl; }

void message_bureau2_para_ctor(Bureaucrat2& b) { 
	std::cout << CYN "📐parameterized constructor called for bureaucrat2 " << b.getName() << "" RST << b.getEmoji() << std::endl; }

void message_bureau2_deft_dtor(Bureaucrat2& b) { 
	std::cout << RED "🗑️ destructor called for bureaucrat2 " << b.getName() << "" RST << b.getEmoji() << std::endl; }

void message_bureau2_copy_ctor(Bureaucrat2& b) {
	std::cout << CYN "👯 copy constructor called for bureaucrat2 " << b.getName() << "" RST << b.getEmoji() << std::endl; }

void message_bureau2_assg_oper(Bureaucrat2& b) { 
	std::cout << CYN "🟰 assignment operator called for bureaucrat2 " << b.getName() << "" RST << b.getEmoji() << std::endl; }	




void message_form_defa_ctor(Form& f) { 
	std::cout << CYN "🔨default constructor called for " << f.getName() << f.getEmoji() << " form" RST << std::endl; }

void message_form_para_ctor(Form& f) { 
	std::cout << CYN "📐parameterized constructor called for " << f.getName() << f.getEmoji() << " form" RST << std::endl; }

void message_form_deft_dtor(Form& f) { 
	std::cout << RED "🗑️ destructor called for " << f.getName() << f.getEmoji() << " form" RST << std::endl; }

void message_form_copy_ctor(Form& f) {
	std::cout << CYN "👯 copy constructor called for " << f.getName() << f.getEmoji() << " form" RST << std::endl; }

void message_form_assg_oper(Form& f) { 
	std::cout << CYN "🟰 assignment operator called for " << f.getName() << f.getEmoji() << " form" RST << std::endl; }



void message_Aform_defa_ctor(AForm& af) { 
	std::cout << CYN "🔨default constructor called for " << af.getName() << af.getEmoji() << " Aform" RST << std::endl; }

void message_Aform_para_ctor(AForm& af) { 
	std::cout << CYN "📐parameterized constructor called for " << af.getName() << af.getEmoji() << " Aform" RST << std::endl; }

void message_Aform_deft_dtor(AForm& af) { 
	std::cout << RED "🗑️ destructor called for " << af.getName() << af.getEmoji() << " Aform" RST << std::endl; }

void message_Aform_copy_ctor(AForm& af) {
	std::cout << CYN "👯 copy constructor called for " << af.getName() << af.getEmoji() << " Aform" RST << std::endl; }

void message_Aform_assg_oper(AForm& af) { 
	std::cout << CYN "🟰 assignment operator called for " << af.getName() << af.getEmoji() << " Aform" RST << std::endl; }	




void message_scf_defa_ctor(ShrubberyCreationForm& s) {
	std::cout << CYN "🔨default constructor called for " << s.getName() << s.getEmoji() << "" RST << std::endl; }

void message_scf_para_ctor(ShrubberyCreationForm& s) {
	std::cout << CYN "📐parameterized constructor called for " << s.getName() << s.getEmoji() << "" RST << std::endl; }

void message_scf_deft_dtor(ShrubberyCreationForm& s) {
	std::cout << RED "🗑️ destructor called for " << s.getName() << s.getEmoji() << "" RST << std::endl; }

void message_scf_copy_ctor(ShrubberyCreationForm& s) {
	std::cout << CYN "👯 copy constructor called for " << s.getName() << s.getEmoji() << "" RST << std::endl; }

void message_scf_assg_oper(ShrubberyCreationForm& s) {
	std::cout << CYN "🟰 assignment operator called for " << s.getName() << s.getEmoji() << "" RST << std::endl; }



void message_rrf_defa_ctor(RobotomyRequestForm& r) {
	std::cout << CYN "🔨default constructor called for " << r.getName() << r.getEmoji() << "" RST << std::endl; }

void message_rrf_para_ctor(RobotomyRequestForm& r) {
	std::cout << CYN "📐parameterized constructor called for " << r.getName() << r.getEmoji() << "" RST << std::endl; }

void message_rrf_deft_dtor(RobotomyRequestForm& r) {
	std::cout << RED "🗑️ destructor called for " << r.getName() << r.getEmoji() << "" RST << std::endl; }

void message_rrf_copy_ctor(RobotomyRequestForm& r) {
	std::cout << CYN "👯 copy constructor called for " << r.getName() << r.getEmoji() << "" RST << std::endl; }

void message_rrf_assg_oper(RobotomyRequestForm& r) {
	std::cout << CYN "🟰 assignment operator called for " << r.getName() << r.getEmoji() << "" RST << std::endl; }


void message_ppf_defa_ctor(PresidentialPardonForm& r) {
	std::cout << CYN "🔨default constructor called for " << r.getName() << r.getEmoji() << "" RST << std::endl; }

void message_ppf_para_ctor(PresidentialPardonForm& r) {
	std::cout << CYN "📐parameterized constructor called for " << r.getName() << r.getEmoji() << "" RST << std::endl; }

void message_ppf_deft_dtor(PresidentialPardonForm& r) {
	std::cout << RED "🗑️ destructor called for " << r.getName() << r.getEmoji() << "" RST << std::endl; }

void message_ppf_copy_ctor(PresidentialPardonForm& r) {
	std::cout << CYN "👯 copy constructor called for " << r.getName() << r.getEmoji() << "" RST << std::endl; }

void message_ppf_assg_oper(PresidentialPardonForm& r) {
	std::cout << CYN "🟰 assignment operator called for " << r.getName() << r.getEmoji() << "" RST << std::endl; }		