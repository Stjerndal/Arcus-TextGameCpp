#ifndef ARCUS_WEAPON_H
#define ARCUS_WEAPON_H

namespace arcus {
	class Item;
	class Weapon: public Item {
	public:
		const int getDamage() const;
		const int getRange() const;
		const int getHandsRequired() const;

		//const fields

	private:
		int damage; //TODO:
		int range; //Make unchangable to const?
		int handsRequired;
	};

}

#endif