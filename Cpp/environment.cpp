#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <memory>

#include "environment.h"
#include "actor.h"
#include "item.h"
#include "dialog.h"

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
	, npcs()
	, status()
	{}


	Environment::Environment(const std::string _description)
	: description(_description)
	, directions()
	, neighbors()
	, items()
	, npcs()
	, status()
	{}

	Environment::Environment(const std::string _description, const std::vector<std::weak_ptr<Item>> _items)
	: description(_description)
	, directions()
	, neighbors()
	, items(_items)
	, npcs()
	, status()
	{}

	Environment::Environment(const std::string _description, const std::vector<Direction_t> _directions,
		const std::map<Direction_t, std::weak_ptr<Environment>> _neighbors, const std::vector<std::weak_ptr<Item>> _items)
	: description(_description)
	, directions(_directions)
	, neighbors(_neighbors)
	, items(_items)
	, npcs()
	, status()
	{}

	const std::vector<Direction_t> Environment::getDirections() const {
		return directions;
	}

	std::shared_ptr<Environment> Environment::getNeighbor(Direction_t _direction){
		return neighbors[_direction].lock();
	}
	
	std::vector<Actor> Environment::getNpcs() const {
		return npcs;
	}
	
	const std::string Environment::getDescription() const {
		return description;
	}
	
	std::string Environment::getStatus() {
		std::string oldStatus = status;
		status = "";
		return oldStatus;
	}

	void Environment::enter(Actor& actor) {
		std::cout << "Environment.enter(" << actor.getName() << ")" << std::endl;
	}
	
	void Environment::leave(Actor& actor) {
		std::cout << "Environment.leave(" << actor.getName() << ")" << std::endl;
	}
	
	void Environment::pick_up(std::weak_ptr<Item> item) {
		items.erase(iteratorOf(item));
	}

	std::weak_ptr<Item> Environment::pick_up(std::string itemName) {
		/*std::transform(itemName.begin(), itemName.end(), itemName.begin(), ::tolower);
		std::string tmpName;
		auto it = items.begin();
		for(; it != items.end(); ++it) {
			tmpName = it->getName();
			std::transform(tmpName.begin(), tmpName.end(), tmpName.begin(), ::tolower);
			std::cout << "Itemname: " << itemName << " getName(): " << tmpName << std::endl;
			if(itemName == tmpName) 
				break;
		}
		if(it != items.end()) {
			Item item = *it;
			std::cerr << "derp" << std::endl;
			items.erase(it);
			std::cerr << "herp" << std::endl;
			return item;
		} else 
			Item item;
			return nullptr;*/
	}

	void Environment::addItem(std::weak_ptr<Item> item) {
		items.push_back(item);
	}
	
	void Environment::drop(std::shared_ptr<Item> item) {
		std::cout << "Environment.drop(" << item->getName() << ")" << std::endl;
		addItem(item);
	}

	void Environment::openDirection(Direction_t direction) {
		//std::cout << description << ".openDirection(" << convertDir(direction) << ")" << std::endl;
		directions.push_back(direction);
	}

	void Environment::addNeighbor(std::weak_ptr<Environment> neighbor, Direction_t direction) {
		//std::cout << description << ".addNeighbor(" << neighbor.getDescription() << ", " << convertDir(direction) << ")" << std::endl;
		neighbors.emplace(direction, neighbor);
	}

	void Environment::addNpc(Actor npc) {
		//std::cout << "Environment.addNpc(" << npc.getName() << ")" << std::endl;
		npcs.push_back(npc);
	}

	bool Environment::isDirectionOpen(Direction_t direction) const {
		for(auto it = directions.begin(); it != directions.end(); ++it) {
			if(*it == direction)
				return true;
		}
		return false;
	}

	
	std::string Environment::present() const {
		std::string presentation;
		presentation.append(description);
		presentation.append("\nOpen directions: ");
		for(auto it = directions.begin(); it != directions.end(); ++it) {
			presentation.append(convertDir(*it)).append(" ");
		}
		presentation.append("\nYou see:");
		for(auto it = items.begin(); it != items.end(); ++it) {
			presentation.append(" ITEM: ").append((*it).lock()->getName());
		}
		for(auto it = npcs.begin(); it != npcs.end(); ++it) {
			presentation.append(" CREATURE: ").append((*it).getType());
		}
		return presentation;
	}
	
	void Environment::affect(Actor& actor) {
		std::cout << "Environment.affect(" << actor.getName() << ")" << std::endl;
	}
	
	const std::vector<std::weak_ptr<Item>>::iterator Environment::iteratorOf(const std::weak_ptr<Item> item) {
		return std::find(items.begin(), items.end(), item);
	}
		



}