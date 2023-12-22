#pragma once

#include "vehicle.h"

class Car : public Vehicle {
private:
	std::string make;
	std::string model;

public:
	Car();

	void print() const;
};