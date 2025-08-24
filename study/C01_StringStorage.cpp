#include <string>
#include <iostream>

int main() {
	std::string s1("12345");					// Set the iterator indicate the first element   
	std::string::iterator it = s1.begin();		// This may copy the first to the second or    
												// use reference counting to simulate a copy    
	std::string s2 = s1;						// Either way, this statement may ONLY modify first   
	*it = '0';
	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
}
