/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:34:44 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:34:46 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

# include "messages.hpp"

class Animal
{
    protected:
        std::string		_type;

    public:
		//canonical methods
        Animal();								// default ctor
        Animal(const Animal& other);			// default copy ctor
        Animal &operator=(const Animal &other);	// default assignment operator
        virtual ~Animal();						// default destructor		

        virtual const std::string&	getType() const;
        virtual void				makeSound(void) const;
};

#endif
