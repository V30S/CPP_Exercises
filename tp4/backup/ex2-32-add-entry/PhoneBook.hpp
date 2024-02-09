#pragma once

#include "PhoneBookEntry.hpp"

#include <list>

class PhoneBook {
public:
    void add_entry(const PhoneBookEntry& phoneBookEntry);
    PhoneBookEntry* get_number(const std::string& name) const;
private:
    std::list<PhoneBookEntry> _phoneBook;
};