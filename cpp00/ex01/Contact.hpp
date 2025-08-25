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
		std::string firstname_;
		std::string lastname_;
		std::string phonenumber_;
		std::string secret_;
		int			order;

	public:
		void set_firstname(std::string input);
		void set_lastname(std::string input);
		void set_phonenumber(std::string input);
		void set_secret(std::string input);

		std::string firstname() ;
		std::string lastname() ;
		std::string phonenumber() ;
		std::string secret() ;

		void read_firstname(std::istream& in);
		void read_lastname(std::istream& in);
		void read_phonenumber(std::istream& in);
		void read_secret(std::istream& in);		

};


#endif
