#ifndef ARCUS_UI
#define ARCUS_UI

#include <iostream>
#include <string>
#include <vector>

class UserInterface {
public:
	static void present(const std::string msg);
	static std::vector<std::string> fetchInput();
private:
	static std::vector<std::string>& split(const std::string&, char, std::vector<std::string>&);
	static std::vector<std::string> split(const std::string&, char);
};

#endif