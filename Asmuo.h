//
// Created by Nerijus on 2019-05-13.
//

#ifndef DUOMENUAPDOROJIMASCPP_ASMUO_H
#define DUOMENUAPDOROJIMASCPP_ASMUO_H

#include <string>

class Asmuo {
protected:
    std::string name;
    std::string surname;

public:
    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }
    void setName(std::string name) { Asmuo::name = name; }
    void setSurname(std::string surname) { Asmuo::surname = surname; }
    virtual int getEgz() const = 0;
};

#endif //DUOMENUAPDOROJIMASCPP_ASMUO_H
