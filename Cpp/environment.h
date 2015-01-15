#ifndef ARCUS_ENVIRONMENT_H
#define ARCUS_ENVIRONMENT_H

#include <string>
#include <vector>
#include <map>

//#include "actor.h"
#include "item.h"

namespace arcus {
	class Actor;
	//enum Direction_t {UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT, LEFT, UP_LEFT};
	enum Direction_t {NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST};

	class Environment {
	public:
		Environment();
		Environment(const std::string description);
		Environment(const std::string description, const std::vector<Item> items);
		Environment(const std::string description, const std::vector<Direction_t> directions,
			const std::map<Direction_t, Environment> neighbors, const std::vector<Item> items);


		const std::vector<Direction_t> getDirections() const;
		Environment getNeighbor(Direction_t);
		
		const std::string getDescription() const;
		void enter(Actor&);
		void leave(Actor&);
		void pick_up(Item);
		void addItem(Item);
		void drop(Item);
		void openDirection(Direction_t);
		void addNeighbor(Environment, Direction_t);
		virtual void affect(Actor&);
		const std::vector<Item>::iterator iteratorOf(const Item);
	private:
		std::string description;
		std::vector<Direction_t> directions;
		std::map<Direction_t, Environment> neighbors;
		std::vector<Item> items;
	};


}

#endif