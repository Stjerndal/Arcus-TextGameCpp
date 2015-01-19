#ifndef ARCUS_WORLD
#define ARCUS_WORLD

#include <vector>
#include <string>

#include "actor.h"
#include "environment.h"

namespace arcus {

	class World {

	public:
		World();

		std::string present(const std::string msg);

		Environment setupWorld();

	
	private:
		Actor player;
		Environment curEnvironment;
	};
	
}
#endif