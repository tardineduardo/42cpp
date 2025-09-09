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

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->type_ = type;
}

const std::string&  Weapon::getType() const {
    return type_;
}

void    Weapon::setType(const std::string type) {
    this->type_ = type;
}

//https://grok.com/s/c2hhcmQtNA%3D%3D_577756df-39cf-42a3-9dbc-026218334069



