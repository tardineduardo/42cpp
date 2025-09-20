/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:36:34 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/20 12:37:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int n = 5;

	Zombie *horde = zombieHorde(n, "blob");

	for(int i = 0; i < n; i++) 
		horde[i].announce();

	delete[](horde);
}
