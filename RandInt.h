//
// Created by Nerijus on 2019-03-24.
//

#ifndef DUOMENUAPDOROJIMASCPP_RANDINT_H
#define DUOMENUAPDOROJIMASCPP_RANDINT_H

#include <iostream>
#include <random>

class RandInt {
public:
    RandInt(int low, int high) : mt{rd()}, dist{low, high} { }
    int operator()() { return dist(mt); } // generuok int'ą
private:
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<int> dist;
};


#endif //DUOMENUAPDOROJIMASCPP_RANDINT_H
