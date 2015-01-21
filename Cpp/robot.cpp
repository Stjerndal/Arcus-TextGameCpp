#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <sstream>

#include "robot.h"
#include "dialog.h"
#include "userinterface.h"

namespace arcus {

	 Robot::Robot(const std::string _type, const std::string _name, const int _attitude,
			const std::string _skinColor, const int _strength, const int _agility,
			const int _intellect, const int _hp)
	 : Humanoid(_type, _name, _attitude, _skinColor,_strength,_agility,
			     _intellect, _hp)
	 {}

	 Robot::Robot(const std::string _type, const std::string _name, const int _attitude,
			const std::vector<Dialog> _dialogs, const std::string _skinColor, const int _strength,
			const int _agility, const int _intellect, const int _hp)
	 : Humanoid(_type, _name, _attitude, _dialogs, _skinColor,_strength,_agility,
			     _intellect, _hp)
	 {}

 	void Robot::talk_to(Actor& other) {
		int answer = getAnswerFromDialog(0);
		if(answer == 0) { //If the first answer
			setAttitude(100); //Get angry
			return;
		} else { //Else be happy.
			setAttitude(1);
			other.giveGoalAccess();
			getAnswerFromDialog(1); //Present another dialog;
		}
	}

	std::string Robot::attackString(Corporeal& other, int dmg) const {
		std::ostringstream oss;
		oss << "The " << getType() << " shreds " << other.getType() << " for " << dmg << " damage!"
			<< "\n" << other.getType() << " has " << other.getHp() << "hp left!";
		return oss.str();
	}

	int Robot::getDmg() const {
		return (getStrength()*2) + (getAgility()/2) + (getIntellect()*2)/ 2;
	}


}