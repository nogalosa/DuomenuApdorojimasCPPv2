#include "main.h"

/**
 * Check cin for bad input
 */
void checkInput(){
    if(!std::cin.good()){
        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');
    }
}

/**
 * Sort users by their nd param.
 *
 * @param users User list you want to sort.
 * @param chrono True if you want to do benchmarking.
 * @return Sorted list.
 */
NVector<Studentas> sortByNd(NVector<Studentas> users, bool chrono) {
    auto start = std::chrono::system_clock::now();
    int i, j, k;
    for (auto user : users)
        for (j = 0; j < user.getNd().size()-1; j++)
            for (k = 0; k < user.getNd().size()-j-1; k++)
                if (user.getNd()[k] > user.getNd()[k+1])
                    std::swap(user.getNd()[k],user.getNd()[k+1]);
    if(chrono) {
        auto end = std::chrono::system_clock::now();
        auto elapsed = end - start;
        std::cout << "# Rusiavimas uztruko: " << (double)elapsed.count()/10000000 << "s." << std::endl;
    }
    return users;
}
/**
 * Sort users by their name.
 *
 * @param users User list you want to sort.
 * @return Sorted list.
 */
NVector<Studentas> sortByName(NVector<Studentas> users) {
    std::sort(users.begin(), users.end(), [](const Studentas &a1, const Studentas &a2 ){
        return a1.getName().compare(a2.getName()) < 0;
    });
//    users.sort([](Studentas const a, Studentas const  b) {return a.name.compare(b.name) < 0;});
    return users;
}

/**
 * Function for gathering information about new Student using live console input.
 *
 * @return Generated Student.
 */
Studentas getUserInfo() {
    Studentas stud;
    std::string name,surname;
    int egz;

    std::cout << "Iveskite varda: ";
    std::cin >> name;
    std::cout << std::endl << "Iveskite pavarde: ";
    std::cin >> surname;

    stud.setName(name);
    stud.setSurname(surname);

    std::cout << std::endl << "Iveskite namu darbu rezultatus (iveskite 0 noredami nutraukti pildyma):" << std::endl;

    int tempn = 1;

    while(tempn != 0){
        std::cin >> tempn;
        checkInput();
        if(tempn > 0 && tempn < 11)
            stud.addNd(tempn);
        else if(tempn > 10 || tempn < 0)
            std::cout << std::endl << "Ivesta neteisinga reiksme. Galite testi rezultatu pildyma arba iveskite 0, jei norite baigti.";
        std::cout << std::endl;
    }
    if(stud.getNd().size() == 0){
        std::cout << "Neivesta jokia namu darbu reiksme. Ivedama nustatyta reiksme: 1" << std::endl;
        stud.getNd().push_back(1);
    }

    std::cout << "Iveskite egzamino rezultata: ";
    std::cin >> egz;
    checkInput();
    while(egz < 1 || egz > 10){
        std::cout << std::endl << "Ivesta neteisinga reiksme. Iveskite egzamino rezultata: ";
        std::cin >> egz;
        checkInput();
    }
    stud.setEgz(egz);

    std::cout << "Ivedimas baigtas" << std::endl << std::endl;

    return stud;
}


/**
 * Calculate and print users' results to console.
 *
 * @param users Users to calculate and print.
 * @param median To use Median or Mathematic average method for counting their average result.
 */
