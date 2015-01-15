#ifndef ARCUS_ROBOT_H
#define ARCUS_ROBOT_H

#include <string>

namespace arcus {
	class Technology;
	class Humanoid;
	class Robot: public Humanoid {
	public:
		const int getHacking() const;

		void setHacking(int);

		const bool hack(Technology) const;

	private:
		int hacking;
	};
}

#endif