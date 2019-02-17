#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <algorithm>

struct studentas {
    std::string name, surname;
    int egz;
    std::vector<int> nd;
};

std::vector<studentas> sortByNd(std::vector<studentas> users) {
    int i, j, k;
    for (i = 0; i < users.size(); i++)
        for (j = 0; j < users[i].nd.size()-1; j++)
            for (k = 0; k < users[i].nd.size()-j-1; k++)
                if (users[i].nd[k] > users[i].nd[k+1])
                    std::swap(users[i].nd[k],users[i].nd[k+1]);
    return users;
}
std::vector<studentas> sortByName(std::vector<studentas> users) {
    std::sort(std::begin(users), std::end(users), [](const studentas &a1, const studentas &a2 ){
        return a1.name.compare(a2.name) < 0;
    });
    return users;
}

studentas getUserInfo() {
    studentas stud;
    std::string name,surname;
    int egz;

    std::cout << "Iveskite varda: ";
    std::cin >> name;
    std::cout << std::endl << "Iveskite pavarde: ";
    std::cin >> surname;

    stud.name = name;
    stud.surname = surname;

    std::cout << std::endl << "Iveskite namu darbu rezultatus (iveskite 0 noredami nutraukti pildyma):" << std::endl;

    int tempn = 1;

    while(tempn != 0){
        std::cin >> tempn;
        if(tempn > 0 && tempn < 11)
            stud.nd.push_back(tempn);
        else if(tempn > 10 || tempn < 0)
            std::cout << std::endl << "Ivesta neteisinga reiksme. Galite testi rezultatu pildyma arba iveskite 0, jei norite baigti.";
        std::cout << std::endl;
    }

    std::cout << "Iveskite egzamino rezultata: ";
    std::cin >> egz;
    stud.egz = egz;

    std::cout << "Ivedimas baigtas" << std::endl << std::endl;

    return stud;
}

void showResults(std::vector<studentas> users, bool median) {
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
    double galutinis = 0,imedian = 0;
    int suma = 0 ;
    for(int i = 0; i < users.size(); i++){
        suma = 0;
        std::cout << users[i].surname << std::string(longestSurname - users[i].surname.size() + 1, ' ') << users[i].name << std::string(longestName - users[i].name.size() + 1, ' ');

        if(median) {
            users = sortByNd(users);
            if(users.size() % 2 == 0){
                imedian = (double)(users[i].nd[users[i].nd.size()/2] + users[i].nd[users[i].nd.size()/2-1])/2;
            } else {
                imedian = floor((double)users[i].nd[users[i].nd.size()/2]);
            }
            galutinis = imedian * 0.4 + 0.6 * (double) users[i].egz;
        } else {
            for(int j = 0; j < users[i].nd.size(); j++){
                suma += users[i].nd[j];
            }
            galutinis = ((double) suma / (double) users[i].nd.size()) * 0.4 + 0.6 * (double) users[i].egz;
        }

        std::cout << std::setprecision(2) << std::fixed << galutinis;
//        std::cout << suma << " < " << users[i].nd.size() << " < " << users[i].egz << " < " << galutinis;
        std::cout << std::endl;
    }

}

std::vector<studentas> regenerateResults(std::vector<studentas> users) {
    srand(time(NULL));
    for(int i = 0; i < users.size(); i++){
        for(int j = 0; j < users[i].nd.size(); j++) {
            users[i].nd[j] = 1 + (rand() % 10);
        }
    }
    return users;
}

std::vector<studentas> loadStudents(std::vector<studentas> users) {
    std::ifstream inf("kursiokai.txt");

    bool start = true;
    std::string entry;
    int ndcount = 0, tempnd = 0;
    while(inf >> entry) {
        if (start) {
            if (entry.find("ND") == 0) {
                ndcount++;
            }
            if (entry == "Egzaminas") {
                start = false;
            }
        } else {
            studentas stud;
            stud.surname = entry;
            inf >> stud.name;
            for(int i = 0; i < ndcount; i++){
                inf >> tempnd;
                stud.nd.push_back(tempnd);
            }
            inf >> stud.egz;
            users.push_back(stud);
        }
    }

    return users;
}

int main() {
    std::vector<studentas> users;
    int selection = 1;
    while(selection == 1){
        std::cout << "Ivesta " << users.size() << " stud. Pasirinkite:" << std::endl;
        std::cout << "1. Ivesti nauja studenta;" << std::endl;
        std::cout << "2. Suskaiciuoti galutinius balus (su vidurkiu);" << std::endl;
        std::cout << "3. Suskaiciuoti galutinius balus (su mediana);" << std::endl;
        std::cout << "4. Pergeneruoti visu ivestu studentu namu darbu balus i atsitiktinius;" << std::endl;
        std::cout << "5. Ivesti studentu informacija is kursiokai.txt failo;" << std::endl;
        std::cin >> selection;
        switch(selection) {
            case 1:
                users.push_back(getUserInfo());
                break;
            case 2:
                showResults(sortByName(users),false);
                break;
            case 3:
                showResults(sortByName(users),true);
                break;
            case 4:
                users = regenerateResults(users);
                selection = 1;
                break;
            case 5:
                users = loadStudents(users);
                selection = 1;
                break;
            default:
                std::cout << "Ivestas neteisingas pasirinkimas" << std::endl << std::endl;
                selection = 1;
                break;
        }
    }


    return 0;
}