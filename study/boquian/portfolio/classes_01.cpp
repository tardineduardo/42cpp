#include <iostream>
#include <string>

using namespace std;

class BankAccont {
	public:
		int		balance;
		string	name;

};

int main(void)
{
	BankAccont account1;
	account1.name = "Eduardo";
	return (0);	
}