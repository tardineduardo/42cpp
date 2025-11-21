/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:39:35 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/20 21:51:28 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.hpp"


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

void message_form_defa_ctor(Form& f) { 
	std::cout << GRN "🔨default constructor called for " << f.getName() << f.getEmoji() << " form" RST << std::endl; }

void message_form_para_ctor(Form& f) { 
	std::cout << GRN "📐paramet constructor called for " << f.getName() << f.getEmoji() << " form" RST << std::endl; }

void message_form_deft_dtor(Form& f) { 
	std::cout << RED "🗑️ destructor called for " << f.getName() << f.getEmoji() << " form" RST << std::endl; }

void message_form_copy_ctor(Form& f) {
	std::cout << GRN "👯 copy constructor called for " << f.getName() << f.getEmoji() << " form" RST << std::endl; }

void message_form_assg_oper(Form& f) { 
	std::cout << GRN "🟰 assignment operator called for " << f.getName() << f.getEmoji() << " form" RST << std::endl; }
