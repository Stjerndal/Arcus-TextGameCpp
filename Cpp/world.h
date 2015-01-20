#ifndef ARCUS_WORLD
#define ARCUS_WORLD

#include <vector>
#include <string>
#include <memory>

#include "corporeal.h"
#include "environment.h"

namespace arcus {

	class World {

	public:
		World();

		void start();

		void update();

		std::string present() const;

		bool handleInput(const std::vector<std::string>&);

		//Environment* setupWorld();
		std::shared_ptr<Environment> setupWorld();



	
	private:
		Corporeal player;
		//Environment* curEnvironment;
		std::shared_ptr<Environment> curEnvironment;
		std::vector<std::shared_ptr<Environment>> envs;
		std::vector<std::shared_ptr<Item>> items;
		std::vector<std::shared_ptr<Actor>> actors;
		bool running;
	};
	
}
#endif