#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "userinterface.h"

void UserInterface::present(const std::string msg){
	std::cout << msg << std::endl;
}

std::vector<std::string> UserInterface::fetchInput(){
    std::cout << ">> ";
	std::string input;
	std::getline(std::cin, input);
	std::transform(input.begin(), input.end(), input.begin(), ::tolower);
	return split(input, ' ');
}

int UserInterface::fetchNumber(){
    int number;
    std::vector<std::string> input;
    while(1) {
            input = UserInterface::fetchInput();
            if(input.size() < 1) {
                std::cerr << "insize" << std::endl;
                continue;
            }
            std::stringstream convert(input[0]);
            if(!(convert >> number)) {
                std::cerr << "numconv" << std::endl;
                continue;
            }
            
            break;
    }

    return number;
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