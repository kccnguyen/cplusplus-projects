#include "Car.h"
#include <iostream>

Car::Car()
	:Vehicle(), make {"chevy"}, model {"impala"} {}

void Car::print() const {

	std::cin;

	std::cout << "make: " << make << std::endl;
	std::cout << "model: " << model << std::endl;
	std::cout << "project_code: " << project_code << std:: endl;

	Vehicle::print();
}