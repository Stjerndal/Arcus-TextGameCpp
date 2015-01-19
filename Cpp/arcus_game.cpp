#include <string>

#include "userinterface.hpp"
#include "world.h"

std::string msg = "Derpa lingonflerpa...";

void update() {

	UserInterface::present(msg);
	std::string input;
	input = UserInterface::fetchInput();
	UserInterface::present(input + " <- thats what you wrote!");
}

int main() {
	arcus::World world();

	while(1)
		update();
}