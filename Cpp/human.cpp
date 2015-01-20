#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "human.h"
#include "dialog.h"

namespace arcus {

	 Human::Human(const std::string _type, const std::string _name, const int _attitude,
			const std::string _skinColor, const int _strength, const int _agility,
			const int _intellect, const int _hp)
	 : Humanoid(_type, _name, _attitude, _skinColor,_strength,_agility,
			     _intellect, _hp)
	 {}

	 Human::Human(const std::string _type, const std::string _name, const int _attitude,
			const std::vector<Dialog> _dialogs, const std::string _skinColor, const int _strength,
			const int _agility, const int _intellect, const int _hp)
	 : Humanoid(_type, _name, _attitude, _dialogs, _skinColor,_strength,_agility,
			     _intellect, _hp)
	 {}

 	void Human::talk_to(std::weak_ptr<Actor> other) {
		std::cout << "Human.talk_to()" << std::endl;
		//TODO
	}


	/*const int Humanoid::getCharisma() const {
		return charisma;
	}

	const int Humanoid::getWisdom() const {
		return wisdom;
	}

	void Humanoid::interact(Item item) const {

	}

	const bool Humanoid::charm(Actor actor) const {

	}

	void Humanoid::insult(Actor actor) const {

	}*/

}