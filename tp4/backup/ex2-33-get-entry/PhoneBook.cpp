#include "PhoneBook.hpp"

#include <iostream>

bool PhoneBook::add_entry(const PhoneBookEntry& phoneBookEntry)
{
    if (phoneBookEntry.get_number().is_valid())
    {
        _phoneBook.emplace_back(phoneBookEntry);
        return true;
    }
    return false;
}

const PhoneNumber* PhoneBook::get_number(const std::string& name) const
{
    for (const auto& phoneBookEntry : _phoneBook)
    {
        if (phoneBookEntry.get_name() == name)
        {
            return &(phoneBookEntry.get_number());
        }
    }
    return nullptr;
}
