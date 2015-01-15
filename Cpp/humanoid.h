#ifndef ARCUS_HUMANOID_H
#define ARCUS_HUMANOID_H

#include <string>

namespace arcus {
	class Actor;
	class Item;
	class Corporeal;
	class Humanoid: public Corporeal {
	public:
		const int getCharisma() const;
		const int getWisdom() const;

		void setCharisma(int);
		void setWisdom(int);

		void interact(Item) const;
		const bool charm(Actor) const;
		void insult(Actor) const;

	private:
		int charisma;
		int wisdom;
	};
}

#endif