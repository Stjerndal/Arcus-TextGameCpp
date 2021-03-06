#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

#include "world.h"
#include "actor.h"
#include "corporeal.h"
#include "human.h"
#include "orbis.h"
#include "robot.h"
#include "environment.h"
#include "outdoor.h"
#include "indoor.h"
#include "dialog.h"
#include "directions.hpp"
#include "userinterface.h"

namespace arcus {
	/*
	Corporeal player;
	std::shared_ptr<Environment> curEnvironment;*/

	World::World() 
	: player("You", "You", 30, "Brown", 50, 50, 50, 1000)
	, envs()
	, items()
	, actors()
	, curEnvironment()
	, running(0)
	, commands("(go xxx, take xxx, talk xxx, attack xxx)")
	{}


	void World::start() {
		UserInterface::present(std::string( 100, '\n' ));//visual effects(clear)
		UserInterface::present("**************************\n");
		UserInterface::present("Welcome to the game 'Arcus'!");
		UserInterface::present("Your spaceship has crashed in a dark forest on a remote and foreign planet!");
		UserInterface::present("In order fix the ship you need to find some fuel-cells.");
		UserInterface::present("\n**************************");
		curEnvironment = setupWorld();
		running = 1;
		while(running)
			update();
	}

	void World::update() {
		updateGoal();
		UserInterface::present("--------------------------\n");
		UserInterface::present(present());
		UserInterface::present("\n--------------------------");
		UserInterface::present("What do you do?" + commands);

		std::vector<std::string> input;
		input = UserInterface::fetchInput();
		UserInterface::present(std::string( 100, '\n' ));//visual effects(clear)
		handleInput(input);
		if(!player.isAlive())
			gameOver();

	}

	std::string World::present() const{
		return curEnvironment->present();
	}

	bool World::handleInput(const std::vector<std::string>& input) {
		if(input.size() < 1 ) { //0 commands
			return false;
		} else if (input.size() < 2) {//1 command
			if (input[0].compare(0,1,"q") == 0) { // QUIT
				running = 0;
				return true;
			}
		} else { // 2 or more commands
			if (input[0].compare(0,2,"go") == 0) { // GO
				Direction_t dir = convertDir(input[1]);
				if(dir != INVALID && curEnvironment->isDirectionOpen(dir)) {
					player.go(dir);
					curEnvironment = curEnvironment->getNeighbor(dir);
					return true;
				}
			} else if (input[0].compare(0,4,"take") == 0) { // TAKE
				std::weak_ptr<Item> item = curEnvironment->pick_up(input[1]);
				if(item.lock() && player.pick_up(item)) {
					UserInterface::present("Picked up " + input[1] + ".");
					if(item.lock()->getName() == "Fuel-cells") {
						gameWon();
					}
					return true;
				} else {
					UserInterface::present("Can't pick up " + input[1] + ".");
				}
			} else if (input[0].compare(0,4,"talk") == 0) { // TALK
				std::shared_ptr<Actor> actor = curEnvironment->getNpcByType(input[1]).lock();
				if(actor) {
					if(actor->isAlive()) {
						actor->talk_to(player);
						if(actor->getAttitude() > 90) //angry!
							UserInterface::present(actor->action(player)); // attack player!
					} else {
						UserInterface::present(actor->getType() + " is dead.");
					}
				} else {
					UserInterface::present("Can't talk with " + input[1] + ".");
				}
			} else if (input[0].compare(0,6,"attack") == 0) { // ATTACK
				std::shared_ptr<Actor> actor = curEnvironment->getNpcByType(input[1]).lock();
				if(actor) {
					UserInterface::present(player.action(*actor));
					UserInterface::present(actor->action(player));
				} else {
					UserInterface::present("Can't attack " + input[1] + ".");
				}
			}

		}

		return false;
	}

	void World::updateGoal() {
		if(player.hasGoalAccess() && !envs[6]->isDirectionOpen(SOUTH))
			envs[6]->openDirection(SOUTH);
	}

