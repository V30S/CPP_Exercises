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

    std::string to_string() const override { return _str; }

    std::string base_type() const { return "String"; }

private:
    std::string _str;
};
