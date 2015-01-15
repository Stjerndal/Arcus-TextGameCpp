#ifndef ARCUS_ONOFFSWITCH_H
#define ARCUS_ONOFFSWITCH_H

#include "onoffitem.h"

namespace arcus {
	class OnOffSwitch: public Technology {
	public:
		const OnOffItem* getTarget() const;
		const bool getState() const;

		void setTarget(const OnOffItem *);
		void setState(const bool);
		

		void toggle();

	private:
		OnOffItem* target;
		bool state;
	};

}

#endif