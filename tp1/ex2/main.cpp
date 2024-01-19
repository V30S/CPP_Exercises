#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Person.hpp"

int main(int argc, char const *argv[])
{
    int nb_person;

    std::cout << "Nombre de personnes: ";

    std::cin >> nb_person;

    std::vector<Person> person_tab;

    for (int i = 0; i < nb_person; i++)
    {
        std::string first_name;
        std::string surname;

        std::cout << "Prenom: ";

        std::cin >> surname;

        std::cout << "Nom: ";

        std::cin >> first_name;

        person_tab.push_back(Person{first_name, surname});
    }

    std::cout << "Les personnes sont ";

    for (int i = 0; i < nb_person; i++)
    {
        if (i == nb_person - 1)
        {
            std::cout << person_tab[i].get_first_name() << " " << person_tab[i].get_surname() << ".";
        }
        else
        {
            std::cout << person_tab[i].get_first_name() << " " << person_tab[i].get_surname() << ", ";
        }
    }

    std::cout << std::endl;

    return 0;
}
