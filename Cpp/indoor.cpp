#include <vector>

#include "indoor.h"
#include "item.h"
#include "environment.h"

namespace arcus {
	/*std::vector<Item> walls;
	int ceiling_height;*/
	Indoor::Indoor(const std::string _description, const int _ceiling_height) 
	: Environment(_description)
	, ceiling_height(_ceiling_height)
	, walls()
	{}

	const std::vector<Item> Indoor::getWalls() const {
		return walls;
	}

	const int Indoor::getCeiling_height() const {
		return ceiling_height;
	}

	void Indoor::setWalls(const std::vector<Item> _walls) {
		walls = _walls;
	}

	void Indoor::setCeiling_height(const int _ceiling_height) {
		ceiling_height = _ceiling_height;
	}

}