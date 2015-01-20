#ifndef ARCUS_ENVIRONMENT_H
#define ARCUS_ENVIRONMENT_H

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "actor.h"
#include "item.h"
#include "directions.hpp"

namespace arcus {
	class Actor;

	class Environment {
	public:
		Environment();

		Environment(const std::string description);
		Environment(const std::string description, const std::vector<std::weak_ptr<Item>> items);
		Environment(const std::string description, const std::vector<Direction_t> directions,
			const std::map<Direction_t, std::weak_ptr<Environment>> neighbors, const std::vector<std::weak_ptr<Item>> items);


		const std::vector<Direction_t> getDirections() const;
		std::shared_ptr<Environment> getNeighbor(Direction_t);
		std::vector<std::weak_ptr<Actor>> getNpcs() const;
		std::string getStatus();
		const std::string getDescription() const;

		void enter(std::weak_ptr<Actor>);
		void leave(std::weak_ptr<Actor>);
		void pick_up(std::weak_ptr<Item>);
		std::weak_ptr<Item> pick_up(std::string);
		void addItem(std::weak_ptr<Item>);
		void drop(std::shared_ptr<Item>);
		void openDirection(Direction_t);
		void addNeighbor(std::weak_ptr<Environment>, Direction_t);
		void addNpc(std::weak_ptr<Actor>);

		bool isDirectionOpen(Direction_t) const;

		virtual void affect(std::weak_ptr<Actor>);
		virtual std::string present() const;
		//const std::vector<std::weak_ptr<Item>>::iterator iteratorOf(const std::weak_ptr<Item>);
	private:
		std::string description;
		std::vector<Direction_t> directions;
		std::map<Direction_t, std::weak_ptr<Environment>> neighbors;
		std::vector<std::weak_ptr<Item>> items;
		std::vector<std::weak_ptr<Actor>> npcs;
		std::string status;
	};


}

#endif