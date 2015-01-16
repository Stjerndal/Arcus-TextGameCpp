#ifndef ARCUS_UI
#define ARCUS_UI

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