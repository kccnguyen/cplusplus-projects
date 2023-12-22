#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle()
	:design("GM design"), project_code ("JL") {}

void Vehicle::print() const {
	std::cout << "Printing design from Vehicle" << design << std::endl;
}