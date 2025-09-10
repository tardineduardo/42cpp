#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int	main(int argc, char **argv)
{
	std::ifstream	inFile;
	std::string		content;
	std::string		newstr;
	std::string		line;
	size_t			len1;
	size_t			startpos;

	//checking number of args
	if (argc != 3) {
		std::cout << "invalid number of arguments" << std::endl;
		return (1);}

	//setting variable values
	std::string	str1(argv[2]);
	std::string	str2(argv[3]);
	len1 = str1.length();
	startpos = 0;
	inFile.open(argv[1]);

	//validating file open
	if (inFile.fail()) {
		std::cout << "error opening file" << std::endl;
		return (1);}

	//read from file
	while (getline(inFile, line)) {
		content += line + "\n";}
	inFile.close();

	while (true) {
		size_t pos = content.find(str1, startpos);
		if (pos == std::string::npos)
			break;
		newstr += content.substr(startpos, pos - startpos);
		newstr += str2;
		startpos = pos + len1; }
	newstr += content.substr(startpos);

	std::cout << newstr << std::endl;

}
