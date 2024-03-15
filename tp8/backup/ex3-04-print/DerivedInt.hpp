#pragma once

#include "Base.hpp"

class DerivedInt : public Base
{
public:
    DerivedInt(int integer)
        : _integer { integer }
    {}

    const int data() const { return _integer; }

    bool is_null() const { return _integer == 0 ? true : false; }

    std::string to_string() const override { return std::to_string(_integer); }

private:
    int _integer;
};