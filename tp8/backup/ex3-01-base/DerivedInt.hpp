#pragma once

class DerivedInt
{
public:
    DerivedInt(int integer)
        : _integer { integer }
    {}

    const int data() const { return _integer; }

private:
    int _integer;
};