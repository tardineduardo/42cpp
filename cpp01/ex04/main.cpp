#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int	main(int argc, char **argv)
{
	std::string		contentsrc;
	std::string		contentdst;

	//checking number of args
	if (argc != 4) {
		std::cout << "invalid number of arguments" << std::endl;
		return (1);}

	//setting variable values
	std::string str1 = argv[2];
	std::string str2 = argv[3];
	size_t len1 = str1.length();
	size_t startpos = 0;

	//validating file open
	std::ifstream inflile;
	inflile.open(argv[1]);
	if (inflile.fail()) {
		std::cout << "error reading from file" << std::endl;
		return (1);}

	//read from file
	std::string line;
	while (getline(inflile, line)) {
		contentsrc += line + "\n";}
	inflile.close();

	//substituition loop
	while (true) {
		size_t pos = contentsrc.find(str1, startpos);
		if (pos == std::string::npos)
			break;
		contentdst += contentsrc.substr(startpos, pos - startpos);
		contentdst += str2;
		startpos = pos + len1; }
	contentdst += contentsrc.substr(startpos);

	//open outfile
	std::ofstream outflile;
	outflile.open(argv[1]);
	if (outflile.fail()) {
		std::cout << "error writing to file" << std::endl;
		return (1);}	

	//write to outfile
	outflile << contentdst;
	if (outflile.fail()) {
		std::cout << "error writing to file" << std::endl;
		return (1);}
	
	outflile.close();
	return (0);	
}