	void World::gameOver() {
		UserInterface::present("\n**************************\n");
		UserInterface::present("YOU JUST LOST THE GAME!");
		UserInterface::present("\n**************************");
		running = false;
	}

	void World::gameWon() {
		UserInterface::present("\n**************************\n");
		UserInterface::present("YOU JUST WON THE GAME!");
		UserInterface::present("\n**************************");
		running = false;
	}


	std::shared_ptr<Environment> World::setupWorld() {
		auto fuelCell = std::make_shared<Item>("Fuel-cells", 100, 5, 42000, "Black", "Fuel cells needed for hyperspace travel.");
		auto berries = std::make_shared<Item>("Blueberries", 1, 1, 10, "Blue", "Small edible berries.");
		auto stone = std::make_shared<Item>("Stone", 70, 4, 3, "Grey", "A small stone.");

		std::vector<std::string> bearAnswers;
		bearAnswers.push_back("Hey bear!");
		Dialog bearDialog("Zzzz", bearAnswers);
		std::vector<Dialog> bearDialogs;
		bearDialogs.push_back(bearDialog);

		//Corporeal bear("Bear", "Jebo", 40, bearDialogs, "Brown", 70, 30, 10, 200);
		auto bear = std::make_shared<Corporeal>("Bear", "Jebo", 95, bearDialogs, "Brown", 80, 50, 10, 250);

		std::vector<std::string> elephantAnswers;
		elephantAnswers.push_back("Hey elephant!");
		Dialog elephantDialog("*Toerroeee!!*", elephantAnswers);
		std::vector<Dialog> elephantDialogs;
		elephantDialogs.push_back(elephantDialog);

		auto elephant = std::make_shared<Corporeal>("Elephant", "Frank", 40, elephantDialogs, "Grey", 90, 50, 90, 350);

		std::vector<std::string> robotAnswers1;
		robotAnswers1.push_back("U ugly");
		robotAnswers1.push_back("In peace, I come.");
		Dialog robotDialog1("U wot mate?", robotAnswers1);
		std::vector<std::string> robotAnswers2;
		robotAnswers2.push_back("Hmkay, thanks I guess.");
		Dialog robotDialog2("Ok, I'll tell Gandalf.", robotAnswers2);
		std::vector<Dialog> robotDialogs;
		robotDialogs.push_back(robotDialog1);
		robotDialogs.push_back(robotDialog2);

		auto robot = std::make_shared<Robot>("robot", "Harry", 40, robotDialogs, "Silver", 50, 30, 70, 300);

		std::vector<std::string> orbisAnswers1;
		orbisAnswers1.push_back("Mountains");
		orbisAnswers1.push_back("Flowers");
		orbisAnswers1.push_back("Rivers");
		orbisAnswers1.push_back("Llamas");
		Dialog orbisDialog1("What can run but never walks, has a mouth but never talks, has a bed but never sleeps, has a head but never weeps?", orbisAnswers1);
		std::vector<std::string> orbisAnswers2;
		orbisAnswers2.push_back("Cool cool.");
		Dialog orbisDialog2("Righto! I'll tell Gandalf!", orbisAnswers2);
		std::vector<std::string> orbisAnswers3;
		orbisAnswers3.push_back("Shit.");
		Dialog orbisDialog3("Wrongo!", orbisAnswers3);
		std::vector<Dialog> orbisDialogs;
		orbisDialogs.push_back(orbisDialog1);
		orbisDialogs.push_back(orbisDialog2);
		orbisDialogs.push_back(orbisDialog3);

		auto orbis = std::make_shared<Orbis>("Orbis", "James", 40, orbisDialogs, "White", 40, 70, 80, 250);

		std::vector<std::string> gandalfAnswers1;
		gandalfAnswers1.push_back("Ok.");
		Dialog gandalfDialog1("You shall not pass.", gandalfAnswers1);
		std::vector<std::string> gandalfAnswers2;
		gandalfAnswers2.push_back("Cool cool.");
		Dialog gandalfDialog2("You shall pass.", gandalfAnswers2);
		std::vector<Dialog> gandalfDialogs;
		gandalfDialogs.push_back(gandalfDialog1);
		gandalfDialogs.push_back(gandalfDialog2);;

		auto gandalf = std::make_shared<Human>("Human", "Gandalf", 40, gandalfDialogs, "Blue", 70, 50, 40, 400);

		auto forest1 = std::make_shared<Outdoor>("A dark and gloomy forest.", SUNNY, "Dark Blue");
		forest1->addItem(berries);

		auto forest2 = std::make_shared<Outdoor>("The forest here is actually pretty dark.", RAINY, "Black");
		forest2->addNpc(bear);

		auto glade = std::make_shared<Outdoor>("A glade in the forest, this area is cleared of trees. To the east you see a tunnel.", SUNNY, "Dark Blue");
		glade->addItem(stone);
		glade->addNpc(orbis);

		auto fields1 = std::make_shared<Outdoor>("Vast grass fields. To the west you see the forest.", SUNNY, "Blue");

		auto fields2 = std::make_shared<Outdoor>("Vast grass fields. To the south you see a tunnel", SUNNY, "Blue");
		fields2->addNpc(elephant);

		auto tunnel = std::make_shared<Indoor>("A dark tunnel.", 3);
		tunnel->addNpc(robot);

		auto mountain = std::make_shared<Outdoor>("Mountains surround you. To the south you see an opening to a cave.", SNOWY, "White");
		mountain->addNpc(gandalf);

		auto cave = std::make_shared<Indoor>("A small cave", 5);
		cave->addItem(fuelCell);

		forest1->addNeighbor(fields1, EAST);
		forest1->openDirection(EAST);
		forest1->addNeighbor(forest2, SOUTH);
		forest1->openDirection(SOUTH);

		forest2->addNeighbor(forest1, NORTH);
		forest2->openDirection(NORTH);
		forest2->addNeighbor(fields2, EAST);
		forest2->openDirection(EAST);
		forest2->addNeighbor(glade, SOUTH);
		forest2->openDirection(SOUTH);

		fields1->addNeighbor(forest1, WEST);
		fields1->openDirection(WEST);
		fields1->addNeighbor(fields2, SOUTH_EAST);
		fields1->openDirection(SOUTH_EAST);

		fields2->addNeighbor(fields1, NORTH_WEST);
		fields2->openDirection(NORTH_WEST);
		fields2->addNeighbor(forest2, WEST);
		fields2->openDirection(WEST);
		fields2->addNeighbor(tunnel, SOUTH);
		fields2->openDirection(SOUTH);

		glade->addNeighbor(forest2, NORTH);
		glade->openDirection(NORTH);
		glade->addNeighbor(tunnel, EAST);
		glade->openDirection(EAST);
		glade->addNeighbor(mountain, SOUTH_EAST);
		glade->openDirection(SOUTH_EAST);

		tunnel->addNeighbor(fields2, NORTH);
		tunnel->openDirection(NORTH);
		tunnel->addNeighbor(glade, WEST);
		tunnel->openDirection(WEST);
		tunnel->addNeighbor(mountain, SOUTH_WEST);
		tunnel->openDirection(SOUTH_WEST);

		mountain->addNeighbor(glade, NORTH_WEST);
		mountain->openDirection(NORTH_WEST);
		mountain->addNeighbor(tunnel, NORTH_EAST);
		mountain->openDirection(NORTH_EAST);
		mountain->addNeighbor(cave, SOUTH);

		cave->addNeighbor(mountain, NORTH);
		cave->openDirection(NORTH);

		envs.push_back(forest1);
 		envs.push_back(forest2);
 		envs.push_back(fields1);
 		envs.push_back(fields2);
 		envs.push_back(glade);
 		envs.push_back(tunnel);
 		envs.push_back(mountain);
		envs.push_back(cave);

		items.push_back(fuelCell);
 		items.push_back(berries);
 		items.push_back(stone);

 		actors.push_back(bear);
 		actors.push_back(elephant);
 		actors.push_back(orbis);
 		actors.push_back(robot);
		actors.push_back(gandalf);


		return forest1;
	}

	
	
}
