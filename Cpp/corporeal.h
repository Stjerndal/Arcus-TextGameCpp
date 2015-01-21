#ifndef ARCUS_CORPOREAL_H
#define ARCUS_CORPOREAL_H

#include <string>
#include <vector>
#include <memory>

#include "actor.h"

namespace arcus {
	class Actor;
	class Item;
	class Dialog;
	class Corporeal: public Actor {
	public:
		Corporeal(const std::string _type, const std::string _name, const int _attitude,
			const std::string _skinColor, const int _strength, const int _agility,
			const int _intellect, const int _hp);
		Corporeal(const std::string _type, const std::string _name, const int _attitude,
			const std::vector<Dialog> _dialogs, const std::string _skinColor, const int _strength,
			const int _agility, const int _intellect, const int _hp);

		std::string getSkinColor() const;
		std::vector<std::weak_ptr<Item>> getInventory() const;
		int getStrength() const;
		int getAgility() const;
		int getIntellect() const;
		int getHp() const;

		void setSkinColor(std::string);
		void setInventory(std::vector<std::weak_ptr<Item>>);
		void setStrength(int);
		void setAgility(int);
		void setIntellect(int);
		void setHp(int);

		std::string attack(Corporeal&);
		virtual std::string attackString(Corporeal&, int) const;
		virtual int getDmg();
		void takeDmg(Corporeal&, int);
		virtual void die(Corporeal&);
		virtual void consume(std::weak_ptr<Item>);
		bool pick_up(std::weak_ptr<Item>);
		void drop(std::weak_ptr<Item>);

		virtual void talk_to(Actor&);
		virtual std::string action(Actor&);

	private:
		std::string skinColor;
		std::vector<std::weak_ptr<Item>> inventory;
		int strength;
		int agility;
		int intellect;
		int hp;
	};


}

#endif