#ifndef ARCUS_UI
#define ARCUS_UI

#include <vector>
#include <string>


namespace arcus {

	class Actor;
	class Environment;
	class World {

	public:
		static std::string present(const std::string msg);
	

	private:
		std::vector<Actor> npcs;
		Actor player;
		Environment curEnvironment;
	};
	
}
#endif