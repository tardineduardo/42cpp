#include <iostream>

void function1(int x)
{
	std::cout << "start function 1" << std::endl;
	std::cout << x << std::endl;
}

void function2(int& x)
{
	std::cout << "start function 2" << std::endl;

	x++;
	std::cout << &x << std::endl;
	std::cout << x << std::endl;
}


void function3(int *x)
{
	std::cout << "start function 3" << std::endl;

	std::cout << std::endl << "1." << std::endl;
	(*x)++;
	std::cout << &(*x) << std::endl;
	std::cout << *x << std::endl;
	std::cout << &x << std::endl;
	std::cout << x << std::endl;

	std::cout << std::endl << "2." << std::endl;
	*x++;
	std::cout << &(*x) << std::endl;
	std::cout << *x << std::endl;
	std::cout << &x << std::endl;
	std::cout << x << std::endl;

	std::cout << std::endl << "3." << std::endl;
	x++;
	std::cout << &(*x) << std::endl;
	std::cout << *x << std::endl;
	std::cout << &x << std::endl;
	std::cout << x << std::endl;

}


int main(void)
{
	int a;
	int b;
	int c;

	void(*fct1)(int);
	void(*fct2)(int&);
	void(*fct3)(int*);

	fct1 = function1;
	fct2 = function2;
	fct3 = function3;	

	a = 5;
	b = 5;

	std::cout << std::endl << std::endl << b << std::endl;

	fct3(&b);
	std::cout << std::endl << std::endl << b << std::endl;

	

	return 0;    
}