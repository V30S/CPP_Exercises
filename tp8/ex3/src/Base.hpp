#pragma once

#include <ostream>
#include <string>

class Base
{
    friend std::ostream& operator<<(std::ostream& stream, const Base& base)
    {
        return stream << base.to_string();
    }

public:
    virtual bool              is_null() const   = 0;
    virtual std::string       to_string() const = 0;
    virtual std::string base_type() const = 0;

    std::string type() const { return base_type(); }
};
