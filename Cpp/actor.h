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

		const std::string getType() const;
		const std::string getName() const;
		const int getAttitude() const;
		std::string getStatus();

		void setType(std::string);
		void setName(std::string);
		void setAttitude(int);

		virtual void action();
		void go(Direction_t);
		virtual void talk_to(std::weak_ptr<Actor>);

	private:
		std::string type;
		std::string name;
		int attitude;
		std::vector<Dialog> dialogs;
		std::string status;
	};


}

#endif