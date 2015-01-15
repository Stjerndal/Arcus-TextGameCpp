#ifndef ARCUS_ACTOR_H
#define ARCUS_ACTOR_H

#include <string>

#include "environment.h"

namespace arcus {
	class Actor {
	public:
		const std::string getType() const;
		const std::string getName() const;
		const std::string getAttitude() const;

		void setType(std::string);
		void setName(std::string);
		void setAttitude(int);

		virtual void action();
		bool go(Direction_t);
		virtual void talk_to(Actor) const;

	private:
		std::string type;
		std::string name;
		int attitude;
	};


}

#endif