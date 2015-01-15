#ifndef ARCUS_MONSTER_H
#define ARCUS_MONSTER_H

#include <string>

namespace arcus {
	class Corporeal;
	class Monster: public Corporeal {
	public:
		const Corporeal getMaster() const;
		const std::string getEats() const;
		const int getHunger() const;

		void setHunger(int);
		void setWisdom(int);

		void subjectTo(Corporeal);

	private:
		Corporeal master;
		std::string eats;
		int hunger;
	};
}

#endif