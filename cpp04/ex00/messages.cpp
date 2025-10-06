/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:35:08 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:35:09 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.hpp"

void m_catctor(){std::cout << GRN "🐱 cat default constructor called" RST << std::endl;}
void m_catdtor(){std::cout << RED "🐱 🗑️ cat destructor called" RST << std::endl;}
void m_catcopy(){std::cout << GRN "🐱 cat copy constructor called" RST << std::endl;}
void m_catassg(){std::cout << GRN "🐱 cat assignment operator called" RST << std::endl;}
void m_dogctor(){std::cout << BLU "🐶 dog default constructor called" RST << std::endl;}
void m_dogdtor(){std::cout << RED "🐶 🗑️ dog destructor called" RST << std::endl;}
void m_dogcopy(){std::cout << BLU "🐶 dog copy constructor called" RST << std::endl;}
void m_dogassg(){std::cout << BLU "🐶 dog assignment operator called" RST << std::endl;}
void m_animalctor(){std::cout << "🌎 animal default constructor called" << std::endl;}
void m_animaldtor(){std::cout << RED "🌎 🗑️ animal destructor called" RST << std::endl;}
void m_animalcopy(){std::cout << "🌎 animal copy constructor called" << std::endl;}
void m_animalassg(){std::cout << "🌎 animal assignment operator called" << std::endl;}
