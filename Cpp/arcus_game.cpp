#include <string>

#include "userinterface.h"
#include "world.h"


std::string msg = "What do you do?";



void update(arcus::World& world) {
	/*UserInterface::present(world.present());
	UserInterface::present(msg);
	std::vector<std::string> input;
	input = UserInterface::fetchInput();
	world.handleInput(input);*/
	//UserInterface::present(input + " <- thats what you wrote!");
}

void start() {

	arcus::World world;

/*
	while(1)
		update(world);*/
	world.start();

}

int main() {
	start();	
}