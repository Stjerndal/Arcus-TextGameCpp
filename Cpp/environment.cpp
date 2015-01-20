#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

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

	Environment::~Environment() { //destructor
		for(auto it = neighbors.begin(); it != neighbors.end(); ++it) {
        	delete it->second; //second element in map is pointer
    	}
	};

/*
	//Copy Constructor 
    Environment::Environment(const Environment& other) 
	: description(other.description)
	, directions(other.directions)
	, neighbors()
	, items(other.items)
	, npcs(other.npcs)
	, status(other.status)
    {
    	for (std::size_t i = 0; i < other.envs.size(); ++i) 
        	envs[i] = new Environment(*other.envs[i]);

        for(auto it = neighbors.begin(); it != neighbors.end(); ++it) {
        	Environment* tmpEnv = new Environment()
        	delete it->second; //second element in map is pointer
    	}
    }*/

	Environment::Environment(const std::string _description)
	: description(_description)
	, directions()
	, neighbors()
	, items()
	, npcs()
	, status()
	{}

	Environment::Environment(const std::string _description, const std::vector<Item> _items)
	: description(_description)
	, directions()
	, neighbors()
	, items(_items)
	, npcs()
	, status()
	{}

	Environment::Environment(const std::string _description, const std::vector<Direction_t> _directions,
		const std::map<Direction_t, Environment*> _neighbors, const std::vector<Item> _items)
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

	Environment* Environment::getNeighbor(Direction_t _direction){
		return neighbors[_direction];
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
		//std::cout << description << ".openDirection(" << convertDir(direction) << ")" << std::endl;
		directions.push_back(direction);
	}

	void Environment::addNeighbor(Environment* neighbor, Direction_t direction) {
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
			presentation.append(" ITEM: ").append((*it).getName());
		}
		for(auto it = npcs.begin(); it != npcs.end(); ++it) {
			presentation.append(" CREATURE: ").append((*it).getType());
		}

		return presentation;
	}
	
	void Environment::affect(Actor& actor) {
		std::cout << "Environment.affect(" << actor.getName() << ")" << std::endl;
	}
	
	const std::vector<Item>::iterator Environment::iteratorOf(const Item item) {
		return std::find(items.begin(), items.end(), item);
	}
		



}