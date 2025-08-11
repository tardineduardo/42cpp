#include <iostream>

int main(int argc, char **argv)
{
	(void)argc;


	std::cout<<"Hello World!"<<std::endl;
	std::string name = "Eduardo";
	std::cout<<name<<std::endl;

	for (int i = 0; argv[i]; i++)
		std::cout<<argv[i]<<std::endl;



	return (0);
}