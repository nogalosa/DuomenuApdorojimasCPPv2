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
#include <deque>

struct studentas {
    std::string name, surname;
    int egz;
    std::vector<int> nd;
};

void checkInput();
std::deque<studentas> sortByNd(std::deque<studentas> users, bool chrono);
std::deque<studentas> sortByName(std::deque<studentas> users);
studentas getUserInfo();
void showResults(std::deque<studentas> users, bool median);
double getResult(studentas stud, bool median);
std::deque<studentas> regenerateResults(std::deque<studentas> users);
std::deque<studentas> generateStudentsAndLoad(std::deque<studentas> users, int amount);
std::deque<studentas> loadStudents(std::deque<studentas> users);
std::deque<studentas> generationMenu(std::deque<studentas> users);

#endif //DUOMENUAPDOROJIMASCPP_MAIN_H
