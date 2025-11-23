/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:22:06 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/22 18:37:46 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

static void separator(std::string def);
static void p(std::string x);

int main(void)
{
// -----------------------------------------------------------------------------	
separator(
"A Bureaucrat must have: a) A constant name. b) A grade that ranges from 1 (highest\n"
"possible grade) to 150 (lowest possible grade). You will provide getters for both\n"
"attributes: getName() and getGrade()");


}






////////////////////////////////////////////////////////////////////////////////
//																			  //
//							Helpersss										  //
//																			  //
////////////////////////////////////////////////////////////////////////////////

static void separator(std::string def)
{
	static int a = 1;

	std::cout <<"\n\n--------------------------------------------------------------------------------\n"
			  << a << ". " << def << "\n\n";

	a++;
}

static void p(std::string x)
{
	std::cout << "\n[" << x << "]\n";

}