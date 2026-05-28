#include "vect2.hpp"

vect2::vect2()
{
	a = 0;
	b = 0;
}

vect2::~vect2()
{

}

vect2::vect2(const vect2& other)
{
	this->a = other.a;
	this->b = other.b;
}

vect2 vect2::operator=(const vect2& other)
{
	a = other.a;
	b = other.b;
	return *this;
}

//------------------------------------------------------

vect2::vect2(const int& x, const int& y)
{
	a = x;
	b = y;
}

int& vect2::operator[](int index)
{
	if (index == 0)
		return a;
	return b;
}

const int& vect2::operator[](int index) const
{
	if (index == 0)
		return a;
	return b;
}


vect2 vect2::operator++()
{
	a++;
	b++;
	return *this;
}

vect2 vect2::operator--()
{
	a--;
	b--;
	return *this;
}

vect2 vect2::operator++(int)
{
	vect2 temp(*this);
	a++;
	b++;
	return temp;
}

vect2 vect2::operator--(int)
{
	vect2 temp(*this);
	a--;
	b--;
	return temp;
}

vect2 vect2::operator+=(const int& k)
{
	a += k;
	b += k;
	return *this;
}

vect2 vect2::operator-=(const int& k)
{
	a -= k;
	b -= k;
	return *this;
}

vect2 vect2::operator*=(const int& k)
{
	a *= k;
	b *= k;
	return *this;
}


vect2 vect2::operator+=(const vect2& other)
{
	a += other.a;
	b += other.b;
	return *this;
}

vect2 vect2::operator-=(const vect2& other)
{
	a -= other.a;
	b -= other.b;
	return *this;
}

vect2 vect2::operator*=(const vect2& other)
{
	a *= other.a;
	b *= other.b;
	return *this;
}

vect2 vect2::operator+(const int& k) const
{
	vect2 temp(*this);
	temp.a += k;
	temp.b += k;
	return *this;
}

vect2 vect2::operator-(const int& k) const
{
	vect2 temp(*this);
	temp.a -= k;
	temp.b -= k;
	return temp;
}

vect2 vect2::operator*(const int& k) const
{
	vect2 temp(*this);
	temp.a *= k;
	temp.b *= k;
	return temp;
}

vect2 vect2::operator+(const vect2& other) const
{
	vect2 temp(*this);
	temp.a += other.a;
	temp.b += other.b;
	return temp;
}

vect2 vect2::operator-(const vect2& other) const
{
	vect2 temp(*this);
	temp.a -= other.a;
	temp.b -= other.b;
	return temp;
}

vect2 vect2::operator*(const vect2& other) const
{
	vect2 temp(*this);
	temp.a *= other.a;
	temp.b *= other.b;
	return temp;
}

vect2 vect2::operator-()
{
	a = -a;
	b = -b;
	return *this;
}

vect2 vect2::operator+()
{
	return *this;
}





bool operator==(const vect2& other1, const vect2& other2)
{
	if (other1[0] == other2[0] || other1[1] == other2[1])
		return true;
	return false;
}

bool operator!=(const vect2& other1, const vect2& other2)
{
	if (other1[0] == other2[0] || other1[1] == other2[1])
		return false;
	return true;
}


std::ostream& operator<<(std::ostream& os, vect2 v)
{
	os << "{" << v[0] << ", " << v[1] << "}" << std::endl;
	return os;
}

vect2 operator*(int k, const vect2& other)
{
	vect2 temp(other);
	temp[0] *= k;
	temp[1] *= k;
	return temp;
}
