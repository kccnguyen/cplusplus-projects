#include "Base.h"

Base::Base()
	:number{414} {}

Base::Base(int number)
	:number{number} {}

void Base::print() const {
	std::cout << "number: " << number << std::endl;
}


