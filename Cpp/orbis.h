#ifndef ARCUS_ORBIS_H
#define ARCUS_ORBIS_H

#include <string>

namespace arcus {
	class Spirit;
	class Humanoid;
	class Orbis: public Humanoid {
	public:
		const int getReligion() const;

		void setReligion(int);

		const bool pray(Spirit) const;

	private:
		int religion;
	};
}

#endif