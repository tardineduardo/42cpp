#include <iostream>



template <typename T, int length>
class Array
{
	public:
		T array[length];
		void fill(T value)
		{
			for (int i = 0; i < length; i++)
				array[i] = value;
		}
		T& at(int index)
		{
			return array[index];
		}
};



int main(void)
{
	Array<int, 5> intArr;
	Array<std::string, 50> strArr;


	intArr.fill(2);
	std::cout << "intArray[4]: " << intArr.at(4) <<std::endl;  


	strArr.fill("Eduardo");
	std::cout << "strArray[4]: " << strArr.at(4) <<std::endl;  



	return 0;
}