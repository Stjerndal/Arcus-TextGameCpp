#include <string>
#include <iostream>

#include "actor.h"
#include "dialog.h"
#include "userinterface.h"

namespace arcus {

	/*std::string type;
	std::string name;
	int attitude;
	std::vector<Dialog> dialogs;*/

	Actor::Actor()
	: type()
	, name()
	, attitude()
	, goalAccess(false)
	, alive(true)
	{}

	Actor::Actor(const std::string _type, const std::string _name, const int _attitude)
	: type(_type)
	, name(_name)
	, attitude(_attitude)
	, goalAccess(false)
	, alive(true)
	{}

	Actor::Actor(const std::string _type, const std::string _name, const int _attitude, const std::vector<Dialog> _dialogs)
	: type(_type)
	, name(_name)
	, attitude(_attitude)
	, dialogs(_dialogs)
	, goalAccess(false)
	, alive(true)
	{}

	std::string Actor::getType() const {
		return type;
	}

	std::string Actor::getName() const {
		return name;
	}

	int Actor::getAttitude() const {
		return attitude;
	}

	int Actor::hasGoalAccess() const {
		return goalAccess;
	}

	bool Actor::isAlive() const {
		return alive;
	}

	std::vector<Dialog> Actor::getDialogs() const{
		return dialogs;
	}

	void Actor::setAlive(bool _alive) {
		alive = _alive;
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

	void Actor::giveGoalAccess() {
		goalAccess = true;
	}

	std::string Actor::action(Actor& other) {
		//std::cout << "Actor.action()" << std::endl;
	}

	void Actor::go(Direction_t direction) {
		//std::cout << "Actor.go()" << std::endl;
	}

	void Actor::talk_to(Actor& other) {
		//std::cout << "Actor.talk_to()" << std::endl;
	}

	int Actor::getAnswerFromDialog(int dialogIndex) {
		UserInterface::present(name + " the " + type + " says: \n");
		UserInterface::present(dialogs[dialogIndex].present());
		int answer = -1;
		while(answer < 0 || answer > dialogs[dialogIndex].answers.size()-1) {
			answer = UserInterface::fetchNumber()-1;
		}
		dialogs[dialogIndex].chooseAnswer(answer);
		return answer;
		return 1;
	}




}
