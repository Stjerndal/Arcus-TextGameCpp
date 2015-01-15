#include <string>

namespace arcus {
private:
	std::string type;
	std::string name;
	int attitude;
public:
	const std::string Actor::getType() const {
		return type;
	}

	const std::string Actor::getName() const {
		return name;
	}

	const std::string Actor::getAttitude() const {
		return attitude;
	}

	void Actor::setType(std::string type) {
		this->type = type;
	}

	void Actor::setName(std::string name) {
		this->name = name;
	}

	void Actor::setAttitude(int attitude) {
		this->attitude = attitude;
	}

	void Actor::action() {
		//TODO
	}

	void Actor::go(Direction_t direction) {
		//TODO
	}

	void Actor::talk_to(Actor other) const{
		//TODO
	}




}
