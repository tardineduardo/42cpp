/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:00:30 by eduribei          #+#    #+#             */
/*   Updated: 2026/05/24 13:51:18 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
#define TESTS_HPP
#include <iostream>
#include <string>

// --- ints --------------------------------------------------------------------

void set_int	(int& x);
void inc_int	(int& x);
void put_int	(const int& x);
void iter_int	(int array[], const int len, void(*func)(int&));
void iter_int	(const int array[], const int len, void(*func)(const int&));

// --- string objects ----------------------------------------------------------

void set_fruit	(std::string& str);
void str_upper	(std::string& x);
void put_str	(const std::string& str);
void iter_str	(std::string array[], const int len, void(*func)(std::string&));
void iter_str	(const std::string array[], const int len, void(*func)(const std::string&));

// --- print_array_overload ----------------------------------------------------

void print_array	(const int int_array[], int len);
void print_array	(const std::string str_array[], int len);

// --- test helpers ------------------------------------------------------------

void divider	(std::string message);
void linebreak	(void);

// --- simple print template ---------------------------------------------------

template <typename T>
void print(const T& item)
{
	std::cout << item << ", ";
}

#endif // TESTS_HPP