// TUIStatsBar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip> 
#include "UI.h"




int main()
{
	renderStat("HP", 100, 200);
	renderStat("Charge", 12.5);
	renderStat("Apple Power", 10, 20, 10, '*', '_', false, true);
}
