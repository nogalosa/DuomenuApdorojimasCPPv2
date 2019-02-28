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

struct studentas {
    std::string name, surname;
    int egz;
    std::vector<int> nd;
};

void checkInput();
std::vector<studentas> sortByNd(std::vector<studentas> users);
std::vector<studentas> sortByName(std::vector<studentas> users);
studentas getUserInfo();
void showResults(std::vector<studentas> users, bool median);
double getResult(studentas stud, bool median);
std::vector<studentas> regenerateResults(std::vector<studentas> users);
std::vector<studentas> generateStudentsAndLoad(std::vector<studentas> users, int amount);
std::vector<studentas> loadStudents(std::vector<studentas> users);
std::vector<studentas> generationMenu(std::vector<studentas> users);

#endif //DUOMENUAPDOROJIMASCPP_MAIN_H
