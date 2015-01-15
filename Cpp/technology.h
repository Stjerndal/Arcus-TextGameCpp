#ifndef ARCUS_TECHNOLOGY_H
#define ARCUS_TECHNOLOGY_H

namespace arcus {
	class Item;
	class Technology: public Item {
	public:
		const int getSecurity() const;

		//const field

		void hacked();

	private:
		int security; //TODO:
		 //Make unchangable to const?
	};

}

#endif