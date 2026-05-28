#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int a;
		int b;

	public:
		vect2();
		~vect2();
		vect2(const vect2& other);
		vect2 operator=(const vect2& other);
		vect2(const int& x, const int& y);

		int& operator[](int index);
		const int& operator[](int index) const;

		vect2 operator++();
		vect2 operator--();
		vect2 operator++(int);
		vect2 operator--(int);

		vect2 operator+=(const int& k);
		vect2 operator-=(const int& k);
		vect2 operator*=(const int& k);

		vect2 operator+=(const vect2& other);
		vect2 operator-=(const vect2& other);
		vect2 operator*=(const vect2& other);

		vect2 operator+(const int& k) const;
		vect2 operator-(const int& k) const;
		vect2 operator*(const int& k) const;

		vect2 operator+(const vect2& other) const;
		vect2 operator-(const vect2& other) const;
		vect2 operator*(const vect2& other) const;

		vect2 operator-();
		vect2 operator+();

};

std::ostream& operator<<(std::ostream& os, vect2 v);
vect2 operator*(int k, const vect2& other);
bool operator==(const vect2& other1, const vect2& other2);
bool operator!=(const vect2& other1, const vect2& other2);

#endif