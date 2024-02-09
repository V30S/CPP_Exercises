#include "PhoneBook.hpp"

void PhoneBook::add_entry(const PhoneBookEntry& phoneBookEntry) {
    _phoneBook.emplace_back(phoneBookEntry);
}