#include <string>
#include <vector>
#include <algorithm>

#include "container.h"
#include "item.h"

namespace arcus {

	/*std::vector<Item> items;
	int hold_weight;
	int hold_volume;*/

	Container::Container(const std::string _name, const int _weight, const int _volume,
		const int _price, const std::string _color, const std::string _desc,
		const int _hold_weight, const int _hold_volume)
	: Item(_name, _weight, _volume, _price, _color, _desc)
	, hold_weight(_hold_weight)
	, hold_volume(_hold_volume)
	, items()
	, cur_weight(0)
	, cur_volume(0)
	{}

	/*Container::Container(const std::string _name, const int _weight, const int _volume,
		const int _price, const std::string _color, const std::string _desc,
		const int _hold_weight, const int _hold_volume, std::vector<Item> _items)
	: Item(_name, _weight, _volume, _price, _color, _desc)
	, hold_weight(_hold_weight)
	, hold_volume(_hold_volume)
	, items(_items)
	{}*/

	const std::vector<Item> Container::getItems() const {
		return items;
	}

	const int Container::getHold_weight() const {
		return hold_weight;
	}
	
	const int Container::getHold_volume() const {
		return hold_volume;
	}

	const int Container::getCur_weight() const {
		return cur_weight;
	}
	
	const int Container::getCur_volume() const {
		return cur_volume;
	}
	

	void Container::setItems(const std::vector<Item> _items) {
		items = _items;
	}
	
	void Container::setHold_weight(const int _hold_weight) {
		hold_weight = _hold_weight;
	}
	
	void Container::setHold_volume(const int _hold_volume) {
		hold_volume = _hold_volume;
	}
	
	
	const bool Container::add(const Item item) {
		if( (cur_weight+item.getWeight()) > hold_weight || 
			(cur_volume+item.getVolume()) > hold_volume)
			return false;
		cur_weight += item.getWeight();
		cur_volume += item.getVolume();
		items.push_back(item);
		return true;
	}
	
	const bool Container::remove(const Item item) {
		if(!contains(item))
			return false;
		cur_weight -= item.getWeight();
		cur_volume -= item.getVolume();
		items.erase(iteratorOf(item));
	}
	
	const bool Container::contains(const Item item) {
		return iteratorOf(item) != items.end();
		//std::find(items.begin(), items.end(), item);
		//return false;
	}

	const std::vector<Item>::iterator Container::iteratorOf(const Item item) {
		return std::find(items.begin(), items.end(), item);
	}
	

}