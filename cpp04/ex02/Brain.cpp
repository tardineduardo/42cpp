/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:38:08 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:39:08 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "messages.hpp"

// canonical methods -----------------------------------------------------------

Brain::Brain() {
	m_brainctor();
}

Brain::Brain(const Brain &other) {
	m_braincopy();
	deepcopy(*this, other);
}

Brain &Brain::operator=(const Brain &other) {
	m_brainassg();
	deepcopy(*this, other);
	return (*this);
}

Brain::~Brain() {
	m_braindtor();
}

//------------------------------------------------------------------------------

void Brain::deepcopy(Brain& dst, const Brain& src) {
	for(int i = 0; i < _k_nb_ideas; i++)
		dst._ideas[i] = src._ideas[i];
}

void	Brain::store_idea(const int& index, const std::string& idea) {
	if (index >= _k_nb_ideas)
		std::cout << YEL "⚠️  brain: invalid idea index" RST << std::endl;
	else
		_ideas[index] = idea;
}

void	Brain::show_ideas() {
	for(int i = 0; i < _k_nb_ideas; i++)
		if (_ideas[i] != "")
			std::cout << i << ". " << _ideas[i] << std::endl;
}
