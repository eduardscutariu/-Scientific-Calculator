#ifndef NOD_H
#define NOD_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
#include "Token.h"

class Nod {
private:
    Token date;
    Nod* urmator;

public:
    Nod(Token date);

    Token obtineDate();
    Nod* obtineUrmator();
    void seteazaUrmator(Nod* urmator);

    Nod& operator++();
    Nod operator++(int);
};

#endif

