#include <vector>

#include "outdoor.h"
#include "environment.h"

namespace arcus {

	/*Weather_t weather;
	std::string skyColor;*/

	Outdoor::Outdoor(const std::string _description, const Weather_t _weather, const std::string _skyColor)
	: Environment(_description)
	, weather(_weather)
	, skyColor(_skyColor)
	{}

	Weather_t Outdoor::getWeather() const {
		return weather;
	}

	std::string Outdoor::getSkyColor() const {
		return skyColor;
	}

	void Outdoor::setWeather(const Weather_t _weather) {
		weather = _weather;
	}
	
	void Outdoor::setSkyColor(const std::string _skyColor) {
		skyColor = _skyColor;
	}
	
}