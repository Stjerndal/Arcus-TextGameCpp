
#include <string>
#include <vector>

#include "world.h"
#include "actor.h"
#include "environment.h"
#include "dialog.h"

namespace arcus {
	/*
	Actor player;
	Environment curEnvironment;*/

	World::World() 
	: player("Human", "Marcus", 30)
	{
		setupWorld();
	}

	std::string World::present(const std::string msg) {
		return "WORLD PRESENTATION";
	}

	Environment World::setupWorld() {
		Item fuelCell("Fuel Cells", 100, 5, 42000, "Black", "Fuel cells needed for hyperspace travel.");
		Item berries("Blueberries", 1, 1, 10, "Blue", "Small edible berries.");
		Item stone("Stone", 70, 4, 3, "Grey", "A small stone.");

		std::vector<std::string> bearAnswers;
		bearAnswers.push_back("Hey bear!");
		Dialog bearDialog("Zzzz", bearAnswers);
		std::vector<Dialog> bearDialogs;
		bearDialogs.push_back(bearDialog);

		Actor bear("Bear", "Jebo", 40, bearDialogs);

	}

	
}
