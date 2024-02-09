#include "PhoneBook.hpp"

void PhoneBook::add_entry(const PhoneBookEntry& phoneBookEntry) {
    _phoneBook.emplace_back(phoneBookEntry);
}

PhoneBookEntry* PhoneBook::get_number(const std::string& name) const {
    for (auto phoneBookEntry : _phoneBook) {
        if (phoneBookEntry.get_name() == name) {
            return &phoneBookEntry;
        }
    }
    return nullptr;
}
