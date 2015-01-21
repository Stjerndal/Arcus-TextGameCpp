#ifndef ARCUS_TECHNOLOGY_H
#define ARCUS_TECHNOLOGY_H

namespace arcus {
	class Item;
	class Technology: public Item {
	public:
		int getSecurity() const;

		void hacked();

	private:
		int security;
	};

}

#endif