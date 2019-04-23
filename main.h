//
// Created by Nerijus on 2019-02-21.
//

#ifndef DUOMENUAPDOROJIMASCPP_MAIN_H
#define DUOMENUAPDOROJIMASCPP_MAIN_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <random>
#include "RandInt.h"
#include "Studentas.h"

void checkInput();
std::vector<Studentas> sortByNd(std::vector<Studentas> users, bool chrono);
std::vector<Studentas> sortByName(std::vector<Studentas> users);
Studentas getUserInfo();
void showResults(std::vector<Studentas> users, bool median);
double getResult(Studentas stud, bool median);
std::vector<Studentas> regenerateResults(std::vector<Studentas> users);
std::vector<Studentas> raskMinkstus(std::vector<Studentas>& studentai);
std::vector<Studentas> iterpkKietus(std::vector<Studentas>& studentai);
std::vector<Studentas> generateStudentsAndLoad(std::vector<Studentas> users, int amount);
std::vector<Studentas> loadStudents(std::vector<Studentas> users);
std::vector<Studentas> generationMenu(std::vector<Studentas> users);

#endif //DUOMENUAPDOROJIMASCPP_MAIN_H
