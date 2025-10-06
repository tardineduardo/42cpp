/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bag.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:36:11 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:36:17 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BAG_HPP
# define BAG_HPP
# include <iostream>

class Bag
{
	public:
		static const int	_k_nb_items = 100;

	private:
		std::string	*_items;

	public:
		//canonical methods
		Bag();								// default ctor
		Bag(const Bag& other);				// default copy ctor
		Bag &operator=(const Bag &other);	// default assignment operator
		~Bag();								// default destructor		

		void	deepcopy(Bag& dst, const Bag& src);		
		void	store_item(const int& index, const std::string& item);
		void	show_items();
};

void m_bagctor();
void m_bagdtor();
void m_bagcopy();
void m_bagassg();

#endif