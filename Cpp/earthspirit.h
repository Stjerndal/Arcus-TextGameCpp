#ifndef ARCUS_EARTHSPIRIT_H
#define ARCUS_EARTHSPIRIT_H

#include <string>

namespace arcus {
	class Corporeal;
	class Spirit;
	class EarthSpirit: public Spirit {
	public:
		const int getCompassion() const;

		void setCompassion(int);

		const bool heal(Corporeal) const;

	private:
		int compassion;
	};
}

#endif