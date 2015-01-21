#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <sstream>

#include "orbis.h"
#include "dialog.h"

namespace arcus {

	 Orbis::Orbis(const std::string _type, const std::string _name, const int _attitude,
			const std::string _skinColor, const int _strength, const int _agility,
			const int _intellect, const int _hp)
	 : Humanoid(_type, _name, _attitude, _skinColor,_strength,_agility,
			     _intellect, _hp)
	 {}

	 Orbis::Orbis(const std::string _type, const std::string _name, const int _attitude,
			const std::vector<Dialog> _dialogs, const std::string _skinColor, const int _strength,
			const int _agility, const int _intellect, const int _hp)
	 : Humanoid(_type, _name, _attitude, _dialogs, _skinColor,_strength,_agility,
			     _intellect, _hp)
	 {}

 	void Orbis::talk_to(Actor& other) {
		int answer = getAnswerFromDialog(0);
		if(answer == 2) { //If the third answer
			other.giveGoalAccess(); //give access to goal
			getAnswerFromDialog(1); //say that is was correct
		} else { //Else your wrong
			getAnswerFromDialog(2); //Present another dialog;
			return;
		}
	}

	std::string Orbis::attackString(Corporeal& other, int dmg) const {
		std::ostringstream oss;
		oss << "The " << getType() << " ninjakicks " << other.getType() << " for " << dmg << " damage!"
			<< "\n" << other.getType() << " has " << other.getHp() << "hp left!";
		return oss.str();
	}

	int Orbis::getDmg() const {
		return (getStrength() + (getAgility()*2) + getIntellect())/ 2;
	}

}