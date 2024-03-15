#pragma once

#include "Base.hpp"

#include <string>

class DerivedString : public Base
{
public:
    DerivedString(const std::string& str)
        : _str { str }
    {}

    const std::string& data() const { return _str; }

    bool is_null() const { return _str == "" ? true : false; }

private:
    std::string _str;
};
