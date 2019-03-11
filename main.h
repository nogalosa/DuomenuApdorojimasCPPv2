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
#include <list>

struct studentas {
    std::string name, surname;
    int egz;
    std::vector<int> nd;
};

void checkInput();
std::list<studentas> sortByNd(std::list<studentas> users, bool chrono);
std::list<studentas> sortByName(std::list<studentas> users);
studentas getUserInfo();
void showResults(std::list<studentas> users, bool median);
double getResult(studentas stud, bool median);
std::list<studentas> regenerateResults(std::list<studentas> users);
std::list<studentas> generateStudentsAndLoad(std::list<studentas> users, int amount);
std::list<studentas> loadStudents(std::list<studentas> users);
std::list<studentas> generationMenu(std::list<studentas> users);

#endif //DUOMENUAPDOROJIMASCPP_MAIN_H
