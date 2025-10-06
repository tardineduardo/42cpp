/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:35:18 by eduribei          #+#    #+#             */
/*   Updated: 2025/10/06 18:35:19 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongANIMAL_HPP
# define WRONGWrongANIMAL_HPP
# include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;

    public:
       WrongAnimal();
       WrongAnimal(const WrongAnimal& other);
       WrongAnimal &operator=(const WrongAnimal &other);
       ~WrongAnimal();

       const std::string& getType() const;
       void makeSound(void) const;
};

#endif
