#ifndef ARCUS_MONSTER_H
#define ARCUS_MONSTER_H

#include <string>
#include <memory>

namespace arcus {
	class Corporeal;
	class Monster: public Corporeal {
	public:
		std::weak_ptr<Corporeal> getMaster() const;
		std::string getEats() const;
		int getHunger() const;

		void setHunger(int);
		void setWisdom(int);

		void subjectTo(std::weak_ptr<Corporeal>);

	private:
		std::weak_ptr<Corporeal> master;
		std::string eats;
		int hunger;
	};
}

#endif