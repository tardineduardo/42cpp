/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:39:30 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/13 21:07:08 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_HPP
# define MESSAGES_HPP

# include "Bureaucrat.hpp"

# include <iostream>

# define RED        "\001\033[31m\002"
# define GRN    	"\001\033[32m\002"
# define YEL        "\001\033[33m\002"
# define BLU        "\001\033[34m\002"
# define RST		"\001\033[0m\002"

void m_bureau_deft_ctor(Bureaucrat& b);
void m_bureau_deft_dtor(Bureaucrat& b);
void m_bureau_copy_ctor(Bureaucrat& b);
void m_bureau_assg_ctor(Bureaucrat& b);







#endif
