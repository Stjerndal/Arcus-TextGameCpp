#ifndef ARCUS_ONOFFITEM_H
#define ARCUS_ONOFFITEM_H

namespace arcus {
	/**
	Interface class
	**/
	class OnOffItem {
	public:
		const bool getState() const;

		virtual void setState(const bool);

		virtual void toggle() = 0;

	private:
		bool state;
	};

}

#endif