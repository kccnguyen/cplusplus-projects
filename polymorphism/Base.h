#pragma once
#include <iostream>

class Base
{
	int number;
public:
	Base();
	Base(int number);

	virtual void print() const;

};

