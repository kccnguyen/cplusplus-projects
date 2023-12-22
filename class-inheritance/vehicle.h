#pragma once

#include <string>

class Vehicle {
private:
	std::string design;

protected:
	std::string project_code;

public:
	Vehicle();

	void print() const;
};