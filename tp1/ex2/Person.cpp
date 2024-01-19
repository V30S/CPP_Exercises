#include <string>

class Person
{
public:
    Person(std::string _first_name, std::string _surname)
        : first_name{_first_name}, surname{_surname}
    {
    }

    std::string get_first_name()
    {
        return first_name;
    }

    std::string get_surname()
    {
        return surname;
    }

private:
    std::string first_name;
    std::string surname;
};