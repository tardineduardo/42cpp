/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:39:35 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/14 22:33:36 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "messages.hpp"

void message_bureau_defa_ctor(Bureaucrat& b) { 
	std::cout << CYN "🔨 default constructor called for bureaucrat " << b.getName() << " " RST << b.getEmoji() << std::endl; }

void message_bureau_para_ctor(Bureaucrat& b) { 
	std::cout << CYN "📐parameterized constructor called for bureaucrat " << b.getName() << " " RST << b.getEmoji() << std::endl; }

void message_bureau_deft_dtor(Bureaucrat& b) { 
	std::cout << RED "🗑️ destructor called for bureaucrat " << b.getName() << " " RST << b.getEmoji() << std::endl; }

void message_bureau_copy_ctor(Bureaucrat& b) {
	std::cout << CYN "👯 copy constructor called for bureaucrat " << b.getName() << " " RST << b.getEmoji() << std::endl; }

void message_bureau_assg_oper(Bureaucrat& b) { 
	std::cout << CYN "🟰 assignment operator called for bureaucrat " << b.getName() << " " RST << b.getEmoji() << std::endl; }
