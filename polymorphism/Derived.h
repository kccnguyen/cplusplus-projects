#pragma once
#include <string>
#include "Base.h"

class Derived :
    public Base
{
    std::string name;

public:
    Derived();
    Derived(int number, std::string name);

    void print() const override;
};

