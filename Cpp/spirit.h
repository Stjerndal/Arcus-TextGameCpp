#ifndef ARCUS_SPIRIT_H
#define ARCUS_SPIRIT_H

#include <string>

namespace arcus {
	class Actor;
	class Corporeal;

	enum Realm_t {THIS, OTHER};

	class Spirit: public Actor {
	public:
		int getPower() const;
		Realm_t getRealm() const;
		Corporeal getBody() const;

		void setPower(int);
		void setRealm(Realm_t);

		void possess(Corporeal&);
		void dispossess();

	private:
		int strength;
		int agility;
		Corporeal body;
	};
}

#endif