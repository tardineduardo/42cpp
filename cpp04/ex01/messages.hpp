/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:36:49 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:36:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_HPP
# define MESSAGES_HPP

# include <iostream>

# define RED        "\001\033[31m\002"
# define GRN    	"\001\033[32m\002"
# define YEL        "\001\033[33m\002"
# define BLU        "\001\033[34m\002"
# define RST		"\001\033[0m\002"

void m_animalctor();
void m_animaldtor();
void m_animalcopy();
void m_animalassg();
void m_brainctor();
void m_braindtor();
void m_braincopy();
void m_brainassg();
void m_catctor();
void m_catdtor();
void m_catcopy();
void m_catassg();
void m_dogctor();
void m_dogdtor();
void m_dogcopy();
void m_dogassg();

#endif
