#ifndef ARCUS_HUMANOID_H
#define ARCUS_HUMANOID_H

#include <string>
#include <vector>
#include <memory>

#include "corporeal.h"

namespace arcus {
	//class Actor;
	//class Item;
	class Dialog;
	class Humanoid: public Corporeal {
	
	 public:
	 	Humanoid(const std::string _type, const std::string _name, const int _attitude,
			const std::string _skinColor, const int _strength, const int _agility,
			const int _intellect, const int _hp);
		Humanoid(const std::string _type, const std::string _name, const int _attitude,
			const std::vector<Dialog> _dialogs, const std::string _skinColor, const int _strength,
			const int _agility, const int _intellect, const int _hp);

		virtual void talk_to(Actor&);

	/*	const int getCharisma() const;
		const int getWisdom() const;

		void interact(Item) const;
		const bool charm(Actor) const;
		void insult(Actor) const;

	private:
		int charisma;
		int wisdom;
		*/
	};
}

#endif