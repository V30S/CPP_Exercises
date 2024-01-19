#include <iomanip>
#include <iostream>
#include "Person.hpp"

int main(int argc, char const *argv[])
{
    Person person;

    person.surname = "Palluche";
    person.first_name = "La Faluche";

    std::cout << "Prenom : " << person.surname << "\nNom : " << person.first_name << std::endl;

    return 0;
}
