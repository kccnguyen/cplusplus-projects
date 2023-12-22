//polymorphism

#include <iostream>
#include "Base.h"
#include "Derived.h"

int main()
{
	Base b;

	Derived d(433, "Ethan");

	Base* pb = nullptr;

	pb = &b;
	pb->print();
	std::cout << "\n";

	pb = &d;
	pb->print();

	pb = new Base(100);
	pb->print();

	pb = new Derived(200, "name");
	pb->print();

	b = d;
	b.print();

}

