#ifndef ARCUS_FIRESPIRIT_H
#define ARCUS_FIRESPIRIT_H

#include <string>

namespace arcus {
	class Corporeal;
	class Spirit;
	class FireSpirit: public Spirit {
	public:
		int getHate() const;

		void setHate(int);

		bool burn(Corporeal) const;

	private:
		int hate;
	};
}

#endif