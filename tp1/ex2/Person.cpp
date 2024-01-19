#include <string>
#include "Person.hpp"

Person::Person(std::string _first_name, std::string _surname)
    : first_name{_first_name}, surname{_surname}
{
}

std::string Person::get_first_name()
{
    return first_name;
}

std::string Person::get_surname()
{
    return surname;
}
