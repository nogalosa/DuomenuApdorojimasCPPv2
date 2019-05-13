//
// Created by Nerijus on 2019-04-23.
//

#ifndef DUOMENUAPDOROJIMASCPP_STUDENTAS_H
#define DUOMENUAPDOROJIMASCPP_STUDENTAS_H

#include <iostream>
#include <vector>
#include "Asmuo.h"

class Studentas : public Asmuo {
private:
    int egz;
    std::vector<int> nd;

public:

    Studentas() : egz(0) { Asmuo::name = ""; Asmuo::surname = ""; }
    Studentas(std::string n, std::string s, int egz, std::vector<int> nd) : egz(egz) { name = n;
        surname = s;}
    ~Studentas(){}
    Studentas (const Studentas& x) : egz(x.getEgz()) {
        name = x.getName();
        surname = x.getSurname();
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
