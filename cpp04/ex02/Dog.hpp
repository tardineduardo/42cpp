/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:25 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/28 19:05:21 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain;

    public:
		// canonicals
        Dog();								// default ctor
        Dog(const Dog& other);				// default copy ctor
        Dog &operator=(const Dog &other);	// default assignt ctor
        ~Dog();                             // default dtor

		void    makeSound() const;
        void	store_idea(const int& index, const std::string& idea);
        void	show_ideas();        
};

#endif
