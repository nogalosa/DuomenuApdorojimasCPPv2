#include <iostream>
#include <string>
#include <cassert>
#include <vector>

struct studentas {
    std::string name, surname;
    int n, egz;
    std::vector<int> nd;
};

studentas getUserInfo() {
    studentas stud;
    std::string name,surname;
    int n, egz;

    std::cout << "Iveskite varda: ";
    std::cin >> name;
    std::cout << std::endl << "Iveskite pavarde: ";
    std::cin >> surname;
    std::cout << std::endl << "Iveskite atliktu namu darbu skaiciu: ";
    std::cin >> n;

    stud.name = name;
    stud.surname = surname;
    stud.n = n;

    std::cout << std::endl << "Iveskite namu darbu rezultatus:" << std::endl;

    int tempn;

    for(int i = 0; i < n; i++){
        std::cin >> tempn;
        stud.nd.push_back(tempn);
        std::cout << std::endl;
    }

    std::cout << "Iveskite egzamino rezultata: ";
    std::cin >> egz;

    std::cout << "Ivedimas baigtas" << std::endl << std::endl;

    return stud;
}

int main() {

    std::vector<studentas> users;
    int selection = 1;
    while(selection == 1){
        std::cout << "Ivesta " << users.size() << " stud. Pasirinkite:" << std::endl;
        std::cout << "1. Ivesti nauja studenta;" << std::endl;
        std::cout << "2. Suskaiciuoti galutinius balus;" << std::endl;
        std::cin >> selection;
        if(selection == 1){
            users.push_back(getUserInfo());
        }
        if(selection != 1 && selection != 2){
            std::cout << "Ivestas neteisingas pasirinkimas" << std::endl << std::endl;
            selection = 1;
        }
    }


    return 0;
}