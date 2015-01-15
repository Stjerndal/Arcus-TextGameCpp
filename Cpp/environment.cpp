#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

#include "environment.h"
#include "actor.h"
#include "item.h"

namespace arcus {

	/*std::string description;
	std::vector<Direction_t> directions;
	std::map<Direction_t, Environment> neighbors;
	std::vector<Item> items;*/

	Environment::Environment()
	: description("default environment")
	, directions()
	, neighbors()
	, items()
	{}

	Environment::Environment(const std::string _description)
	: description(_description)
	, directions()
	, neighbors()
	, items()
	{}

	Environment::Environment(const std::string _description, const std::vector<Item> _items)
	: description(_description)
	, directions()
	, neighbors()
	, items(_items)
	{}

	Environment::Environment(const std::string _description, const std::vector<Direction_t> _directions,
		const std::map<Direction_t, Environment> _neighbors, const std::vector<Item> _items)
	: description(_description)
	, directions(_directions)
	, neighbors(_neighbors)
	, items(_items)
	{}

	const std::vector<Direction_t> Environment::getDirections() const {
		return directions;
	}

	Environment Environment::getNeighbor(Direction_t _direction){
		return neighbors[_direction];
	}
	
	
	
	const std::string Environment::getDescription() const {
		return description;
	}
	
	void Environment::enter(Actor& actor) {
		std::cout << "Environment.enter(" << actor.getName() << ")" << std::endl;
	}
	
	void Environment::leave(Actor& actor) {
		std::cout << "Environment.leave(" << actor.getName() << ")" << std::endl;
	}
	
	void Environment::pick_up(Item item) {
		items.erase(iteratorOf(item));
	}

	void Environment::addItem(Item item) {
		items.push_back(item);
	}
	
	void Environment::drop(Item item) {
		std::cout << "Environment.drop(" << item.getName() << ")" << std::endl;
		addItem(item);
	}

	void Environment::openDirection(Direction_t direction) {
		std::cout << "Environment.openDirection()" << std::endl;
		directions.push_back(direction);
	}

	void Environment::addNeighbor(Environment neighbor, Direction_t direction) {
		std::cout << "Environment.addNeighbor()" << std::endl;
		neighbors.emplace(direction, neighbor);
	}
	
	void Environment::affect(Actor& actor) {
		std::cout << "Environment.affect(" << actor.getName() << ")" << std::endl;
	}
	
	const std::vector<Item>::iterator Environment::iteratorOf(const Item item) {
		return std::find(items.begin(), items.end(), item);
	}
		



}