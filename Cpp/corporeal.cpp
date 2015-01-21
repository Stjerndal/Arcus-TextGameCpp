#include <string>
#include <iostream>
#include <memory>
#include <sstream>

#include "corporeal.h"
#include "dialog.h"
#include "item.h"
#include "userinterface.h"

namespace arcus {

	/*std::string skinColor;
	std::vector<Item> inventory;
	int strength;
	int agility;
	int intellect;
	int hp;*/


	Corporeal::Corporeal(const std::string _type, const std::string _name, const int _attitude,
			const std::string _skinColor, const int _strength, const int _agility,
			const int _intellect, const int _hp)
	: Actor(_type, _name, _attitude)
	, skinColor(_skinColor)
	, strength(_strength)
	, agility(_agility)
	, intellect(_intellect)
	, hp(_hp)
	{}

	Corporeal::Corporeal(const std::string _type, const std::string _name, const int _attitude,
			const std::vector<Dialog> _dialogs, const std::string _skinColor, const int _strength,
			const int _agility, const int _intellect, const int _hp)
	: Actor(_type, _name, _attitude, _dialogs)
	, skinColor(_skinColor)
	, strength(_strength)
	, agility(_agility)
	, intellect(_intellect)
	, hp(_hp)
	{}

	const std::string Corporeal::getSkinColor() const {
		return skinColor;
	}

	const int Corporeal::getStrength() const {
		return strength;
	}

	const int Corporeal::getAgility() const {
		return agility;
	}

	const int Corporeal::getIntellect() const {
		return intellect;
	}

	const int Corporeal::getHp() const {
		return hp;
	}

	void Corporeal::setSkinColor(std::string _skinColor) {
		skinColor = _skinColor;
	}

	void Corporeal::setStrength(int _strength) {
		strength = _strength;
	}

	void Corporeal::setAgility(int _agility) {
		agility = _agility;
	}

	void Corporeal::setIntellect(int _intellect) {
		intellect = _intellect;
	}

	void Corporeal::setHp(int _hp) {
		hp = _hp;
	}

	std::string Corporeal::attack(Corporeal& other) {
		std::cout << "Corporeal.attack()" << std::endl;
		int dmg = getDmg();
		other.takeDmg(*this, dmg);
		return attackString(other, dmg);
	}

	std::string Corporeal::attackString(Corporeal& other, int dmg) {
		std::ostringstream oss;
		oss << "The " << getType() << " pummels " << other.getType() << " for " << dmg << " damage!"
			<< "\n" << other.getType() << " has " << other.getHp() << "hp left!";
		return oss.str();
	}

	int Corporeal::getDmg() {
		return ((strength * 3) + agility )/ 2;
	}

	void Corporeal::takeDmg(Corporeal& other, int dmg) {
		hp -= dmg;
		if(hp <= 0) {
			hp = 0;
			die(other);
		}
	}

	void Corporeal::die(Corporeal& other) {
		std::cout << "Corporeal.die()" << std::endl;
		setAlive(false);
	}

	void Corporeal::consume(std::weak_ptr<Item> item) {
		std::cout << "Corporeal.consume()" << std::endl;
		//TODO
	}

	bool Corporeal::pick_up(std::weak_ptr<Item> item){
		std::cout << "Corporeal.pick_up()" << std::endl;
		inventory.push_back(item);
		return true;
	}

	void Corporeal::drop(std::weak_ptr<Item> item){
		std::cout << "Corporeal.drop()" << std::endl;
		//TODO
	}

	void Corporeal::talk_to(Actor& other) {
		getAnswerFromDialog(0);
	}

	std::string Corporeal::action(Actor& other) {
		std::cout << "Corporeal.action()" << std::endl;
		Corporeal* otherCorp =  dynamic_cast<Corporeal*>(&other);
      	if(otherCorp){
			if(!isAlive())
				return getName() + " the " + getType() + " is dead.";
			if(!otherCorp->isAlive())
				return "The " + other.getType() + " is already dead.";
			return attack(*otherCorp);
		}
		else {
			return "Can not take action against " + other.getType() + " - it's incorporeal!";
		}
	}


}
