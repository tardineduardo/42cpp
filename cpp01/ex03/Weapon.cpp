/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:47:48 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/03 22:29:10 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
	private:
		std::string type_;

	public:
		const std::string& getType() const;
		std::string setType(const std::string type);
};

#endif

const std::string& Weapon::getType() const {
    return type_;
}


//https://grok.com/s/c2hhcmQtNA%3D%3D_577756df-39cf-42a3-9dbc-026218334069



