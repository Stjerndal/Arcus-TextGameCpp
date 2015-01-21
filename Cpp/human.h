#ifndef ARCUS_HUMAN_H
#define ARCUS_HUMAN_H

#include <string>
#include <vector>
#include <memory>

#include "humanoid.h"
#include "corporeal.h"

namespace arcus {

	class Dialog;
	class Human: public Humanoid {
	public:
		Human(const std::string _type, const std::string _name, const int _attitude,
			const std::string _skinColor, const int _strength, const int _agility,
			const int _intellect, const int _hp);
		Human(const std::string _type, const std::string _name, const int _attitude,
			const std::vector<Dialog> _dialogs, const std::string _skinColor, const int _strength,
			const int _agility, const int _intellect, const int _hp);


		virtual void talk_to(Actor&);

		virtual std::string attackString(Corporeal&, int);
		virtual void die(Corporeal&);
		/*
		const std::string getHairColor() const;
		const int getHumor() const;

		void setHairColor(std::string);
		void setHumor(int);

		const bool joke(Actor) const;

	private:
		std::string hairColor;
		int humor;*/
	};


}

#endif