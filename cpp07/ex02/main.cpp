/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:12:00 by eduribei          #+#    #+#             */
/*   Updated: 2026/05/24 19:26:20 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include "iter.hpp"


int main(void)
{
    double *a = new double();
    std::cout << a << std::endl;
    std::cout << *a << std::endl;

    std::cout << std::endl << std::endl;

    Arrayint test1(10);
    for (int i = 0; i < 900000; i++)
    {
        std::cout << test1.index(i) << ", ";
    }
    std::cout << std::endl << std::endl;

    std::cout << sizeof(int) << std::endl;

    // Arrayint test2;
    // for (int i = 0; i < 100; i++)
    // {
    //     std::cout << test2.index(i) << ", ";

    // }

    std::cout << std::endl << std::endl;


}


