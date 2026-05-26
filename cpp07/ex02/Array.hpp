/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:00:30 by eduribei          #+#    #+#             */
/*   Updated: 2026/05/24 20:31:32 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

#include <exception>

class Arrayint
{
    private:
        int *_array;
        int _size;

    public:

        Arrayint();
        ~Arrayint();
        Arrayint& operator=(const Arrayint& other);
        Arrayint(const unsigned int& n);

        Arrayint(const Arrayint& other);
        const int& operator[](unsigned int index) const;
        int& operator[](unsigned int index);

        int operator()(const int& index);
        int index(const int& i);
        int size();

        class OutOfBoundsException : public std::exception {
            public: const char *what() const throw(); };

        class EmptyArrayException : public std::exception {
            public: const char *what() const throw(); };        


};



#include "Array.tpp"

#endif



// Develop a class template Array that contains elements of type T and that implements
// the following behavior and functions:

// •Construction with no parameter: Creates an empty array.

// •Construction with an unsigned int n as a parameter: Creates an array of n elements
// initialized by default. ------- Tip: Try to compile int * a = new int(); then display *a.

// •Construction by copy and assignment operator. In both cases, modifying either the
// original array or its copy after copying musn’t affect the other array.

// •You MUST use the operator new[] to allocate memory. Preventive allocation (al-
// locating memory in advance) is forbidden. Your program must never access non-
// allocated memory.

// •Elements can be accessed through the subscript operator: [ ].

// •When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.

// •A member function size() that returns the number of elements in the array. This
// member function takes no parameters and must not modify the current instance.
// As usual, ensure everything works as expected and turn in a main.cpp file that con-
// tains your tests.