void showResults(NVector<Studentas> users, bool median) {
    int longestName = 0, longestSurname = 0;
    for (auto user : users) {
        if(user.getName().size() > longestName)
            longestName = user.getName().size();
        if(user.getSurname().size() > longestSurname)
            longestSurname = user.getSurname().size();
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
    users = sortByNd(users, true);
    auto start = std::chrono::system_clock::now();
    for(auto user : users){
        suma = 0;
        std::cout << user.getSurname() << std::string(longestSurname - user.getSurname().size() + 1, ' ') << user.getName() << std::string(longestName - user.getName().size() + 1, ' ');

        if(median) {
            if(users.size() % 2 == 0){
                imedian = (double)(user.getNd()[user.getNd().size()/2] + user.getNd()[user.getNd().size()/2-1])/2;
            } else {
                imedian = floor((double)user.getNd()[user.getNd().size()/2]);
            }
            galutinis = imedian * 0.4 + 0.6 * (double) user.getEgz();
        } else {
            for(int j = 0; j < user.getNd().size(); j++){
                suma += user.getNd()[j];
            }
            galutinis = ((double) suma / (double) user.getNd().size()) * 0.4 + 0.6 * (double) user.getEgz();
        }

        std::cout << std::setprecision(2) << std::fixed << galutinis;
//        std::cout << suma << " < " << user.getNd().size() << " < " << user.egz << " < " << galutinis;
        std::cout << std::endl;
    }
    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
    std::cout << "# Spausdinimas uztruko: " << (double)elapsed.count()/10000000 << "s." << std::endl;
}

/**
 * Get result for one student.
 *
 * @param stud Student to calculate.
 * @param median To use Median or Mathematic average method for counting their average result.
 * @return Result.
 */
double getResult(Studentas stud, bool median){
    NVector<Studentas> users;
    users.push_back(stud);
    double imedian, galutinis,suma = 0;
    if(median) {
        users = sortByNd(users, false);
        if(users.size() % 2 == 0){
            imedian = (double)(users.front().getNd()[users.front().getNd().size()/2] + users.front().getNd()[users.front().getNd().size()/2-1])/2;
        } else {
            imedian = floor((double)users.front().getNd()[users.front().getNd().size()/2]);
        }
        galutinis = imedian * 0.4 + 0.6 * (double) users.front().getEgz();
    } else {
        for(int j = 0; j < users.front().getNd().size(); j++){
            suma += users.front().getNd()[j];
        }
        galutinis = (suma / (double) users.front().getNd().size()) * 0.4 + 0.6 * (double) users.front().getEgz();
    }
    return galutinis;
}

/**
 * To randomize nd param values.
 *
 * @param users Students list.
 * @return Regenerated Students list.
 */
NVector<Studentas> regenerateResults(NVector<Studentas> users) {
    auto start = std::chrono::system_clock::now();
    RandInt rnd {0, 9};
    for(auto user : users){
        for(int j = 0; j < user.getNd().size(); j++) {
            user.setNd(j, rnd() + 1);
        }
    }
    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
    std::cout << "# Regeneracija uztruko: " << (double)elapsed.count()/10000000 << "s." << std::endl;
    return users;
}

/**
 * minkštus studentus nukopijuoja į naują vektorių ir ištrina iš seno
 */
NVector<Studentas> raskMinkstus(NVector<Studentas>& studentai) {
    auto start = std::chrono::system_clock::now();

    NVector<Studentas> minksti;
    NVector<Studentas>::size_type i = 0;
    // invariantas: vektoriaus `studentai` elementai [0, i) yra "kieti"
    while (i != studentai.size()) {
        if (getResult(studentai[i],false) < 5) {
            minksti.push_back(studentai[i]);
            studentai.erase(studentai.begin() + i);  // ištrinti i-ąjį stud.
        } else
            ++i;  // pereiti prie kito studento
    }

    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
    std::cout << "raskMinkstus(): " << (double)elapsed.count()/10000000 << "s." << std::endl;

    return minksti;  // grąžina studentus gavusius skolą
}

NVector<Studentas> iterpkKietus(NVector<Studentas>& studentai) {
    auto start = std::chrono::system_clock::now();

    NVector<Studentas>::size_type count = 0;
    NVector<Studentas>::size_type i = 0;
    while (i != studentai.size()) {
        if (getResult(studentai[i],false) < 5) {
            studentai.insert(studentai.begin(),studentai[i]);
            i++;
            count++;
        } else
            ++i;  // pereiti prie kito studento
    }
    studentai.resize(count);
    studentai.shrink_to_fit();

    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
    std::cout << "iterpkKietus(): " << (double)elapsed.count()/10000000 << "s." << std::endl;

    return studentai;
}

/**
 * Main automatic students generation function which requires some userr input for selecting a generating strategy
 *
 * @param users Users vector (can be empty one)
 * @param amount How many Students to generate
 * @return users vector with added new generated Students.
 */
NVector<Studentas> generateStudentsAndLoad(NVector<Studentas> users, int amount) {
    int strategy = 0;
    std::cout << "Pasirinkite strategija (1-4):\n1. Pirma strategija\n2. Antra strategija\n3. Optimizuota strategija.\n4. Papildomos uzduoties strategija\n";
    std::cin >> strategy;
    checkInput();
    if(strategy == 2){
        std::cout << "Pasirinkta antra strategija" << std::endl;
    }else if(strategy == 3){
        std::cout << "Pasirinkta trecia strategija" << std::endl;
    }else if(strategy == 4){
        std::cout << "Pasirinkta ketvirta strategija" << std::endl;
    }else {
        std::cout << "Pasirinkta pirma strategija" << std::endl;
    }


    auto start = std::chrono::system_clock::now();
    RandInt rnd {0, 9};

    NVector<Studentas> nuskriaustukai;
    NVector<Studentas> galvociai;

    std::ofstream osless("nuskriaustukai.txt");
    std::ofstream osmore("galvociai.txt");

    osless << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde";
    for(int i = 0; i < 10; i++)
        osless << "NS" << (i+1) << "   ";
    osless << "Egzaminas" << std::endl;
    osmore << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde";
    for(int i = 0; i < 10; i++)
        osmore << "NS" << (i+1) << "   ";
    osmore << "Egzaminas" << std::endl;

    for(int i = 0; i < amount; i++){
        Studentas stud;
        stud.setName("Vardas" + std::to_string(i));
        stud.setSurname("Pavarde" + std::to_string(i));
        for(int j = 0; j < 10; j++) {
            stud.addNd(rnd() + 1);
        }
        stud.setEgz(rnd() + 1);
        if(strategy != 2)
            users.push_back(stud);
        if(getResult(stud,false) >= 5){
            osmore << std::left << std::setw(15) << stud.getName() << std::left << std::setw(15) << stud.getSurname();
            for(int j = 0; j < stud.getNd().size(); j++){
                osmore << std::left << std::setw(6) << stud.getNd()[j];
            }
            osmore << " " << stud.getEgz() << std::endl;
            if(strategy == 2){
                users.push_back(stud);
            } else if(strategy == 1) {
                galvociai.push_back(stud);
            }
        }else {
            osless << std::left << std::setw(15) << stud.getName() << std::left << std::setw(15) << stud.getSurname();
            for(int j = 0; j < stud.getNd().size(); j++){
                osless << std::left << std::setw(6) << stud.getNd()[j];
            }
            osless << " " << stud.getEgz() << std::endl;
            if(strategy == 1 || strategy == 2)
                nuskriaustukai.push_back(stud);
        }
    }

    if(strategy == 3) {
        remove_copy_if(users.begin(), users.end(),
                       nuskriaustukai.back_inserter(nuskriaustukai), [](const Studentas &a1){
                    return getResult(a1,false) >= 5;
                });
        users.erase(std::remove_if(users.begin(), users.end(), [](const Studentas &a1){
                        return getResult(a1,false) < 5;
                    }), users.end());
    }

    if(strategy == 4) {
        nuskriaustukai = raskMinkstus(users);
        users = iterpkKietus(users);
    }

    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
    std::cout << "# Generacija uztruko: " << (double)elapsed.count()/10000000 << "s." << std::endl;

    return users;
}

/**
 * Load students from kursiokai.txt
 *
 * @param users Users vector
 * @return Updated users vector with inserted values from the file.
 */
NVector<Studentas> loadStudents(NVector<Studentas> users) {
    try {
        std::ifstream inf("kursiokai.txt");

        if (inf.fail() || inf.bad() || !inf.is_open()) {
            throw std::runtime_error("Can not load file.");
        }

        bool start = true;
        std::string entry, entry2;
        int tempegz;
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
                Studentas stud;
                stud.setSurname(entry);
                inf >> entry2;
                stud.setName(entry2);
                for(int i = 0; i < ndcount; i++){
                    inf >> tempnd;
                    if(tempnd < 1 || tempnd > 10){
                        tempnd = 1;
                        std::cout << "Rasta bloga namu darbu reiksme. Ji pakeista i 1." << std::endl;
                    }
                    stud.addNd(tempnd);
                }
                inf >> tempegz;
                if(tempegz < 1 || tempegz > 10){
                    stud.setEgz(1);
                    std::cout << "Rasta bloga egzamino reiksme. Ji pakeista i 1." << std::endl;
                }
                stud.setEgz(tempegz);
                users.push_back(stud);
            }
        }
    } catch (std::exception& e) {
        std::cout << "Klaida ikeliant failus is kursiokai.txt. Galbut failas neegzistuoja?";
    }

    return users;
}

