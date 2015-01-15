#ifndef ARCUS_CONTAINER_H
#define ARCUS_CONTAINER_H

#include <vector>

#include "item.h"

namespace arcus {
	class Container: public Item {
	public:
		Container(const std::string _name, const int _weight, const int _volume,
			const int _price, const std::string _color, const std::string _desc,
			const int _hold_weight, const int _hold_volume);
		/*Container(const std::string _name, const int _weight, const int _volume,
			const int _price, const std::string _color, const std::string _desc,
			const int _hold_weight, const int _hold_volume, std::vector<Item> _items);*/

		const std::vector<Item> getItems() const;
		const int getHold_weight() const;
		const int getHold_volume() const;
		const int getCur_weight() const;
		const int getCur_volume() const;

		void setItems(const std::vector<Item>);
		void setHold_weight(const int);
		void setHold_volume(const int);
		
		const bool add(const Item);
		const bool remove(const Item);
		const bool contains(const Item);
		const std::vector<Item>::iterator iteratorOf(const Item);

	private:
		std::vector<Item> items;
		int hold_weight;
		int hold_volume;
		int cur_weight;
		int cur_volume;
	};

}

#endif