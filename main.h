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

std::vector<studentas> sortByNd(std::vector<studentas> users);
std::vector<studentas> sortByName(std::vector<studentas> users);
studentas getUserInfo();
void showResults(std::vector<studentas> users, bool median);
std::vector<studentas> regenerateResults(std::vector<studentas> users);
std::vector<studentas> loadStudents(std::vector<studentas> users);

#endif //DUOMENUAPDOROJIMASCPP_MAIN_H
