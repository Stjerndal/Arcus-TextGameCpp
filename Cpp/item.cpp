#include <string>
#include <climits>

#include "item.h"

namespace arcus {
	/*std::string name; //TODO:
	int weight; //Make unchangable to const?
	int volume;
	int price;
	std::string color;
	std::string description;
	int hp;*/

		Item::Item(const std::string _name, const int _weight, const int _volume,
			const int _price, const std::string _color, const std::string _desc)
		: name(_name)
		, weight(_weight)
		, volume(_volume)
		, price(_price)
		, color(_color)
		, description(_desc)
		, hp(INT_MAX)
		{}

		Item::Item(const std::string _name, const int _weight, const int _volume,
			const int _price, const std::string _color, const std::string _desc, int _hp)
		: name(_name)
		, weight(_weight)
		, volume(_volume)
		, price(_price)
		, color(_color)
		, description(_desc)
		, hp(_hp)
		{}

		bool Item::operator==(Item const& item) const {
			return name == item.getName() && hp == item.hp && weight == item.weight;
		}

		bool Item::operator!=(Item const& item) const {
			return !((*this) == item);
		}

		const std::string Item::getName() const {
			return name;
		}

		const int Item::getWeight() const {
			return weight;
		}

		const int Item::getVolume() const {
			return volume;
		}

		const int Item::getPrice() const {
			return price;
		}
		
		const std::string Item::getColor() const {
			return color;
		}
		
		const std::string Item::getDescription() const {
			return description;
		}
		
		const int Item::getHp() const {
			return hp;
		}
		

		void Item::setName(std::string _name) {
			name = _name;
		}
		
		void Item::setHp(int _hp) {
			hp = _hp;
		}
		

		

}