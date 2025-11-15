/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:22:06 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/14 23:33:07 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	//-------------------------------------- CASE 1 ----------------------------	
	try 
	{
		Bureaucrat b1("Max", 20);
		std::cout << b1;
	}
	catch (...) 
	{
		std::cout << "Can't instanciate bureacrat.\n";
	}

	//-------------------------------------- CASE 2 ----------------------------	
	try 
	{
		Bureaucrat b2("Yan", 50);
		Bureaucrat b1("Max", 20);
		b1 = b2;
		b1.decrementGrade(6);
		std::cout << b1.getGrade() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) 
	{
		std::cout << "Can't instanciate bureacrat.\n";
	}

	//-------------------------------------- CASE 3 ----------------------------	




	//-------------------------------------- CASE 4 ----------------------------	




}