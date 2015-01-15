#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#include "actor.h"
#include "environment.h"
#include "corporeal.h"
#include "humanoid.h"
#include "human.h"
#include "orbis.h"
#include "robot.h"
#include "monster.h"
#include "spirit.h"
#include "firespirit.h"
#include "earthspirit.h"
#include "item.h"
#include "weapon.h"
#include "technology.h"
#include "onoffswitch.h"
#include "container.h"
#include "door.h"
#include "onoffitem.h"
#include "indoor.h"
#include "outdoor.h"
#include "dialog.h"

int main() {
	std::cout << "flerp" << std::endl;
	arcus::Actor actor("Human", "Peter", 42);
	std::cout << actor.getName() << std::endl;

	arcus::Corporeal corpse("Orbis", "Klas", 50, "Red", 10, 10, 10, 100);
	std::cout << corpse.getHp() << std::endl;

	arcus::Item key("Key", 32, 2, 500, "Gold", "A golden Key");
	std::cout << key.getDescription() << std::endl;

	arcus::Item ball("Ball", 32, 2, 500, "Blue", "A soft blue ball");
	std::cout << ball.getDescription() << std::endl;

	arcus::Container bag("Backpack", 1, 1, 1327, "Brown", "A simple bag", 50, 10);
	bag.add(key);
	bag.add(key);
	std::cout << bag.getHold_weight() << "kg, " << bag.getCur_weight() << "kg, " << std::endl;
	std::cout << "is ball removable?" << bag.remove(ball) << std::endl;
	std::cout << bag.getHold_weight() << "kg, " << bag.getCur_weight() << "kg, " << std::endl;
	bag.remove(key);
	std::cout << bag.getHold_weight() << "kg, " << bag.getCur_weight() << "kg, " << std::endl;
	bag.remove(key);
	std::cout << bag.getHold_weight() << "kg, " << bag.getCur_weight() << "kg, " << std::endl;

	std::vector<arcus::Direction_t> directions = {arcus::UP, arcus::RIGHT, arcus::LEFT, arcus::DOWN};
	arcus::Environment desert("A desert");

	arcus::Environment forest("A forest");
	forest.addNeighbor(desert, arcus::UP);
	forest.openDirection(arcus::UP);
	std::cout << forest.getDescription() << ", UP: " << forest.getNeighbor(arcus::UP).getDescription() << std::endl;

	return 0;
}