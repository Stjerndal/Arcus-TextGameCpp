#ifndef ARCUS_UI
#define ARCUS_UI

#include <iostream>
#include <string>

class UserInterface {
public:
	static void present(const std::string msg);
	static std::string fetchInput();
};

#endif