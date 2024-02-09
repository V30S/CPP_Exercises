#include "PhoneBookEntry.hpp"

PhoneBookEntry::PhoneBookEntry(const std::string& name, const PhoneNumber& phoneNumber)
    : _name { name }
    , _phoneNumber { phoneNumber }
{}

const std::string& PhoneBookEntry::get_name() const
{
    return _name;
}

const PhoneNumber& PhoneBookEntry::get_number() const
{
    return _phoneNumber;
}

bool PhoneBookEntry::operator==(const PhoneBookEntry& phoneBookEntry) const
{
    return _name == phoneBookEntry._name;
}