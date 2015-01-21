#ifndef ARCUS_ROBOT_H
#define ARCUS_ROBOT_H

#include <string>
#include <vector>
#include <memory>

#include "humanoid.h"
#include "corporeal.h"

namespace arcus {
	//class Technology;
	class Dialog;
	class Robot: public Humanoid {
	public:
		Robot(const std::string _type, const std::string _name, const int _attitude,
			const std::string _skinColor, const int _strength, const int _agility,
			const int _intellect, const int _hp);
		Robot(const std::string _type, const std::string _name, const int _attitude,
			const std::vector<Dialog> _dialogs, const std::string _skinColor, const int _strength,
			const int _agility, const int _intellect, const int _hp);


		virtual void talk_to(Actor&);
		virtual std::string attackString(Corporeal&, int) const;
		virtual int getDmg();

		/*
		const int getHacking() const;

		void setHacking(int);

		const bool hack(Technology) const;

	private:
		int hacking;*/
	};
}

#endif