#pragma once
#include "PhoneNumber.hpp"

#include <string>

class PhoneBookEntry
{
public:
    PhoneBookEntry(const std::string& name, const PhoneNumber& phoneNumber);

    const std::string& get_name() const;

    const PhoneNumber& get_number() const;

    bool operator==(const PhoneBookEntry& phoneBookEntry) const;

private:
    std::string _name;
    PhoneNumber _phoneNumber;
};