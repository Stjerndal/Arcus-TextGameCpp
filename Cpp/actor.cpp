#include <string>
#include <iostream>

#include "actor.h"
#include "dialog.h"

namespace arcus {

	/*std::string type;
	std::string name;
	int attitude;
	std::vector<Dialog> dialogs;*/

	Actor::Actor()
	: type()
	, name()
	, attitude()
	, status()
	{}

	Actor::Actor(const std::string _type, const std::string _name, const int _attitude)
	: type(_type)
	, name(_name)
	, attitude(_attitude)
	, status()
	{}

	Actor::Actor(const std::string _type, const std::string _name, const int _attitude, const std::vector<Dialog> _dialogs)
	: type(_type)
	, name(_name)
	, attitude(_attitude)
	, dialogs(_dialogs)
	, status()
	{}

	const std::string Actor::getType() const {
		return type;
	}

	const std::string Actor::getName() const {
		return name;
	}

	const int Actor::getAttitude() const {
		return attitude;
	}

	std::string Actor::getStatus() {
		std::string oldStatus = status;
		status = "";
		return oldStatus;
	}

	void Actor::setType(std::string _type) {
		type = _type;
	}

	void Actor::setName(std::string _name) {
		name = _name;
	}

	void Actor::setAttitude(int _attitude) {
		attitude = _attitude;
	}

	void Actor::action() {
		std::cout << "Actor.action()" << std::endl;
		//TODO
	}

	void Actor::go(Direction_t direction) {
		std::cout << "Actor.go()" << std::endl;
		//TODO
	}

	void Actor::talk_to(Actor other) const{
		std::cout << "Actor.talk_to()" << std::endl;
		//TODO
	}




}
