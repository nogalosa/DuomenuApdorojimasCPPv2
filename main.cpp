#include <iostream>
#include <iomanip>
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
    stud.egz = egz;

    std::cout << "Ivedimas baigtas" << std::endl << std::endl;

    return stud;
}

void showResults(std::vector<studentas> users) {
    int longestName = 0, longestSurname = 0;
    for (int i = 0; i < users.size(); i++) {
        if(users[i].name.size() > longestName)
            longestName = users[i].name.size();
        if(users[i].surname.size() > longestSurname)
            longestSurname = users[i].surname.size();
    }
    if(longestSurname < 7)
        longestSurname = 7;
    if(longestName < 6)
        longestName = 6;
    std::cout << "Pavarde" << std::string(longestSurname - 6, ' ') << "Vardas" << std::string(longestName - 5, ' ');
    std::cout << "Galutinis (Vid.)" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    double galutinis = 0;
    int suma = 0;
    for(int i = 0; i < users.size(); i++){
        suma = 0;
        std::cout << users[i].surname << std::string(longestSurname - users[i].surname.size() + 1, ' ') << users[i].name << std::string(longestName - users[i].name.size() + 1, ' ');
        for(int j = 0; j < users[i].nd.size(); j++){
            suma += users[i].nd[j];
        }
        galutinis = ((double)suma / (double)users[i].nd.size()) * 0.4 + 0.6 * (double) users[i].egz;
        std::cout << std::setprecision(2) << std::fixed << galutinis;
//        std::cout << suma << " < " << users[i].nd.size() << " < " << users[i].egz << " < " << galutinis;
        std::cout << std::endl;
    }

}

int main() {
    std::vector<studentas> users;
    int selection = 1;
    while(selection == 1){
        std::cout << "Ivesta " << users.size() << " stud. Pasirinkite:" << std::endl;
        std::cout << "1. Ivesti nauja studenta;" << std::endl;
        std::cout << "2. Suskaiciuoti galutinius balus;" << std::endl;
        std::cin >> selection;
        switch(selection) {
            case 1:
                users.push_back(getUserInfo());
                break;
            case 2:
                showResults(users);
                break;
            default:
                std::cout << "Ivestas neteisingas pasirinkimas" << std::endl << std::endl;
                selection = 1;
                break;
        }
    }


    return 0;
}