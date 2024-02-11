#pragma once

#include "PhoneBookEntry.hpp"

#include <list>

class PhoneBook
{
public:
    bool         add_entry(const PhoneBookEntry& phoneBookEntry);
    const PhoneNumber* get_number(const std::string& name) const;

private:
    std::list<PhoneBookEntry> _phoneBook;
};