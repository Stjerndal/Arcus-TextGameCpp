#ifndef ARCUS_ITEM_H
#define ARCUS_ITEM_H

#include <string>

namespace arcus {
	class Item {
	public:
		const std::string getName() const;
		const int getWeight() const;
		const int getVolume() const;
		const int getPrice() const;
		const std::string getColor() const;
		const std::string getDescription() const;
		const int getHp() const;

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