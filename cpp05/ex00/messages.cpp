/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:39:35 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/13 21:11:11 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "messages.hpp"


void m_bureau_para_ctor(Bureaucrat& b) { 
	std::cout << BLU "parameterized constructor called for Bureaucrat " << b.getName() << " " RST << b.getEmoji() << std::endl; }

void m_bureau_deft_dtor(Bureaucrat& b) { 
	std::cout << RED "default destructor called for Bureaucrat " << b.getName() << " " RST << b.getEmoji() << std::endl; }

void m_bureau_copy_ctor(Bureaucrat& b) {
	std::cout << RED "copy constructor called for Bureaucrat " << b.getName() << " " RST << b.getEmoji() << std::endl; }

void m_bureau_assg_oper(Bureaucrat& b) { 
	std::cout << RED "assignment constructor called for Bureaucrat " << b.getName() << " " RST << b.getEmoji() << std::endl; }
