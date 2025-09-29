/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:25 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 19:08:46 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Animal
{
	protected:
		std::string _type;

	public:
		// canonicals
        Animal();								// default ctor
        Animal(const Animal& other);			// default copy ctor
        Animal &operator=(const Animal &other);	// default assignt ctor
        ~Animal();								// destructor	

};