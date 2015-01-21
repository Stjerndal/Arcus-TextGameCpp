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

		std::vector<Item> getItems() const;
		int getHold_weight() const;
		int getHold_volume() const;
		int getCur_weight() const;
		int getCur_volume() const;

		void setItems(std::vector<Item>);
		void setHold_weight(int);
		void setHold_volume(int);
		
		bool add(const Item);
		bool remove(const Item);
		bool contains(const Item);
		std::vector<Item>::iterator iteratorOf(const Item);

	private:
		std::vector<Item> items;
		int hold_weight;
		int hold_volume;
		int cur_weight;
		int cur_volume;
	};

}

#endif