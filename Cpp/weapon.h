#ifndef ARCUS_WEAPON_H
#define ARCUS_WEAPON_H

namespace arcus {
	class Item;
	class Weapon: public Item {
	public:
		int getDamage() const;
		int getRange() const;
		int getHandsRequired() const;

	private:
		int damage; 
		int range;
		int handsRequired;
	};

}

#endif