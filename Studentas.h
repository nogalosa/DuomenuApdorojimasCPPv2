//
// Created by Nerijus on 2019-04-23.
//

#ifndef DUOMENUAPDOROJIMASCPP_STUDENTAS_H
#define DUOMENUAPDOROJIMASCPP_STUDENTAS_H

#include <iostream>
#include <vector>

class Studentas {
private:
    std::string name, surname;
    int egz;
    std::vector<int> nd;
public:
    Studentas() : egz(0), name(""), surname("") { }
    Studentas(std::string name, std::string surname, int egz, std::vector<int> nd);
    inline std::string getName() const { return name; }
    inline std::string getSurname() const { return surname; }
    inline int getEgz() const { return egz; }
    inline std::vector<int> getNd() const { return nd; }
    inline void setName(std::string name) { Studentas::name = name; }
    inline void setSurname(std::string surname) { Studentas::surname = surname; }
    inline void setEgz(int egz) { Studentas::egz = egz; }
    inline void addNd(int ndn) { nd.push_back(ndn); }
    inline void setNd(int index, int ndn) { nd[index] = ndn; }
};

#endif //DUOMENUAPDOROJIMASCPP_STUDENTAS_H
