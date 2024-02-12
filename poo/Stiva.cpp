#include "Stiva.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;
Stiva::Stiva() {
    varf = NULL;
}

void Stiva::adauga(Token date) {
    Nod* nodNou = new Nod(date);
    nodNou->seteazaUrmator(varf);
    varf = nodNou;
}

Token Stiva::scoate() {
    if (varf != NULL) {
        Token date = varf->obtineDate();
        Nod* temp = varf;
        varf = varf->obtineUrmator();
        delete temp;
        return date;
    }
    else {
        throw "Stiva este goala";
    }
}

Token Stiva::vede() {
    if (varf != NULL) {
        return varf->obtineDate();
    }
    else {
        throw "Stiva este goala";
    }
}

bool Stiva::esteGoala() {
    return varf == NULL;
}
