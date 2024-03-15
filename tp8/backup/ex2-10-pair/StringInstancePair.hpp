#pragma once
#include "../lib/InstanceCounter.hpp"

#include <memory>
#include <string>

class StringInstancePair
{
public:
    StringInstancePair(const std::string& string_value)
        : _string_value { string_value }
    {}
    ~StringInstancePair() {}

    const std::string& get_str() const { return _string_value; }

    const InstanceCounter& get_instance_counter() { return *_ptr_i.get(); }

private:
    std::string                      _string_value;
    std::unique_ptr<InstanceCounter> _ptr_i { new InstanceCounter() };
};
