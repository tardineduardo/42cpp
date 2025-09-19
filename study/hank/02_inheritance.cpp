#include <iostream>

//base class
class Foo {
	private:
		int x;

	protected;

	public:
		Foo() {x = 0;}
		void setX(int _x) {x = _x;}
		int getX() const {return x;}
};

//derived class
class Bar : public Foo {
	public:
	Bar() {setX(8);}

};

int main(void)
{

	Bar test;


	test.setX(1);



}