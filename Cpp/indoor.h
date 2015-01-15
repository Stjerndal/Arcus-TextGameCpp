#ifndef ARCUS_INDOOR_H
#define ARCUS_INDOOR_H

#include <vector>

#include "environment.h"

namespace arcus {
	class Item;
	class Indoor: public Environment {
	public:
		Indoor(const std::string _description, const int ceiling_height);

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