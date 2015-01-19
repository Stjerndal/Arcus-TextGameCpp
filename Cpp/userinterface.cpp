#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "userinterface.h"

void UserInterface::present(const std::string msg){
	std::cout << msg << std::endl;
}

std::vector<std::string> UserInterface::fetchInput(){
	std::string input;
	std::getline(std::cin, input);
	std::transform(input.begin(), input.end(), input.begin(), ::tolower);
	return split(input, ' ');
}

std::vector<std::string>& UserInterface::split(const std::string& s, char delimeter, std::vector<std::string>& substrings) {
    std::stringstream ss(s);
    std::string substring;
    while (std::getline(ss, substring, delimeter)) {
        substrings.push_back(substring);
    }
    return substrings;
}


std::vector<std::string> UserInterface::split(const std::string& s, char delimeter) {
    std::vector<std::string> substrings;
    split(s, delimeter, substrings);
    return substrings;
}