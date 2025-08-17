/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 12:15:16 by eduribei          #+#    #+#             */
/*   Updated: 2025/08/17 13:34:17 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	
	for (int a = 1; argv[a]; a++)
	{
		std::string s = argv[a];
		for (int b = 0; s[b]; b++)
			s[b] = std::toupper(s[b]);
		std::cout << s << " ";
	}
	std::cout << "\n";
}
