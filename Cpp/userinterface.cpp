#include <iostream>
#include <string>

#include "userinterface.hpp"

void UserInterface::present(const std::string msg){
	std::cout << msg << std::endl;
}

std::string UserInterface::fetchInput(){
	std::string input;
	std::getline(std::cin, input);
	return input;
}