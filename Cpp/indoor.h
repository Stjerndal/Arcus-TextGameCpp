#ifndef ARCUS_INDOOR_H
#define ARCUS_INDOOR_H

#include <vector>

namespace arcus {
	class Item;
	class Indoor: public Environment {
	public:
		const std::vector<Item> getWalls() const;
		const int getCeiling_height() const;

		void setWalls(const std::vector<Item>);
		void setCeiling_height(const int);

	private:
		std::vector<Item> walls;
		int ceiling_height;
	};

}

#endif