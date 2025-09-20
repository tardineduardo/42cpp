/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:47:48 by eduribei          #+#    #+#             */
/*   Updated: 2025/09/20 12:31:54 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    type_ = type;
}

const std::string&	Weapon::getType() const {
    return type_;
}

void	Weapon::setType(const std::string type) {
    type_ = type;
}
