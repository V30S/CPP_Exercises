#pragma once

#include "PhoneBookEntry.hpp"

#include <vector>

class PhoneBook {
public:
    void add_entry(const PhoneBookEntry& phoneBookEntry);
private:
    std::vector<PhoneBookEntry> _phoneBook;
};