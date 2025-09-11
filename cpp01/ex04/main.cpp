#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <cstring>

int	main(int argc, char **argv)
{
	std::string		input_text;
	std::string		output_text;

	//validating number of args
	if (argc != 4) {
		std::cout << "error: invalid number of arguments" << std::endl;
		return (1);}

	//setting variable values
	std::string str1 = argv[2];
	std::string str2 = argv[3];
	size_t len1 = str1.length();
	size_t startpos = 0;

	//validating search string
	if (str1.empty()) {
  		std::cerr << "sed: error: empty search string" << std::endl;
  	return (1);}

	//opening source file
	std::ifstream infile;
	infile.open(argv[1]);
	if (!infile.is_open()) {
		std::cerr << "sed: error opening " << argv[1] << ": "
		<< std::strerror(errno) << std::endl;
		return (1);}

	//reading from source file
	std::string line;
	while (getline(infile, line)) {
		input_text += line + "\n";}

	//check success of reading
	if (infile.bad()) {
    	std::cerr << "sed: I/O error while reading file: "
		<< std::strerror(errno) << std::endl;
		return (1);}
	else if (infile.fail() && !infile.eof()) {
    	std::cerr << "sed: undefined error while reading file" << std::endl;
		return (1);}
	infile.close();

	//substituition loop
	while (true) {
		size_t pos = input_text.find(str1, startpos);
		if (pos == std::string::npos)
			break;
		output_text += input_text.substr(startpos, pos - startpos);
		output_text += str2;
		startpos = pos + len1; }
	output_text += input_text.substr(startpos);

	//opening target file
	std::string filename = argv[1];
	filename += ".replace";
	std::ofstream outfile;
	outfile.open(filename.c_str());
	if (!outfile) {
		std::cerr << "sed: error writing to file" << std::endl;
		return (1);}	

	//writing to target file
	outfile << output_text;
	if (!outfile) {
		std::cerr << "sed: error writing to file" << std::endl;
		return (1);}
	
	outfile.close();
	return (0);	
}
