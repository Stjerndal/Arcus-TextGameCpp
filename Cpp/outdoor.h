#ifndef ARCUS_OUTDOOR_H
#define ARCUS_OUTDOOR_H

#include <vector>

namespace arcus {

	enum Weather_t {SUNNY, RAINY, SNOWY};

	class Outdoor: public Environment {
	public:
		const Weather_t getWeather() const;
		const std::string getSkyColor() const;

		void setWeather(const Weather_t);
		void setSkyColor(const std::string);

	private:
		Weather_t weather;
		std::string skyColor;
	};

}

#endif