/**
 * A pre-function for generateStudentAndLoad() function for selecting how many Students the user wants to generate.
 *
 * @param users Users vector
 * @return users vector with added new generated Students.
 */
NVector<Studentas> generationMenu(NVector<Studentas> users){
    int selection = 0;
    while(selection == 0){
        std::cout << "Pasirinkite, kiek studentu norite sugeneruoti:" << std::endl;
        std::cout << "1. 10 studentu" << std::endl;
        std::cout << "2. 100 studentu" << std::endl;
        std::cout << "3. 1000 studentu" << std::endl;
        std::cout << "4. 10 000 studentu" << std::endl;
        std::cout << "5. 100 000 studentu" << std::endl;
        std::cout << "6. Atsaukti" << std::endl;
        std::cin >> selection;
        checkInput();

        if(selection >= 1 && selection <= 5){
            auto gen = 10;
            switch (selection){
                case 2:
                    gen = 100;
                    break;
                case 3:
                    gen = 1000;
                    break;
                case 4:
                    gen = 10000;
                    break;
                case 5:
                    gen = 100000;
                    break;
            }
            users = generateStudentsAndLoad(users, gen);
            return users;
        }else if(selection == 6){
            return users;
        } else {
            std::cout << "Ivestas neteisingas pasirinkimas. Pabandykite vel." << std::endl;
            selection = 0;
        }
    }
}

int main() {

//    std::random_device rd;
//    std::mt19937 mt(rd());
//    std::uniform_int_distribution<int> dist(0, 99);
//    for(int i = 0; i < 16, i++){
//        std::cout << dist(mt) << " ";
//    }
//    std::cout << dist(mt) << " ";

    NVector<Studentas> users;
    int selection = 1;
    while(selection == 1){
        std::cout << "Ivesta " << users.size() << " stud. (Cap: " << users.capacity() << ") Pasirinkite:" << std::endl;
        std::cout << "1. Ivesti nauja studenta;" << std::endl;
        std::cout << "2. Suskaiciuoti galutinius balus (su vidurkiu);" << std::endl;
        std::cout << "3. Suskaiciuoti galutinius balus (su mediana);" << std::endl;
        std::cout << "4. Pergeneruoti visu ivestu studentu namu darbu balus i atsitiktinius;" << std::endl;
        std::cout << "5. Ivesti studentu informacija is kursiokai.txt failo;" << std::endl;
        std::cout << "6. Sugeneruoti tam tikra skaiciu studentu, juos ikelti i programa ir isaugoti failuose;" << std::endl;
        std::cin >> selection;
        checkInput();


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
            case 6:
                users = generationMenu(users);
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