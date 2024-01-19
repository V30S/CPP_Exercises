#ifndef PERSON
#define PERSON
#include <string>

class Person
{
public:
    Person(std::string _first_name, std::string _surname);

    std::string get_first_name();

    std::string get_surname();

private:
    std::string first_name;
    std::string surname;
};
#endif