#pragma once
#include <array>
#include <ostream>

class PhoneNumber
{

public:
    PhoneNumber(int a, int b, int c, int d, int e);

    bool is_valid() const;

    int operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& stream, PhoneNumber phoneNumber);

private:
    std::array<int, 5> _array_of_numbers;
};