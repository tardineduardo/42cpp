/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:36:01 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:36:02 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

# include "messages.hpp"

class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(const Animal& other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        virtual const std::string& getType() const;
        virtual void makeSound(void) const;
};

#endif
