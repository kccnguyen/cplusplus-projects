#include "Derived.h"

Derived::Derived()
	: Base(), name{"Hank"} {}

Derived::Derived(int number, std::string name)
	: Base(number), name{ name } {}

void Derived::print() const {
	Base::print();
	std::cout << "name: " << name << std::endl;
}