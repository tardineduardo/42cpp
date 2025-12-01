/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:38:01 by eduribei          #+#    #+#             */
/*   Updated: 2025/12/01 12:57:53 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data array[2];
	array[0].a = 1;
	array[0].b = 2;
	array[0].c = 3.0;
	array[0].d = 'A';
	array[0].e = "britney";
	array[0].f = "spears";
	array[0].g[0] = "banana";
	array[0].g[1] = "maca";
	array[0].g[2] = "melao";
	array[0].g[3] = "uva";

	array[1].a = 5;
	array[1].b = 7;
	array[1].c = 99.0;
	array[1].d = 'Z';
	array[1].e = "lady";
	array[1].f = "gaga";
	array[1].g[0] = "RJ";
	array[1].g[1] = "SP";
	array[1].g[2] = "MG";
	array[1].g[3] = "PE";

	Data *original1 = &array[0];
	uintptr_t raw1;
	Data *decoded1;

	raw1 = Serializer::serialize(original1);
	decoded1 = Serializer::deserialize(raw1);
		
	std::cout << "original Data pointer: " << original1 << std::endl;
	std::cout << "raw uintptr_t pointer: " << raw1;
	std::cout << std::showbase << std::hex << " - " << raw1 << std::dec << std::endl;;
	std::cout << "decoded Data pointer:  " << decoded1 << std::endl;

	if (decoded1 == original1)
		std::cout << "pointers match ✅" << std::endl;
	else
		std::cout << "pointers do NOT match ❌" << std::endl;

	std::cout << decoded1->a << std::endl;
	std::cout << decoded1->b << std::endl;
	std::cout << decoded1->c << std::endl;
	std::cout << decoded1->d << std::endl;
	std::cout << decoded1->e << std::endl;
	std::cout << decoded1->f << std::endl;
	std::cout << decoded1->g[0] << std::endl;
	std::cout << decoded1->g[1] << std::endl;
	std::cout << decoded1->g[2] << std::endl;
	std::cout << decoded1->g[3] << std::endl;

	return 0;
}



