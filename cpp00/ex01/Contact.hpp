/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:13:53 by eduribei          #+#    #+#             */
/*   Updated: 2025/08/17 16:30:17 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string firstname;
		std::string lastname;
		std::string phonenumber;
		std::string secret;

	public:
		int	age;

		void set_firstname(std::string input) {
			firstname = input;
		}
		std::string get_firstname() {
			return firstname;
		}
		void set_lastname(std::string input) {
			lastname = input;
		}
		std::string get_lastname() {
			return lastname;
		}
		void set_phonenumber(std::string input) {
			phonenumber = input;
		}
		std::string get_phonenumber() {
			return phonenumber;
		}
		void set_secret(std::string input) {
			secret = input;
		}
		std::string get_secret() {
			return secret;
		}



};


#endif