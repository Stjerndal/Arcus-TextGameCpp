#ifndef ARCUS_HUMAN_H
#define ARCUS_HUMAN_H

#include <string>

namespace arcus {
	class Actor;
	class Humanoid;
	class Human: public Humanoid {
	public:
		const std::string getHairColor() const;
		const int getHumor() const;

		void setHairColor(std::string);
		void setHumor(int);

		const bool joke(Actor) const;

	private:
		std::string hairColor;
		int humor;
	};


}

#endif