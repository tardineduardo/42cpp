/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:38:13 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:38:51 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	public:
		static const int	_k_nb_ideas = 100;

	private:
		std::string	_ideas[_k_nb_ideas];

	public:
		//canonical methods
		Brain();								// default ctor
		Brain(const Brain& other);				// default copy ctor
		Brain &operator=(const Brain &other);	// default assignment operator
		~Brain();								// default destructor		

		void	deepcopy(Brain& dst, const Brain& src);		
		void	store_idea(const int& index, const std::string& idea);
		void	show_ideas();
};

#endif