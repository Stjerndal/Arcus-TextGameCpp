#ifndef ARCUS_ACTOR_H
#define ARCUS_ACTOR_H

#include <string>
#include <vector>
#include <memory>

#include "directions.hpp"
#include "dialog.h"

namespace arcus {
	//class Dialog;
	class Actor {
	public:
		Actor();
		Actor(const std::string type, const std::string name, const int attitude);
		Actor(const std::string type, const std::string name, const int attitude, const std::vector<Dialog>);

		std::string getType() const;
		std::string getName() const;
		int getAttitude() const;
		int hasGoalAccess() const;
		bool isAlive() const;
		std::vector<Dialog> getDialogs() const;


		void setAlive(bool);
		void setType(std::string);
		void setName(std::string);
		void setAttitude(int);

		void giveGoalAccess();

		virtual std::string action(Actor&);
		void go(Direction_t);
		virtual void talk_to(Actor&);
		int getAnswerFromDialog(int dialogIndex);

	private:
		std::string type;
		std::string name;
		int attitude;
		std::vector<Dialog> dialogs;
		bool goalAccess;
		bool alive;
	};


}

#endif