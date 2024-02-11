#include "PhoneBook.hpp"

#include <iostream>

void PhoneBook::add_entry(const PhoneBookEntry& phoneBookEntry)
{
    _phoneBook.emplace_back(phoneBookEntry);
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
