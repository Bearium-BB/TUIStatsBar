#pragma once

#include <iostream>
#include <iomanip> 

void renderStat(const std::string& label, int current, int max);

void renderStat(const std::string& label, double percent);

void renderStat(const std::string& label, int current, int max,
	int width, char fill, char empty, bool showRatio,
	bool showPercentage);

