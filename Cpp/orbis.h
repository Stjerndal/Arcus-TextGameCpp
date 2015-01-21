#ifndef ARCUS_ORBIS_H
#define ARCUS_ORBIS_H

#include <string>
#include <vector>
#include <memory>

#include "humanoid.h"
#include "corporeal.h"

namespace arcus {
	//class Spirit;
	class Dialog;
	class Orbis: public Humanoid {
	public:
		Orbis(const std::string _type, const std::string _name, const int _attitude,
			const std::string _skinColor, const int _strength, const int _agility,
			const int _intellect, const int _hp);
		Orbis(const std::string _type, const std::string _name, const int _attitude,
			const std::vector<Dialog> _dialogs, const std::string _skinColor, const int _strength,
			const int _agility, const int _intellect, const int _hp);


		virtual void talk_to(Actor&);
		virtual std::string attackString(Corporeal&, int) const;
		virtual int getDmg() const;

		/*
		const int getReligion() const;

		void setReligion(int);

		const bool pray(Spirit) const;

	private:
		int religion;*/
	};
}

#endif