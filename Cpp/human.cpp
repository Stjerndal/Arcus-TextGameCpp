#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <sstream>

#include "human.h"
#include "humanoid.h"
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

 	void Human::talk_to(Actor& other) {
 		int dialogIndex = (other.hasGoalAccess() ? 1 :  0);
		getAnswerFromDialog(dialogIndex);
	}

	std::string Human::attackString(Corporeal& other, int dmg) {
		std::ostringstream oss;
		oss << getType() << " blast " << other.getType() << " for " << dmg << " damage!"
			<< "\n" << other.getType() << " has " << other.getHp() << "hp left!";
		return oss.str();
	}

	void Human::die(Corporeal& other) {
		Humanoid::die(other);
		other.giveGoalAccess();
	}


}