#include "UI.h"

#include <iostream>
#include <iomanip> 


template <typename T>
bool inRangeInclusive(T value, T min, T max) {
	if (min <= value && value <= max) {
		return true;
	}
	return false;
}

template <typename T>
T clamp(T value, T low, T high) {
	if (value < low) {
		return low;
	}
	else if (value > high) {
		return high;
	}
	else {
		return value;
	}
}

void renderStat(const std::string& label, int current, int max) {
	std::string statName = label + " ";

	std::cout << statName;

	double percent = static_cast<double>(current) / max;
	int barCount = static_cast<int>(std::round(20 * percent));

	std::cout << "[";

	for (size_t i = 0; i < 20; i++)
	{
		if (i <= barCount) {
			std::cout << "#";
		}
		else {
			std::cout << "_";
		}
	}

	std::cout << "]  ";

	std::cout << current << "/" << max << " ";

	std::cout << "(" << std::setprecision(3) << percent * 100 << "%" << ")" << std::endl;


}

void renderStat(const std::string& label, double percent) {
	std::string statName = label + " ";
	percent = clamp(percent, 0.0, 100.0);
	std::cout << statName;

	int barCount = static_cast<int>(std::round(20 * (percent / 100)));

	std::cout << "[";

	for (size_t i = 0; i < 20; i++)
	{
		if (i <= barCount) {
			std::cout << "#";
		}
		else {
			std::cout << "_";
		}
	}

	std::cout << "]  ";

	std::cout << "(" << std::setprecision(3) << percent << "%" << ")" << std::endl;
}

void renderStat(const std::string& label, int current, int max,
	int width, char fill, char empty, bool showRatio,
	bool showPercentage) {

	std::string statName = label + " ";

	std::cout << statName;

	double percent = static_cast<double>(current) / max;
	int barCount = static_cast<int>(std::round(width * percent));

	std::cout << "[";

	for (size_t i = 0; i < width; i++)
	{
		if (i <= barCount) {
			std::cout << fill;
		}
		else {
			std::cout << empty;
		}
	}

	std::cout << "] ";

	if (showRatio) {
		std::cout << current << "/" << max << " ";
	}

	if (showPercentage) {
		std::cout << "(" << std::setprecision(3) << percent * 100 << "%" << ")" << std::endl;
	}
	else
	{
		std::cout << std::endl;
	}
}
