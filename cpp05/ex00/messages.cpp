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


void m_bureau_ctor(Bureaucrat& b)
{
	std::cout << b.getEmoji() << "bureaucrat default constructor called" << std::endl;
}

