/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:12:00 by eduribei          #+#    #+#             */
/*   Updated: 2026/05/29 19:00:07 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Array.hpp"
#include "iter.hpp"


int main(void)
{
	std::cout << "1.\n" << std::endl;


	double *a = new double();
	std::cout << a << std::endl;
	std::cout << *a << std::endl;


	Arrayint test1(5);


	test1[0] = 0;
	test1[1] = 1;
	test1[2] = 2;
	test1[3] = 3;
	test1[4] = 4;


	std::cout << test1[0] << std::endl;
	std::cout << test1[1] << std::endl;
	std::cout << test1[2] << std::endl;
	std::cout << test1[3] << std::endl;
	std::cout << test1[4] << std::endl;

	std::cout << "2.\n" << std::endl;



	std::cout << test1(-1) << std::endl;


	std::cout << std::endl << std::endl;

	std::cout << "3.\n" << std::endl;



	Arrayint test2(99);
	try
	{
		for (unsigned int i = 0; i < 10; i++)
		{
			std::cout << test2[i] << ", ";
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
    }

	std::cout << "4.\n" << std::endl;


	Arrayint test3;
	try
	{
		for (unsigned int i = 0; i < 10; i++)
		{
			std::cout << test2[i] << ", ";
		}
	}
	catch (const Arrayint::EmptyArrayException& e) {
		std::cerr << e.what() << std::endl;
    } catch (const Arrayint::OutOfBoundsException& e) {
		std::cerr << e.what() << std::endl;
    } catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::endl << std::endl;


}

