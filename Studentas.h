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
    Studentas(std::string name, std::string surname, int egz, std::vector<int> nd) : name(name), surname(surname), egz(egz) { }
    ~Studentas(){}
    Studentas (const Studentas& x) : name(x.getName()), surname(x.getSurname()), egz(x.getEgz()) {
        nd.reserve(x.getNd().size());
        for(int nds : x.getNd()) {
            nd.push_back(nds);
        }
    }

    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }
    int getEgz() const { return egz; }
    std::vector<int> getNd() const { return nd; }
    void setName(std::string name) { Studentas::name = name; }
    void setSurname(std::string surname) { Studentas::surname = surname; }
    void setEgz(int egz) { Studentas::egz = egz; }
    void addNd(int ndn) { nd.push_back(ndn); }
    void setNd(int index, int ndn) { nd[index] = ndn; }

    Studentas& Studentas::operator=(const Studentas& x) {
        if(&x == this) return *this;

        name = x.getName();
        surname = x.getSurname();
        egz = x.getEgz();
        nd.clear();
        nd.shrink_to_fit();
        nd.reserve(x.getNd().size());
        for(int nds : x.getNd()) {
            nd.push_back(nds);
        }
        return *this;
    }
};

#endif //DUOMENUAPDOROJIMASCPP_STUDENTAS_H
