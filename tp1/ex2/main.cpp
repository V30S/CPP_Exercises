#include <iomanip>
#include <iostream>
#include "Person.hpp"

int main(int argc, char const *argv[])
{
    Person person{"La Faluche", "Palluche"};

    std::cout << "Prenom : " << person.get_surname() << "\nNom : " << person.get_first_name() << std::endl;

    return 0;
}
