#include "PhoneNumber.hpp"

PhoneNumber::PhoneNumber(int a, int b, int c, int d, int e)
    : _array_of_numbers({ a, b, c, d, e })
{}

bool PhoneNumber::is_valid() const
{
    for (auto i = 0; i < _array_of_numbers.size(); i++)
    {
        if (_array_of_numbers[i] < 0 || _array_of_numbers[i] > 99)
        {
            return false;
        }
    }
    return true;
}

int PhoneNumber::operator[](int index) const
{
    if (index < 0 || index > _array_of_numbers.size() - 1)
    {
        return -1;
    }
    return _array_of_numbers[index];
}

std::ostream& operator<<(std::ostream& stream, PhoneNumber phoneNumber)
{
    for (auto i = 0; i < phoneNumber._array_of_numbers.size(); i++)
    {
        phoneNumber._array_of_numbers[i] < 10 ? stream << "0" << phoneNumber._array_of_numbers[i]
                                              : stream << phoneNumber._array_of_numbers[i];
    }
    return stream;
}