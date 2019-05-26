//
// Created by Nerijus on 2019-02-21.
//

#ifndef DUOMENUAPDOROJIMASCPP_MAIN_H
#define DUOMENUAPDOROJIMASCPP_MAIN_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include "NVector.h"
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <random>
#include "RandInt.h"
#include "Studentas.h"

void checkInput();
NVector<Studentas> sortByNd(NVector<Studentas> users, bool chrono);
NVector<Studentas> sortByName(NVector<Studentas> users);
Studentas getUserInfo();
void showResults(NVector<Studentas> users, bool median);
double getResult(Studentas stud, bool median);
NVector<Studentas> regenerateResults(NVector<Studentas> users);
NVector<Studentas> raskMinkstus(NVector<Studentas>& studentai);
NVector<Studentas> iterpkKietus(NVector<Studentas>& studentai);
NVector<Studentas> generateStudentsAndLoad(NVector<Studentas> users, int amount);
NVector<Studentas> loadStudents(NVector<Studentas> users);
NVector<Studentas> generationMenu(NVector<Studentas> users);

#endif //DUOMENUAPDOROJIMASCPP_MAIN_H
