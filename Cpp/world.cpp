
#include <string>
#include <vector>

#include "world.h"
#include "actor.h"
#include "environment.h"

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

	}

	
}
