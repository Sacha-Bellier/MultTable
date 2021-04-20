
#include <iostream>
#include <sstream>
#include "MultTable.h"


int main(int argc, char **argv) {
	if(argc != 3) {
		std::cout << "\033[1;31mInvalid input : ./MultTable arg1 arg2\n";
		std::cout << "\033[0;31m- arg1 : (Integer) The number to reach program will perform algorithm from 0 to this number\n";
		std::cout << "- arg2 : (true/false) true if you want that the program show all lines that are equals, false else\033[0m\n";
		return 0;
	}
	std::stringstream str(argv[1]);
	uint32_t i;
	str >> i;
	bool b = false;
	std::string s(argv[2]);
	if(s.find("true") != std::string::npos)
		b = true;
	Run(i, b);
	return 1;
}

