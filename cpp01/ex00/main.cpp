/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:01:13 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/03 21:01:15 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	randomChump("Ben");
	Zombie *madonna = newZombie("madonna");
	madonna->announce();
	randomChump("suzy");
	Zombie songa("songa");
	delete(madonna);
}
