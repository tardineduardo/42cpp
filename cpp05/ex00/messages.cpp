/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:39:35 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/15 19:11:28 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

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



void message_form_defa_ctor(Form& b) { 
	std::cout << CYN "🔨default constructor called for " << b.getName() << b.getEmoji() << " form" RST << std::endl; }

void message_form_para_ctor(Form& b) { 
	std::cout << CYN "📐parameterized constructor called for " << b.getName() << b.getEmoji() << " form" RST << std::endl; }

void message_form_deft_dtor(Form& b) { 
	std::cout << RED "🗑️ destructor called for " << b.getName() << b.getEmoji() << " form" RST << std::endl; }

void message_form_copy_ctor(Form& b) {
	std::cout << CYN "👯 copy constructor called for " << b.getName() << b.getEmoji() << " form" RST << std::endl; }

void message_form_assg_oper(Form& b) { 
	std::cout << CYN "🟰 assignment operator called for " << b.getName() << b.getEmoji() << " form" RST << std::endl; }
