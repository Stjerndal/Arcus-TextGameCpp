#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "humanoid.h"
#include "dialog.h"

namespace arcus {

	 Humanoid::Humanoid(const std::string _type, const std::string _name, const int _attitude,
			const std::string _skinColor, const int _strength, const int _agility,
			const int _intellect, const int _hp)
	 : Corporeal(_type, _name, _attitude, _skinColor,_strength,_agility,
			     _intellect, _hp)
	 {}

	 Humanoid::Humanoid(const std::string _type, const std::string _name, const int _attitude,
			const std::vector<Dialog> _dialogs, const std::string _skinColor, const int _strength,
			const int _agility, const int _intellect, const int _hp)
	 : Corporeal(_type, _name, _attitude, _dialogs, _skinColor,_strength,_agility,
			     _intellect, _hp)
	 {}

 	void Humanoid::talk_to(std::weak_ptr<Actor> other) {
		std::cout << "Corporeal.talk_to()" << std::endl;
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