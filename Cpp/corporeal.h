#ifndef ARCUS_CORPOREAL_H
#define ARCUS_CORPOREAL_H

#include <string>

namespace arcus {
	class Actor;
	class Item;
	class Corporeal: public Actor {
	public:
		const std::string getSkinColor() const;
		const std::vector<Item> getInventory() const;
		const int getStrength() const;
		const int getAgility() const;
		const int getIntellect() const;
		const int getHp() const;

		void setSkinColor(std::string);
		void setInventory(std::vector<Item>);
		void setStrength(int);
		void setAgility(int);
		void setIntellect(int);
		void setHp(int);

		virtual void fight(Corporeal);
		virtual void die();
		virtual void consume(Item);
		bool pick_up(Item);
		void drop(Item);

	private:
		std::string skinColor;
		std::vector<Item> inventory;
		int strength;
		int agility;
		int intellect;
		int hp;
	};


}

#endif