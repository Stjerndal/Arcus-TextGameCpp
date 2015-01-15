#ifndef ARCUS_CONTAINER_H
#define ARCUS_CONTAINER_H

#include <vector>

namespace arcus {
	class Item;
	class Container: public Item {
	public:
		const std::vector<Item> getItems() const;
		const int getHold_weight() const;
		const int getHold_volume() const;

		void setItems(const std::vector<Item>);
		void setHold_weight(const int);
		void setHold_volume(const int);
		
		const bool add(const Item);
		const bool remove(const Item);
		const bool contains(const Item);

	private:
		std::vector<Item> items;
		int hold_weight;
		int hold_volume;
	};

}

#endif