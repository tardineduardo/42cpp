#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <ctime>

class Contact
{
	private:
		std::string firstname_;
		std::string lastname_;
		std::string nickname_;
		std::string phone_;
		std::string secret_;
		std::time_t	time_;

	public:
		void set_firstname(const std::string& input);
		void set_lastname(const std::string& input);
		void set_nickname(const std::string& input);
		void set_phone(const std::string& input);
		void set_secret(const std::string& input);
		void set_time(const std::time_t& time);

		const std::string& firstname() const;
		const std::string& lastname() const;
		const std::string& nickname() const;
		const std::string& phone() const;
		const std::string& secret() const;
		const std::time_t& time() const;		

		void PrintContact();
};

#endif
