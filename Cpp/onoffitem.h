#ifndef ARCUS_ONOFFITEM_H
#define ARCUS_ONOFFITEM_H

namespace arcus {
	/**
	Interface class
	**/
	class OnOffItem {
	public:
		bool getState() const;

		virtual void setState(bool);

		virtual void toggle();

	private:
		bool state;
	};

}

#endif