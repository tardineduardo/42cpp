/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:38:25 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:36:33 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain;

    public:
		// canonicals
        Cat();								// default ctor
        Cat(const Cat& other);				// default copy ctor
        Cat &operator=(const Cat &other);	// default assignt ctor
        ~Cat();			                    // default dtor

		void    makeSound() const;
        void	store_idea(const int& index, const std::string& idea);
        void	show_ideas();
};

#endif
