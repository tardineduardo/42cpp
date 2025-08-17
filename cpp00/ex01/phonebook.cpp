/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:21:42 by eduribei          #+#    #+#             */
/*   Updated: 2025/08/17 16:21:01 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

int main(void)
{
	Contact eduardo;
	eduardo.age = 42;
	std::cout << "Eduardo's age is " << eduardo.age << " years\n";	

	std::string name;
	std::cin >> name;
	eduardo.set_firstname(name);

	std::cout << eduardo.get_firstname() << std::endl;

}
