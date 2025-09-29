/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:25 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 19:09:26 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		// canonicals
        Cat();								// default ctor
        Cat(const Cat& other);				// default copy ctor
        Cat &operator=(const Cat &other);	// default assignt ctor
        ~Cat();								// destructor	

		void getType();
		void makeSound();

};