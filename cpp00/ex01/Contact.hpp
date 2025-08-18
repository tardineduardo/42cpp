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
		void set_firstname(const std::string& input);
		void set_lastname(const std::string& input);
		void set_phonenumber(const std::string& input);
		void set_secret(const std::string& input);

		const std::string& firstname() const;
		const std::string& lastname() const;
		const std::string& phonenumber() const;
		const std::string& secret() const;

		void read_firstname(std::istream& in);
		void read_lastname(std::istream& in);
		void read_phonenumber(std::istream& in);
		void read_secret(std::istream& in);		

};


#endif
