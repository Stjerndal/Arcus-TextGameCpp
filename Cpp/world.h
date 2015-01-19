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

		~World();

		World (const World& other); //copy constructor

		World& operator= (const World& other); //copy assignment operator

		void start();

		void update();

		std::string present() const;

		bool handleInput(const std::vector<std::string>&);

		Environment* setupWorld();



	
	private:
		Actor player;
		Environment* curEnvironment;
		std::vector<Environment*> envs;
	};
	
}
#endif