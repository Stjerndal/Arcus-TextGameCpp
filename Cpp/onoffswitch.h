#ifndef ARCUS_ONOFFSWITCH_H
#define ARCUS_ONOFFSWITCH_H

#include "onoffitem.h"

namespace arcus {
	class OnOffSwitch: public Technology {
	public:
		OnOffItem getTarget() const;
		bool getState() const;

		void setTarget(const OnOffItem );
		void setState(bool);
		

		void toggle();

	private:
		OnOffItem target;
		bool state;
	};

}

#endif