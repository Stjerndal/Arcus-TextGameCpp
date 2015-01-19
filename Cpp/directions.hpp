#ifndef ARCUS_DIRECTIONS_H
#define ARCUS_DIRECTIONS_H

#include <string>

namespace arcus {
	enum Direction_t {NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST, INVALID};

	static Direction_t convertDir(std::string string) {
		if(string == "north")
			return NORTH;
		else if(string == "north-east")
			return NORTH_EAST;
		else if(string == "east")
			return EAST;
		else if(string == "south-east")
			return SOUTH_EAST;
		else if(string == "south")
			return SOUTH;
		else if(string == "south-west")
			return SOUTH_WEST;
		else if(string == "west")
			return WEST;
		else if(string == "north-west")
			return NORTH_WEST;
		else
			return INVALID;
	}

	static std::string convertDir(Direction_t dir) {
		if(dir == NORTH)
			return "north";
		else if(dir == NORTH_EAST)
			return "north-east";
		else if(dir == EAST)
			return "east";
		else if(dir == SOUTH_EAST)
			return "south-east";
		else if(dir == SOUTH)
			return "south";
		else if(dir == SOUTH_WEST)
			return "south-west";
		else if(dir == WEST)
			return "west";
		else if(dir == NORTH_WEST)
			return "north-west";
		else
			return "invalid";
	}

}

#endif