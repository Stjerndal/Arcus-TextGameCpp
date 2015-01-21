#ifndef ARCUS_WORLD
#define ARCUS_WORLD

#include <vector>
#include <string>
#include <memory>

#include "corporeal.h"
#include "environment.h"
#include "human.h"

namespace arcus {

	class World {

	public:
		World();

		void start();

		void update();

		std::string present() const;

		bool handleInput(const std::vector<std::string>&);

		void updateGoal();

		void gameOver();
		void gameWon();

		//Environment* setupWorld();
		std::shared_ptr<Environment> setupWorld();



	
	private:
		Human player;
		//Environment* curEnvironment;
		std::shared_ptr<Environment> curEnvironment;
		std::vector<std::shared_ptr<Environment>> envs;
		std::vector<std::shared_ptr<Item>> items;
		std::vector<std::shared_ptr<Actor>> actors;
		std::string commands;
		bool running;
	};
	
}
#endif