#ifndef ARCUS_ENVIRONMENT_H
#define ARCUS_ENVIRONMENT_H

#include <string>
#include <vector>
#include <map>

namespace arcus {
	class Actor;
	class Item;

	enum Direction_t {UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT, LEFT, UP_LEFT};

	class Environment {
	public:	
		const std::vector<Direction_t> getDirections() const;
		const Environment getNeighbor(Direction_t) const;
		void openDirection(Direction_t);
		const std::string getDescription() const;
		void enter(Actor);
		void leave(Actor);
		void pick_up(Item);
		void drop(Item);
		virtual void affect(Actor actor);
	private:
		std::string description;
		std::vector<Direction_t> directions;
		std::map<Direction_t, Environment> neighbors;
		std::vector<Item> items;
	};


}

#endif