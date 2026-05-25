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

    Arrayint test(10);
    for (int i = 0; i < 10; i++)
    {
        std::cout << test.get_index(i) << ", ";
    }


    


}


