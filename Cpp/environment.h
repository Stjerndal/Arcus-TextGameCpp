#ifndef ARCUS_ENVIRONMENT_H
#define ARCUS_ENVIRONMENT_H

#include <string>
#include <vector>
#include <map>

#include "actor.h"
#include "item.h"
#include "directions.hpp"

namespace arcus {
	class Actor;

	class Environment {
	public:
		Environment();
		~Environment();
		//Environment(const Environment& other); //copy constructor
		//Environment& operator= (const Environment& other); //copy assignment operator

		Environment(const std::string description);
		Environment(const std::string description, const std::vector<Item> items);
		Environment(const std::string description, const std::vector<Direction_t> directions,
			const std::map<Direction_t, Environment*> neighbors, const std::vector<Item> items);


		const std::vector<Direction_t> getDirections() const;
		Environment* getNeighbor(Direction_t);
		std::vector<Actor> getNpcs() const;
		std::string getStatus();
		
		const std::string getDescription() const;
		void enter(Actor&);
		void leave(Actor&);
		void pick_up(Item);
		void addItem(Item);
		void drop(Item);
		void openDirection(Direction_t);
		void addNeighbor(Environment*, Direction_t);
		void addNpc(Actor);

		bool isDirectionOpen(Direction_t) const;

		virtual void affect(Actor&);
		virtual std::string present() const;
		const std::vector<Item>::iterator iteratorOf(const Item);
	private:
		std::string description;
		std::vector<Direction_t> directions;
		std::map<Direction_t, Environment*> neighbors;
		std::vector<Item> items;
		std::vector<Actor> npcs;
		std::string status;
	};


}

#endif