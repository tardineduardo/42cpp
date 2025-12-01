/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:10:19 by eduribei          #+#    #+#             */
/*   Updated: 2025/12/01 14:39:31 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

// ---------- canonical methods ------------------------------------------------

Base::~Base() {}


// ---------- other functions --------------------------------------------------

Base	*generate(void)
{
	static bool isseeded = false;
	
	if (!isseeded) {
	srand(static_cast<unsigned int>(std::time(NULL)));
	isseeded = true;
	}

	int randomint = rand() % 3;

	if (randomint == 0)
		return new A; 
	if (randomint == 1)
		return new B;
	if (randomint == 2)
		return new C;
	std::cerr << "error\n";
	return (NULL);		
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p)) 
		std::cout << "it's of type: A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "it's of type: B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "it's of type: C\n";
	else
		std::cout << "Unknown class\n";
}

void	identify(Base& p)
{
	try { dynamic_cast<A&>(p); return; }
	catch (std::exception &e) {}

	try { dynamic_cast<B&>(p); return; }
	catch (std::exception &e) {}	

	try { dynamic_cast<C&>(p); return; }
	catch (std::exception &e) {	std::cout << "Unknown class\n"; }
}
