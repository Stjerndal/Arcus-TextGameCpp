#ifndef ARCUS_ITEM_H
#define ARCUS_ITEM_H

#include <string>

namespace arcus {
	class Item {
	public:
		Item(const std::string _name, const int _weight, const int _volume,
			const int _price, const std::string _color, const std::string _desc);
		Item(const std::string _name, const int _weight, const int _volume,
			const int _price, const std::string _color, const std::string _desc, int hp);

		bool operator==(Item const& item) const;
		bool operator!=(Item const& item) const;


		std::string getName() const;
		int getWeight() const;
		int getVolume() const;
		int getPrice() const;
		std::string getColor() const;
		std::string getDescription() const;
		int getHp() const;

		void setName(std::string);
		void setHp(int);

	private:
		std::string name; //TODO:
		int weight; //Make unchangable to const?
		int volume;
		int price;
		std::string color;
		std::string description;
		int hp;
	};

}

#endif