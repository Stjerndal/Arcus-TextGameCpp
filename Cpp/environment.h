#ifndef ARCUS_ENVI_H
#define ARCUS_ENVI_H

#include <string>
#include <vector>

namespace arcus {
	class Actor;
	class Item;

	enum direction_t {UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT, LEFT, UP_LEFT};

	class Environment {
	public:	
		const std::vector<direction_t> directions() const;
		const Environment neighbor(direction_t) const;
		void openDirection(direction_t);
		const std::string description() const;
		void enter(Actor);
		void leave(Actor);
		void pick_up(Item);
		void drop(Item);
		void affect(Actor actor);
	};


}

#endif